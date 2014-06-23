#include "material.h"

char *material_inputDenomination()
{
 char *denomination=NULL;
 do
 {
  printf("Descrição: ");
  denomination=(char*)fgets(denomination,750,stdin);
 }while(denomination!=NULL);
 return denomination;
}

char *material_inputNSerie()
{
 char nSerie[12];
 do
 {
  printf("\nNúmero de serie: ");
  nSerie=fgets(nSerie,11,stdin);
 }while(nSerie!=NULL);
 return nSerie;
}

Date material_inputAcquisitionDate()
{
 Date newDate;
 unsigned short int day;
 unsigned short int month;
 unsigned short int year;
 do
 {
  printf("\nIntruduza a data da aquisição do produto!\n");
  do
  {
   printf("\nDia (ex. 02): ");
   scanf("%hu",&day);
  }while(day<1||day>32);
  
  do
  {
   printf("\nMês (ex. 02): ");
   scanf("%hu",&month);
  }while(month<1||month>12);
  
  do
  {
   printf("\nAno (ex. 2014): ");
   scanf("%hu",&year);
  }while(year<0);
  
  newDate=fillDate(day, month, year);
  
 }while(isCorrectDate(newDate));
 return newDate;
}

float material_inputPrice()
{
 float price;
 printf("\nPreço: ");
 scanf("%f", &price);
 while(price<0)
 {
  printf("\nPreco menor que 0");
  printf("\nPreço: ");
  scanf("%f", &price);
 }
 return price;
}

tMaterial material_fillMaterial()
{
 tMaterial newMaterial;
 
 newMaterial.denomination=material_inputDenomination();
 newMaterial.acquisitionDate=material_inputAcquisitionDate();
 strcpy(newMaterial.nSerie,material_inputNSerie());
 newMaterial.price=material_inputPrice();
 return newMaterial;
}

tMaterial *material_add(tMaterial *material, unsigned int *numMaterial,tMaterial elementToAdd, bool isToOrder)
{
 material=(tMaterial*)realloc(material, (sizeof(material)+sizeof(elementToAdd)));
 if(material!=NULL)
 {
  (*material)[*numMaterial]=elementToAdd;
  (*numMaterial)++;
 }
 if(isToOrder)
 {
  material_sort(material, numMaterial);
 }
 return material;
}

unsigned int *material_addID(unsigned int *fID, unsigned int numMaterial,unsigned int elementToAdd)
{
 fID=(int*)realloc(fID, (sizeof(unsigned int)*(numMaterial)));
 if(fID!=NULL)
 {
  (*fID)[numMaterial]=elementToAdd;
 }
 return fID;
}

tMaterial *material_replace(tMaterial *material, tMaterial elementToEdit, unsigned int numMaterial ,unsigned int index)
{
 (*material)[index]=elementToEdit;
 material_sort(material, numMaterial);
 return material;
}

tMaterial *material_remove(tMaterial *material, unsigned int *numMaterial)
{
 unsigned int position;
 int i;
 int length;
 tMaterial toRemove;
 for(i=position;i<(*numMaterial);i++)
 {
  if(i==position)
  {
   length=sizeof((*material)[position]);
   toRemove=(*material)[position];
  }
  else
  {
   if((i+1)<(*numMaterial))
   {
    (*material)[i]=(*material)[i+1];
   }
   else
   {
    (*material)[i]=toRemove;
    free((*material)[i].denomination);
   }
  }
 }
 (*numMaterial)++;
 return (tMaterial*)realloc(material, (sizeof(*material)-length));
}

int material_searchMaterial(tMaterial *material, int numMaterial,unsigned int *fID)
{
 int i;
 tMaterial *fMaterial=NULL;
 unsigned int fundMaterial=0;
 char* str=NULL;
 char *denToFind;
 
 
 
 for(i=0;i<numMaterial;i++)
 {
  str=strstr((*(*material)[i].denomination),denToFind);
  if(str!=NULL)
  {
   fMaterial=(tMaterial*)material_add(fMaterial, &fundMaterial, (*material)[i], false);
   fID=(unsigned int*)material_addID(fID,fundMaterial-1,i);
  }
 }
 
 if(fundMaterial==1)
 {
  return material_searchMaterial(fMaterial, fundMaterial, fID);
 }
 else
 {
  fundMaterial=(*fID)[0];
  free(fMaterial);
  free(fID);
  free(str);
  return fundMaterial;
 }
}

/*int material_outputSearch(tMaterial *material, int nMat)
{
 int i;
 bool z=false;
 int input=-1;
 for(i=0;i<nMat;i++)
 {
  printf("ID Procura: %i\nSerial Number: %s\nDenomination: %s\nPrice: %f\n__________________________",i,(*material)[i].nSerie,(*(*material)[i].denomination, (*material)[i].price));
 }
 if(nMat>0)
 {
  printf("ID Procura: %i \nDescrição: Procurar sobre esta procura\n___________________________", -2);
 }
 printf("Insira um valor fora de %i a %i para ir para o menu principal", -2, nMat);
 do
 {
  input=-1;
  if(z)
  {
   printf("Não existe nenhum material associado ao número intruduzido!");
  }
  else
  {
   if(input==-1)
   {
    z=true;
   }
  }
  printf("Intruduza um ID de procura apresentados na lista");
  scanf("%i",&input);
 }while(input>nMat&&input<0);
 
 if(input>0&&input<nMat)
 {
  ///////
  printf("Serial Number: %s\nDenomination: %s\nPrice: %f\n__________________________",(*material)[input].nSerie,(*(*material)[input].denomination, (*material)[input].price));
 }
 else
 {
  if(input==-2)
  {
   material_searchMaterial(material, nMat, );
  }
 }
}*/

void material_sort(tMaterial* material, unsigned int numMaterial)
{
 bool haTroca=true;
 int i;
 int j=-1;
 tMaterial exchange;
 while(j<(numMaterial) && haTroca==true)
 {
  haTroca=false;
  j++;
  for(i=0;i<(numMaterial-j-1);i++)
  {
   if(strcmp((*(*material)[i].denomination),(*(*material)[i+1].denomination))>0)
   {
    exchange=(*material)[i];
    (*material)[i]=(*material)[i+1];
    (*material)[i+1]=exchange;
    haTroca=true;
   }
  }
 }
}