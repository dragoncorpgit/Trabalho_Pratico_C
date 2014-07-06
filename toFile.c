#include "toFile.h"

void toFile_exportTGarage(tGarage* garage, unsigned int nGarage)
{
 FILE *fileGarage;
 int i;
 if(garage!=NULL)
 {
  fileGarage=fopen("garage.txt","w");
  if(fileGarage!=NULL)
  {
   fprintf(fileGarage,"%u\n",nGarage);
   for(i=0;i<nGarage;i++)
   {
    fprintf(fileGarage,"%hu\n",garage[i].number);
    fprintf(fileGarage,"%hu\n",garage[i].hangarLocation);
    fprintf(fileGarage,"%hu\n",garage[i].speciality);
    fprintf(fileGarage,"%hu\n",garage[i].floor);
    fprintf(fileGarage,"%hu\n",garage[i].enable);
    fprintf(fileGarage,"%f\n",garage[i].area);
    fprintf(fileGarage,"%u\n",garage[i].numMaterial);
   }
   fclose(fileGarage);
   toFile_exportTMaterial(garage, nGarage);
  }
  else
  {
   printf("Erro ao escrever no ficheiro");
  }
 }
 else
 {
  printf("Erro sem dados para guardar");
 }
}

void toFile_exportTMaterial(tGarage* garage, unsigned int nGarage)
{
 int i;
 int j;
 FILE *fileMaterial;
 fileMaterial=fopen("material.txt","w");
 if(fileMaterial!=NULL)
 {
  for(i=0;i<nGarage;i++)
  {
   fprintf(fileMaterial, "%hu\n", garage[i].number);
   for(j=0;j<garage[i].numMaterial;j++)
   {
    fprintf(fileMaterial,"%s\n", garage[i].material[j].denomination);
    fprintf(fileMaterial,"%s\n",garage[i].material[j].nSerie);
    fprintf(fileMaterial,"%hu\n",garage[i].material[j].acquisitionDate.day);
    fprintf(fileMaterial,"%hu\n",garage[i].material[j].acquisitionDate.month);
    fprintf(fileMaterial,"%hu\n",garage[i].material[j].acquisitionDate.year);
    fprintf(fileMaterial,"%f\n",garage[i].material[j].price);
   }
  }
  fclose(fileMaterial);
 }
 else
 {
  printf("Erro ao escrever no ficheiro");
 }
}

void toFile_exportTMaterial(tMechanic* garage, unsigned int nMachanic)
{
 
}