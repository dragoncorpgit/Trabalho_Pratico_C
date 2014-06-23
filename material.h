/* 
 * File:   material.h
 * Author: y2l1
 *
 * Created on June 10, 2014, 6:40 PM
 */

#ifndef MATERIAL_H
#define	MATERIAL_H
 #include "date.h"
 #include <stdbool.h>
 #include <string.h>

 typedef struct
 {
  char *denomination;
  float price;
  char nSerie[12];
  Date acquisitionDate;
 }tMaterial;

 unsigned int numMaterial=-1;
 
 tMaterial material_fillMaterial();
 tMaterial *material_add(tMaterial*, unsigned int*,tMaterial, bool);
 tMaterial *material_replace(tMaterial*, tMaterial, unsigned int);
 tMaterial *material_remove(tMaterial*, unsigned int*);
 int material_searchMaterial(tMaterial*, int,unsigned int);
 void material_outputSearch(tMaterial, unsigned int);

#endif	/* MATERIAL_H */