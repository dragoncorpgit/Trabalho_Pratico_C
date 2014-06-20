#include "material.h"

bool material_setDenomination(char newDenomination[], char* denomination)
{
 int denominationLenght=strlen(newDenomination);
 if(denominationLenght!=-1 && denominationLenght>-1)
 {
  denomination=(char*)realloc(denomination, denominationLenght*sizeof(char));
  if(denomination!=NULL)
  {
   strcpy((*denomination),newDenomination);
   return true;
  }
  else
  {
   return false;
  }
 }
 else
 {
  return false;
 }
 newDenomination=NULL;
}

void material_setNSerie(char newNSerie[12], char nSerie[12])
{
 strcpy((nSerie),newNSerie);
}

bool material_setAcquisitionDate(Date newDate, Date* date)
{
 (*date)=newDate;
 if(isCorrectDate(*date))
 {
  return true;
 }
 else
 {
  return false;
 }
}

tMaterial material_fillMaterial(char denomination[], char nSerie[12], Date acquisitionDate, float price)
{
 tMaterial newMaterial;
 (newMaterial).denomination=NULL;
 if(material_setDenomination(denomination, (newMaterial).denomination))
 {
  if(material_setAcquisitionDate(acquisitionDate, &(newMaterial).acquisitionDate))
  {
   (newMaterial).price=price;
   material_setNSerie(nSerie, &(newMaterial).nSerie);
  }
 }
 return newMaterial;
}

void *material_add(tMaterial *material, unsigned int numMaterial,tMaterial elementToAdd)
{
 material=(tMaterial*)realloc(material, (sizeof(material)+sizeof(elementToAdd)));
 if(material!=NULL)
 {
  (*material)[*numMaterial]=elementToAdd;
  (*numMaterial)++;
 }
 return material;
}

void *material_replace(tMaterial *material, tMaterial elementToEdit, unsigned int numMaterial ,unsigned int index)
{
 (*material)[index]=elementToEdit;
 material_sort(material, numMaterial);
 return material;
}

void *material_remove(tMaterial *material, unsigned int position, unsigned int *numMaterial)
{
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

void material_searchMaterial(tMaterial *material, int numMaterial, char *denToFind)
{
 int i;
 char *str;
 tMaterial *fundMaterial=NULL;
 unsigned int nMatFund=0;
 for(i=0;i<numMaterial;i++)
 {
  str=strstr((*(*material)[i].denomination),(*denToFind));
  if(str!=NULL)
  {
   fundMaterial=realloc(sizeof(fundMaterial)+sizeof((*material)[i]));
   (*fundMaterial)[nMatFund]=(*material)[i];
   nMatFund++;
  }
 }
 material_outputSearch(fundMaterial, nMatFund);
}

void material_outputSearch(tMaterial *material, int nMat)
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
   printf("Não existe nenhum material assiciado ao número intruduzido!");
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
}

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