#include "material.h"

char* material_inputDenomination()
{
 char input[500];
 char *denomination=NULL;
 do
 {
  //getchar();
  printf("Descrição: ");
  fgets(input,500,stdin);
 }while(input==NULL);
 while(denomination==NULL)
 {
  denomination=(char*)calloc(strlen(input),sizeof(char));
 }
 strcpy(denomination,input);
 denomination=material_removeNewLineFromPointer(denomination);
 return (char*)denomination;
}

char* material_inputNSerie()
{
 char nSerie[12];
 do
 {
  printf("\nNúmero de serie: ");
  fgets(nSerie,12,stdin);
 }while(nSerie==NULL);
 material_removeNewLineFromArray(nSerie);
 return nSerie;
}

Date material_inputAcquisitionDate()
{
 Date newDate;
 unsigned short int day;
 unsigned short int month;
 unsigned short int year;
 do
 {
  printf("\nIntruduza a data da aquisição do produto!\n");
  do
  {
   printf("\nDia (ex. 02): ");
   scanf("%hu",&day);
   getchar();
  }while(day<1||day>32);
  do
  {
   printf("\nMês (ex. 02): ");
   scanf("%hu",&month);
   getchar();
  }while(month<1||month>12);
  do
  {
   printf("\nAno (ex. 2014): ");
   scanf("%hu",&year);
   getchar();
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
  getchar();
 }while(price<0);
 return price;
}

tMaterial material_fillMaterial()
{
 tMaterial newMaterial;
 newMaterial.denomination=NULL;
 newMaterial.denomination=material_inputDenomination();
 strcpy(newMaterial.nSerie,material_inputNSerie());
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
  getchar();
 }while(choice==0);
 if(choice!=-1)
 {
  index=material_searchMaterial(material, numMaterial,NULL);
 
  if(index!=-1 && (index<numMaterial && index > -1))
  {
   elementToEdit=material[index];
   switch(choice)
   {
    case 1: strcpy(elementToEdit.nSerie,material_inputNSerie());
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
  scanf("%c",&removeConf);

  if(removeConf=='Y'||removeConf=='y')
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
      free((*material[i].denomination));
     }
    }
   } 
   (*numMaterial)--;
   return (tMaterial*)realloc(material, (sizeof(material)-length));
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
 char* str=NULL;
 char denToFind[500];
 bool byDenomination=true;
 
 if(fID!=NULL)
 {
  printf("\nID: -1(para re-procurar por descricao): ");
  scanf("%i",&i);
  getchar();
  if(i!=-1)
  {
   byDenomination=false;
   fundMaterial=i;
  }
 }
 else
 {
  printf("\nDescrição a procurar: ");
  fgets(denToFind,500,stdin);
  material_removeNewLineFromArray(denToFind);
 }
 
 for(i=0;i<numMaterial;i++)
 {
  str=strstr((material[i].denomination),denToFind);
  if(str!=NULL)
  {
   fMaterial=(tMaterial*)material_add(fMaterial, &fundMaterial, (material)[i], false);
   fID=(unsigned int*)material_addID(fID,fundMaterial-1,i);
  }
 }
  
 if(fundMaterial!=0)
 {
  if(fundMaterial!=1)
  {
   for(i=0;i<fundMaterial;i++)
   {
    material_outputSearch(material[i],fID[i]);
   }
   return material_searchMaterial(fMaterial, fundMaterial, fID);
  }
  else
  {
   fundMaterial=(fID)[0];
   free(fMaterial);
   free(fID);
   return fundMaterial;
  }
 }
 else
 {
  printf("Não existem procuras com a descrição inserida");
  return -1;
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
 unsigned short int choice=0;
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
  getchar();
  switch(choice)
  {
   case 1:system(CLEAR_CMD); 
          material_listAll(material,*nMaterial);
    break;
   case 2:system(CLEAR_CMD); 
          index=material_searchMaterial(material, *nMaterial,NULL);
          if(index!=-1)
          {
           material_outputSearch(material[index],0);
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

int string_lentgh(char* str)
{
 int i=0;
 while(str[i]!='\0')
 {
  i++;
 }
 return i;
}

char *material_removeNewLineFromPointer(char* str)
{
 int j;
 int length=string_lentgh(str);
 for(j=0;j<length;j++)
 {
  if(str[j]=='\n')
  {
   str[j]='\0';
  }
 }
 if(string_lentgh(str)!=length)
 {
  str=(char*)realloc(str,sizeof(char)*strlen(str));
 }
 return str;
}

void material_removeNewLineFromArray(char str[])
{
 int j;
 int length=string_lentgh(str);
 for(j=0;j<length;j++)
 {
  if(str[j]=='\n')
  {
   str[j]='\0';
  }
 }
}