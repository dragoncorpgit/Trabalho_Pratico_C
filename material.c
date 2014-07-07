#include "material.h"

char* material_inputDenomination()
{
 char *denomination=NULL;
 do
 {
  printf("Descrição: ");
  scanf("%ms", &denomination);
  ClearBuffer();
 }while(denomination==NULL);
 denomination=string_removeNewLineFromPointer(denomination);
 return (char*)denomination;
}

void material_inputNSerie(char nSerie[])
{
 do
 {
  printf("\nNúmero de serie: ");
  fgets(nSerie,12,stdin);
  if(!(string_lentgh(nSerie)<11))
  {
   ClearBuffer();
  }
 }while(nSerie==NULL);
 string_removeNewLineFromArray(nSerie);
}

Date material_inputAcquisitionDate()
{
 Date newDate;
 short unsigned int day;
 short unsigned int month;
 short unsigned int year;
 do
 {
  printf("\nIntruduza a data da aquisição do produto!\n");
  do
  {
   printf("\nDia (ex. 02): ");
   scanf("%hu",&day);
   ClearBuffer();
  }while(day<1||day>32);
  do
  {
   printf("\nMês (ex. 02): ");
   scanf("%hu",&month);
   ClearBuffer();
  }while(month<1||month>12);
  do
  {
   printf("\nAno (ex. 2014): ");
   scanf("%hu",&year);
   ClearBuffer();
  }while(year<0);
  fillDate(&newDate,day, month, year);
  
 }while(!isCorrectDate(newDate));
 return newDate;
}

float material_inputPrice()
{
 float price;
 do
 {
  printf("\nPreço: ");
  scanf("%f", &price);
  ClearBuffer();
 }while(price<0);
 return price;
}

tMaterial material_fillMaterial()
{
 tMaterial newMaterial;
 newMaterial.denomination=NULL;
 newMaterial.denomination=material_inputDenomination();
 material_inputNSerie(newMaterial.nSerie);
 newMaterial.price=material_inputPrice();
 newMaterial.acquisitionDate=material_inputAcquisitionDate();
 return newMaterial;
}

tMaterial *material_add(tMaterial *material, unsigned int *numMaterial,tMaterial elementToAdd, bool isToOrder)
{
 material=(tMaterial*)realloc(material, (sizeof(tMaterial)*(*numMaterial+1)));
 if(material!=NULL)
 {
  material[*numMaterial]=elementToAdd;
  (*numMaterial)++;
 }
 if(isToOrder)
 {
  material_sort(material, *numMaterial);
 }
 return (tMaterial*)material;
}

unsigned int *material_addID(unsigned int *fID, unsigned int numMaterial,unsigned int elementToAdd)
{
 fID=(unsigned int*)realloc(fID, (sizeof(unsigned int)*(numMaterial)));
 if(fID!=NULL)
 {
  fID[numMaterial]=elementToAdd;
 }
 return (unsigned int*)fID;
}

tMaterial *material_replace(tMaterial *material, unsigned int numMaterial)
{
 int index;
 tMaterial elementToEdit;
 int choice=0;
 do
 {
  printf("\n1 - Número Serie");
  printf("\n2 - Descrição");
  printf("\n3 - Preço");
  printf("\n4 - Data");
  printf("\n-1 - Sair\n");
  scanf("%i",&choice);
  ClearBuffer();
 }while(choice==0);
 if(choice!=-1)
 {
  index=material_searchMaterial(material, numMaterial,NULL);
 
  if(index!=-1 && (index<numMaterial && index > -1))
  {
   elementToEdit=material[index];
   switch(choice)
   {
    case 1: material_inputNSerie(elementToEdit.nSerie);
          break;
    case 2: elementToEdit.denomination=material_inputDenomination();
          break;
    case 3: elementToEdit.price=material_inputPrice();
          break;
    case 4: elementToEdit.acquisitionDate=material_inputAcquisitionDate();
          break;
    default:
           break;
   }
   material[index]=elementToEdit;
   material_sort(material, numMaterial);
  }
 }
 return (tMaterial*)material;
}

tMaterial *material_remove(tMaterial *material, unsigned int *numMaterial)
{
 int position=material_searchMaterial(material, *numMaterial,NULL);
 char removeConf;
 bool toRemove=false;
 if(position!=-1)
 {
  material_outputSearch(material[position],(unsigned int)position);
  printf("\nDeseja mesmo remover a entrada?\n(Y)es | (N)o\n");
  scanf("%c", &removeConf);
  removeConf = tolower(removeConf);

  if(removeConf=='y')
  {
   toRemove=true;
  }
  if(toRemove)
  {
   int i;
   int length;
   tMaterial toRemove;
   for(i=position;i<(*numMaterial);i++)
   {
    if(i==position)
    {
     length=sizeof(material[position]);
     toRemove=(material)[position];
    }
    else
    {
     if((i+1)<(*numMaterial))
     {
      (material)[i]=(material)[i+1];
     }
     else
     {
      (material)[i]=toRemove;
      free(material[i].denomination);
     }
    }
   }
   
   (*numMaterial)--;
   
   if (numMaterial ==0){
   free(material);
   material = NULL;
   return material;
   }else {
   return (tMaterial*)realloc(material, (sizeof(material)-length));
   }
  }
  else
  {
   return (tMaterial*)material;
  }
 }
 else
 {
  return (tMaterial*)material;
 }
}

