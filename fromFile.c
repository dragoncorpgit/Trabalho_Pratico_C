#include "fromFile.h"

tGarage* fromFile_importTGarage(tGarage* garage,  short unsigned int* nGarage)
{
 FILE *fileGarage;
 int i;
 garage=NULL;
 (*nGarage)=0;
 fileGarage=fopen("oficinas.txt","r");
 if(fileGarage!=NULL)
 {
  if(feof(fileGarage)==0)
  {
   fscanf(fileGarage,"%hu",nGarage);
   garage = (tGarage*) realloc(garage, sizeof(tGarage) * *nGarage); 
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
  printf("\nO ficheiro oficinas.txt nao existe");
 }
 return garage;
}

tGarage* fromFile_importTMaterial(tGarage* garage, short unsigned int nGarage)
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
      if (garage[i].material != NULL){
   garageIndex=-1;
    garageNumber=-1;
    fscanf(fileMaterial, "%hi", &garageNumber);
    garageIndex=SearchForNumber(garage, nGarage, garageNumber);
    if(garageIndex>-1)
    {
     if(garage[garageIndex].material!=NULL)
     {
      garage[garageIndex].material=NULL;
     }
     garage[garageIndex].material=(tMaterial*) realloc(garage[garageIndex].material, (garage[garageIndex].numMaterial)*sizeof(tMaterial));
     for(j=0; j<garage[garageIndex].numMaterial; j++)
     {
      fscanf(fileMaterial, "%ms", &garage[garageIndex].material[j].denomination);
      fscanf(fileMaterial, "%s", &garage[garageIndex].material[j].nSerie);
      fscanf(fileMaterial, "%hu", &garage[garageIndex].material[j].acquisitionDate.day);
      fscanf(fileMaterial, "%hu", &garage[garageIndex].material[j].acquisitionDate.month);
      fscanf(fileMaterial, "%hu", &garage[garageIndex].material[j].acquisitionDate.year);
      fscanf(fileMaterial, "%f", &garage[garageIndex].material[j].price);
     }
    }
    else
    {
     printf("\nMemória insuficiente para os materiais da oficina numero %hi",garageNumber);
    }
   }
   else
   {
    printf("Oficina %hi inválida", garageNumber);
   }
  }
  fclose(fileMaterial);
 }
 else
 {
  printf("\nO ficheiro material.txt não existe");
 }
 return garage;
}

tMechanic* fromFile_importTMechanic(tMechanic* mechanic, unsigned int* nMechanic)
{
 int i;
 int j;
 FILE *fileMechanic;
 fileMechanic=NULL;
 if(mechanic!=NULL)
 {
  mechanic=NULL;
 }
 (*nMechanic)=0;
 fileMechanic=fopen("mecanicos.txt","r");
 if(fileMechanic!=NULL)
 {
  fscanf(fileMechanic,"%u",nMechanic);
  mechanic=(tMechanic*)realloc(mechanic,(*nMechanic)*sizeof(tMechanic));
  if(mechanic!=NULL)
  {
   for(i=0;i<(*nMechanic);i++)
   {
    fscanf(fileMechanic,"%u",&mechanic[i].nr);
    fscanf(fileMechanic,"%ms",&mechanic[i].name);
    fscanf(fileMechanic,"%hu",&mechanic[i].speciality);
    fscanf(fileMechanic,"%hu",&mechanic[i].dateOfBirth.day);
    fscanf(fileMechanic,"%hu",&mechanic[i].dateOfBirth.month);
    fscanf(fileMechanic,"%hu",&mechanic[i].dateOfBirth.year);
    fscanf(fileMechanic,"%hu",&mechanic[i].nrOfShifts);
    if(mechanic[i].shift!=NULL)
    {
     mechanic[i].shift=NULL;
    }
    mechanic[i].shift=(tSchedule*)realloc(mechanic[i].shift,(mechanic[i].nrOfShifts)*sizeof(tMechanic));
    if(mechanic[i].shift!=NULL)
    {
     for(j=0;j<mechanic[i].nrOfShifts;j++)
     {
      fscanf(fileMechanic,"%hu",&mechanic[i].shift[j].nrOfGarage);
      fscanf(fileMechanic,"%hu",&mechanic[i].shift[j].startWork.hour);
      fscanf(fileMechanic,"%hu",&mechanic[i].shift[j].startWork.minute);
      fscanf(fileMechanic,"%hu",&mechanic[i].shift[j].startWork.second);
      fscanf(fileMechanic,"%hu",&mechanic[i].shift[j].finishWork.hour);
      fscanf(fileMechanic,"%hu",&mechanic[i].shift[j].finishWork.minute);
      fscanf(fileMechanic,"%hu",&mechanic[i].shift[j].finishWork.second);
     }
    }
    else
    {
     printf("\nErro memoria insuficiente para alocar turnos");
    }
   }
  }
 }
 else
 {
  printf("\nO ficheiro mecanicos.txt não existe");
 }
 return (tMechanic*)mechanic;
}