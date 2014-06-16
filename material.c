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

void material_setPrice(float newPrice, float* price)
{
 (*price)=newPrice;
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

void material_fillMaterial(tMaterial *newMaterial, char denomination[], char nSerie[12], Date acquisitionDate, float price)
{
 (*newMaterial).denomination=NULL;
 if(material_setDenomination(denomination, (*newMaterial).denomination))
 {
  if(material_setAcquisitionDate(acquisitionDate, &(*newMaterial).acquisitionDate))
  {
   material_setPrice(price, &(*newMaterial).price);
   material_setNSerie(nSerie, &(*newMaterial).nSerie);
  }
 }
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

void *material_replace(tMaterial *material, tMaterial elementToEdit)
{
 
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

void *material_searchMaterial(tMaterial material)
{
 
}

void material_binarySearch(tMaterial *material, int numMaterial, char *denToFind)
{
 unsigned int low=0;
 unsigned int high=numMaterial;
 unsigned short int middle;
 bool finded=false;
 while(low<=high && finded==false)
 {
  middle=(low+high)/2;
  strlen(*denToFind);
  if(strcmp((*(*material)[middle].denomination),(*denToFind))==0)
  {
   finded=true;
  }
  else
  {
   if(strcmp((*(*material)[middle].denomination),(*denToFind))>0)
   {
    low=middle;
   }
   else
   {
    high=middle;
   }
  }
 }
}

void material_bubbleSort(tMaterial* material, int numMaterial)
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