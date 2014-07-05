#include "garage.h"

int main(void) 
{
 tGarage* garage;
 unsigned int numGarage;
 char choice;
 bool z;
 garage=NULL;
 numGarage=0;
 choice=' ';
 
 tMaterial* material;
 unsigned int m;
 material=NULL;
 m=0;
 
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
    material_menu(material,&m);
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

/*void freeMemory(tGarage* garage, unsigned int* numGarage)
{
 //Free all garage pointers
 for((*numGarage)-=1;(*numGarage)>-1;(*numGarage)--)
 {
  freeMaterialMemory(garage[(*numGarage)].material,&garage[(*numGarage)].numMaterial);
 }
 //end
 //Free all mechanics pointers
 
 //end
}

void freeMaterialMemory(tMaterial* material, unsigned int* nMaterial)
{
 for((*nMaterial)-=1;(*nMaterial)>-1;(*nMaterial)--)
 {
  free(material[(*nMaterial)].denomination);
 }
 free(material);
}*/