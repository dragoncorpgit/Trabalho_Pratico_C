/* 
 * File:   material.h
 * Author: y2l1
 *
 * Created on June 10, 2014, 6:40 PM
 */

#ifndef MATERIAL_H
#define	MATERIAL_H
 
 #include "date.h"
 #include "additionalFunctions.h"
 #include <stdbool.h>
 #include <string.h>
 #include <stdio.h>
 #include <stdlib.h>

 typedef struct
 {
  char *denomination;
  float price;
  char nSerie[12];
  Date acquisitionDate;
 }tMaterial;
 
 tMaterial *material_freeMemory(tMaterial*, unsigned int*);
 tMaterial *material_menu(tMaterial*, unsigned int*);
 tMaterial *material_add(tMaterial*, unsigned int*,tMaterial, bool);
 tMaterial *material_replace(tMaterial*, unsigned int);
 tMaterial *material_remove(tMaterial*, unsigned int*);
 unsigned int *material_addID(unsigned int*, unsigned int,unsigned int);
 char* material_inputDenomination();
 char* material_inputNSerie();
 Date material_inputAcquisitionDate();
 float material_inputPrice();
 tMaterial material_fillMaterial();
 int material_searchMaterial(tMaterial*, unsigned int,unsigned int*);
 void material_outputSearch(tMaterial, unsigned int);
 void material_listAll(tMaterial*, unsigned int);
 void material_sort(tMaterial*, unsigned int);
 
#endif	/* MATERIAL_H */