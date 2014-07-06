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

void toFile_exportTMechanic(tMechanic* mechanic, unsigned int nMechanic)
{
 int i;
 int j;
 FILE *file;
 file=NULL;
 if(mechanic!=NULL)
 {
  file=fopen("mechanic.txt","w");
  if(file!=NULL)
  {
   fprintf(file,"%u\n",nMechanic);
   for(i=0;i<nMechanic;i++)
   {
    fprintf(file,"%u\n",mechanic[i].nr);
    fprintf(file,"%s\n",mechanic[i].name);
    fprintf(file,"%hu\n",mechanic[i].speciality);
    fprintf(file,"%hu\n",mechanic[i].dateOfBirth.day);
    fprintf(file,"%hu\n",mechanic[i].dateOfBirth.month);
    fprintf(file,"%hu\n",mechanic[i].dateOfBirth.year);
    fprintf(file,"%hu\n",mechanic[i].nrOfShifts);
    for(j=0;j<mechanic[i].nrOfShifts;j++)
    {
     fprintf(file,"%hu\n",mechanic[i].shift[j].nrOfGarage);
     fprintf(file,"%hu\n",mechanic[i].shift[j].startWork.hour);
     fprintf(file,"%hu\n",mechanic[i].shift[j].startWork.minute);
     fprintf(file,"%hu\n",mechanic[i].shift[j].startWork.second);
     fprintf(file,"%hu\n",mechanic[i].shift[j].finishWork.hour);
     fprintf(file,"%hu\n",mechanic[i].shift[j].finishWork.minute);
     fprintf(file,"%hu\n",mechanic[i].shift[j].finishWork.second);
    }
   }
  }
  else
  {
   printf("Erro nao escrever no ficheiro");
  }
 }
 else
 {
  printf("Não existem mecanicos para serem gravados");
 }
}