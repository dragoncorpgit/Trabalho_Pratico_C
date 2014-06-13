#include "material.h"

bool material_setDenomination(char newDenomination[], char* denomination)
{
 int denominationLenght=strlen(newDenomination);
 if(denominationLenght!=-1 && denominationLenght>-1)
 {
  denomination=realloc(denomination, strlen(newDenomination)*sizeof(char));
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
 strcpy(nSerie,newNSerie);
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

void *material_fillMaterial(tMaterial *newMaterial, char denomination[], char nSerie[12], Date acquisitionDate, float price)
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
 return newMaterial;
}

void *material_add(tMaterial *material, tMaterial elementToAdd)
{
 material=realloc(material, (sizeof(material)+sizeof(elementToAdd)));
 if(material!=NULL)
 {
  (*material)[(*material).numMaterial]=elementToAdd;
  (*material).numMaterial++;
 }
 return material;
}

void *material_replace(tMaterial *material, tMaterial elementToEdit)
{
 
}

void *material_remove(tMaterial *material, char nSerie[12])
{
 
}

void *material_findMaterial(tMaterial material)
{
 
}