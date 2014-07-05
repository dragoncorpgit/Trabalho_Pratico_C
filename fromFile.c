#include "fromFile.h"

tGarage* fromFile_importTGarage(tGarage* garage, unsigned int* nGarage)
{
 FILE *fileGarage;
 int i;
 /*if(garage!=NULL)
 {
  garage=NULL;
 }*/
 if((*nGarage)!=0)
 {
  (*nGarage)=0;
 }
 fileGarage=fopen("garage.txt","r");
 if(fileGarage!=NULL)
 {
  if(feof(fileGarage)==0)
  {
   fscanf(fileGarage,"%u",nGarage);
   for(i=0;i<(*nGarage);i++)
   {
    fscanf(fileGarage,"%hu",&garage[i].number);
    fscanf(fileGarage,"%hu",&garage[i].hangarLocation);
    fscanf(fileGarage,"%hu",&garage[i].speciality);
    fscanf(fileGarage,"%hu",&garage[i].floor);
    fscanf(fileGarage,"%hu",&garage[i].enable);
    fscanf(fileGarage,"%f",&garage[i].area);
    fscanf(fileGarage,"%u",&garage[i].numMaterial);
   }
   fclose(fileGarage);
   garage=fromFile_importTMaterial(garage,*nGarage);
  }
 }
 else
 {
  printf("O ficheiro oficinas não existe não existe");
 }
 return garage;
}

tGarage* fromFile_importTMaterial(tGarage* garage, unsigned int nGarage)
{
 int i;
 int j;
 short int garageIndex;
 short int garageNumber;
 FILE *fileMaterial;
 fileMaterial=fopen("material.txt","r");
 if(fileMaterial!=NULL)
 {
  for(i=0;i<nGarage;i++)
  {
   garageIndex=-1;
   garageNumber=-1;
   fscanf(fileMaterial, "%hi",&garageNumber);
   garageIndex=SearchForNumber(garage,nGarage,garageNumber);
   if(garageIndex>-1)
   {
    if(garage[garageIndex].material!=NULL)
    {
     garage[garageIndex].material=NULL;
    }
    garage[garageIndex].material=(tMaterial*)realloc(garage[garageIndex].material,(garage[garageIndex].numMaterial)*sizeof(tMaterial));
    if(garage[garageIndex].material!=NULL)
    {
     for(j=0;j<garage[garageIndex].numMaterial;j++)
     {
      fscanf(fileMaterial,"%ms",&garage[garageIndex].material[j].denomination);
      fscanf(fileMaterial,"%s",&garage[garageIndex].material[j].nSerie);
      fscanf(fileMaterial,"%hu",&garage[garageIndex].material[j].acquisitionDate.day);
      fscanf(fileMaterial,"%hu",&garage[garageIndex].material[j].acquisitionDate.month);
      fscanf(fileMaterial,"%hu",&garage[garageIndex].material[j].acquisitionDate.year);
      fscanf(fileMaterial,"%f",&garage[garageIndex].material[j].price);
     }
    }
    else
    {
     printf("Memória insuficiente para os materiais da oficina número %hi",garageNumber);
    }
   }
   else
   {
    printf("1");
   }
  }
  fclose(fileMaterial);
 }
 else
 {
  printf("O ficheiro materiais não existe");
 }
 return garage;
}

void importTMechanic()
{
 
}