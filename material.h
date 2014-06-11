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

 bool material_setDenomination(char[], char*);
 void material_setNSerie(char[], char[]);
 void material_setPrice(float, float*);
 bool material_setAcquisitionDate(Date, Date*);
 void *material_fillMaterial(tMaterial*, char[], char[], Date, float);
 

#endif	/* MATERIAL_H */