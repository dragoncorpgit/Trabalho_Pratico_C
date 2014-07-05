#include "toFile.h"
#include "fromFile.h"

int main(void) 
{
 tGarage* garage;
 unsigned int numGarage;
 char choice;
 bool z;
 garage=NULL;
 numGarage=0;
 choice=' ';
 
 do
 {
  printf("\n(F)uncionários");
  printf("\n(M)ateriais");
  printf("\n(O)ficinas");
  printf("\n\n(S)air\n");
  scanf("%c", &choice);
  choice = tolower(choice);
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
 //freeMemory(garage, numGarage);
}

void freeMemory(tGarage* garage, unsigned int* numGarage)
{
 //Free all garage pointers
 for((*numGarage)-=1;(*numGarage)>-1;(*numGarage)--)
 {
  freeMaterialMemory(garage[(*numGarage)].material,&garage[(*numGarage)].numMaterial);
  freeMechanicMemory(garage[(*numGarage)].mechanic,&garage[(*numGarage)].nrOfMechanics);
 }
 free(garage);
 //end
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