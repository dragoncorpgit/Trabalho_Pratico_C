#include "additionalFunctions.h"

int string_lentgh(char* str)
{
 int i=0;
 while(str[i]!='\0')
 {
  i++;
 }
 return i;
}

char *string_removeNewLineFromPointer(char* str)
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

void string_removeNewLineFromArray(char str[])
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

void ClearBuffer() 
{
 int c;
 while((c = getchar()) != '\n' && c != EOF);
}