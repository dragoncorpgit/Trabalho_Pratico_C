#include "functions.h"

int getStringLenght(char string[])
{
 int stringLength=-1;
 int i;
 for(i=0;string[i]!='\0';i++)
 {
  if(stringLength!=-1 && stringLength>-1)
  {
   stringLength++;
  }
  else
  {
   stringLength=0;
  }
 }
 return stringLength;
}

