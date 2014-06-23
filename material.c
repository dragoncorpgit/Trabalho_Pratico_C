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

tMaterial *material_replace(tMaterial *material, tMaterial elementToEdit, unsigned int numMaterial)
{
 unsigned int index=material_searchMaterial(material, numMaterial,NULL);
 if(index!=-1)
 {
  (*material)[index]=elementToEdit;
  material_sort(material, numMaterial);
 }
 return material;
}

tMaterial *material_remove(tMaterial *material, unsigned int *numMaterial)
{
 unsigned int position=material_searchMaterial(material, numMaterial,NULL);
 if(position!=-1)
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
 else
 {
  return material;
 }
}

int material_searchMaterial(tMaterial *material, int numMaterial,unsigned int *fID)
{
 int i;
 tMaterial *fMaterial=NULL;
 unsigned int fundMaterial=0;
 char* str=NULL;
 char *denToFind;
 bool byDenomination=true;
 
 if(fID!=NULL)
 {
  printf("\nID (-1 para procurar por descricao): ");
  scanf("%i",&i);
 }
 if(i!=-1)
 {
  byDenomination=false;
  fundMaterial=i;
 }
 else
 {
  
 }
 printf("\nDescrição a procurar: ");
 scanf("%s",denToFind);
 while(denToFind!=NULL)
 {
  printf("Erro ao ler descricção!\nDescrição a procurar: ");
  scanf("%s",denToFind);
 }
 
 for(i=0;i<numMaterial;i++)
 {
  str=strstr((*(*material)[i].denomination),denToFind);
  if(str!=NULL)
  {
   fMaterial=(tMaterial*)material_add(fMaterial, &fundMaterial, (*material)[i], false);
   fID=(unsigned int*)material_addID(fID,fundMaterial-1,i);
  }
 }
  
 if(fundMaterial!=1 && byDenomination)
 {
  for(i=0;i<fundMaterial;i++)
  {
   material_outputSearch((*material)[i]);
  }
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

void material_outputSearch(tMaterial material, unsigned int id)
{
 printf("ID: %u\nSerial Number: %s\nDenomination: %s\nPrice: %f\n__________________________",id,material.nSerie,(*(material.denomination)), material.price);
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