#include "material.h"

bool setDenomination(char newDenomination[], char* denomination)
{
 int denominationLenght=strlen(newDenomination);
 if(denominationLenght!=-1 && denominationLenght>-1)
 {
  
  return true;
 }
 else
 {
  return false;
 }
}

void *addMaterial(tMaterial *newMaterial, char denomination[], char nSerie[12], Date acquisitionDate, float price)
{
 
}