int material_searchMaterial(tMaterial *material, unsigned int numMaterial,unsigned int *fID)
{
 int i=-1;
 tMaterial *fMaterial=NULL;
 unsigned int fundMaterial=0;
 unsigned int* fundID=NULL;
 char* str=NULL;
 char* denToFind=NULL;
 bool byDenomination=true;
 
 if(fID!=NULL)
 {
  printf("\n\nID: -1 (para re-procurar por descricao): ");
  scanf("%i",&i);
  ClearBuffer();
  if(i!=-1)
  {
   byDenomination=false;
   fundMaterial=i;
  }
  else
  {
   do
   {
    printf("\nDescrição a procurar: ");
    scanf("%ms",&denToFind);
   }while(denToFind==NULL);
   denToFind=string_removeNewLineFromPointer(denToFind);
  }
 }
 else
 {
  do
  {
   printf("\nDescrição a procurar: ");
   scanf("%ms",&denToFind);
  }while(denToFind==NULL);
  denToFind=string_removeNewLineFromPointer(denToFind);
 }
 
 if(byDenomination)
 {
  for(i=0;i<numMaterial;i++)
  {
   str=strstr((material[i].denomination),denToFind);
   if(str!=NULL)
   {
    if(fID==NULL)
    {
     fMaterial=(tMaterial*)material_add(fMaterial, &fundMaterial, material[i], false);
     fundID=(unsigned int*)material_addID(fundID,fundMaterial-1,i);
    }
    else
    {
     fMaterial=(tMaterial*)material_add(fMaterial, &fundMaterial, material[fID[i]], false);
     fundID=(unsigned int*)material_addID(fundID,fundMaterial-1,fID[i]);
    }
   }
  }
  
  if(fundMaterial!=0)
  {
   if(fundMaterial!=1)
   {
    for(i=0;i<fundMaterial;i++)
    {
     material_outputSearch(fMaterial[i],fundID[i]);
    }
    return material_searchMaterial(fMaterial, fundMaterial, fundID);
   }
   else
   {
    fundMaterial=(fundID)[0];
    free(fMaterial);
    free(fundID);
    return fundMaterial;
   }
  }
  else
  {
   printf("Não existem procuras com a descrição inserida");
   return -1;
  }
 }
 else
 {
  return fundMaterial;
 }
}

void material_outputSearch(tMaterial material, unsigned int id)
{
 printf("\nID: %u\nSerial Number: %s\nDenomination: %s\nPrice: %f",id,material.nSerie,material.denomination, material.price);
}

void material_sort(tMaterial* material, unsigned int numMaterial)
{
 bool haTroca=true;
 int i;
 int j=-1;
 int nMaterial=(int)numMaterial;
 tMaterial exchange;
 while((j<(nMaterial) && haTroca))
 {
  j++;
  if((nMaterial-j-1)>0)
  {
   haTroca=false;
   for(i=0;i<(nMaterial-j-1);i++)
   {
    if((i+1)<nMaterial)
    {
     if(strcmp(material[i].denomination,material[i+1].denomination)>0)
     {
      exchange=(material)[i];
      (material)[i]=(material)[i+1];
      (material)[i+1]=exchange;
      haTroca=true;
     }
    }
   }
  }
 }
}

void material_listAll(tMaterial* material, unsigned int nMaterial)
{
 int i;
 for(i=0;i<nMaterial;i++)
 {
  material_outputSearch(material[i], i);
 }
}

tMaterial *material_menu(tMaterial* material, unsigned int* nMaterial)
{
 short unsigned int choice=0;
 int index=-1;
 do
 {
  printf("\n1 - Listar todos os materiais");
  printf("\n2 - Procurar todos os materiais");
  printf("\n3 - Adicionar novo material");
  printf("\n4 - Modificar material");
  printf("\n5 - Remover material");
  printf("\n0 - Menu anterior");
  printf("\nQuero: ");
  scanf("%hu",&choice);
  ClearBuffer();
  switch(choice)
  {
   case 1:system(CLEAR_CMD); 
          material_listAll(material,*nMaterial);
    break;
   case 2:system(CLEAR_CMD); 
          index=material_searchMaterial(material, *nMaterial,NULL);
          if(index!=-1)
          {
           material_outputSearch(material[index],index);
          }
    break;
   case 3:system(CLEAR_CMD); 
          material=material_add(material, nMaterial, material_fillMaterial(), true);
    break;
   case 4:system(CLEAR_CMD); 
          material=material_replace(material, *nMaterial);
    break;
   case 5:system(CLEAR_CMD); 
          material=material_remove(material, nMaterial);
    break;
   default: system(CLEAR_CMD);
    break;
  }
 }while(choice!=0);
 return (tMaterial*)material;
}