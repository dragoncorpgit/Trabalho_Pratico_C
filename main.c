#include "toFile.h"
#include "fromFile.h"
void freeMemory(tGarage*, unsigned int*, tMechanic*, unsigned int*);
void freeMechanicMemory(tMechanic*, unsigned int*);
void freeMaterialMemory(tMaterial*, unsigned int*);

int main(void) 
{
 tGarage* garage;
 unsigned int numGarage;
 tMechanic* mechanic;
 unsigned int numMechanic;
 char choice;
 bool z;
 garage=NULL;
 numGarage=0;
 mechanic=NULL;
 numMechanic=0;
 choice=' ';
 
 do
 {
  printf("\n(F)uncionários");
  printf("\n(M)ateriais");
  printf("\n(O)ficinas");
  printf("\n\n(S)air\n");
  fscanf(stdin,"%c", &choice);
  choice = (choice);
  switch(choice)
  {
   
   case 'f':
       
    break; 
    
   case 'm'://Escolher oficina
    break;
   
   case 'o':
    break;
   default: if(choice!='s')
            {
             printf("Opção '%c' inválida", choice);
            }
    break;
  }
 }while(choice!='s');
 //freeMemory(garage, &numGarage, mechanic, &numMechanic);
}

void freeMemory(tGarage* garage, unsigned int* numGarage, tMechanic* mechanic, unsigned int* numMechanic)
{
 for((*numGarage)-=1;(*numGarage)>-1;(*numGarage)--)
 {
  freeMaterialMemory(garage[(*numGarage)].material,&garage[(*numGarage)].numMaterial);
 }
 free(garage);
 freeMechanicMemory(mechanic,numMechanic);
}

void freeMaterialMemory(tMaterial* material, unsigned int* nMaterial)
{
 for((*nMaterial)-=1;(*nMaterial)>-1;(*nMaterial)--)
 {
  free(material[(*nMaterial)].denomination);
 }
 free(material);
}

void freeMechanicMemory(tMechanic* mechanic, unsigned int* nMechanic)
{
 for((*nMechanic)-=1;(*nMechanic)>-1;(*nMechanic)--)
 {
  free(mechanic[(*nMechanic)].name);
  free(mechanic[(*nMechanic)].shift);
 }
 free(mechanic);
}