#ifndef ADDITIONALFUNCTIONS_H
#define	ADDITIONALFUNCTIONS_H
 #include <stdio.h>
 #include <stdlib.h>

 #ifdef __unix__
  #define CLEAR_CMD "clear"
 #else
  #define CLEAR_CMD "cls"
 #endif

 char* string_removeNewLineFromPointer(char*);
 int string_lentgh(char*);
 void string_removeNewLineFromArray(char[]);
 void ClearBuffer();
#endif	/* ADDITIONALFUNCTIONS_H */

