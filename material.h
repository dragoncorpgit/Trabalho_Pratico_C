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
 
 char *material_inputDenomination();
 char *material_inputNSerie();
 bool material_inputAcquisitionDate(Date*);
 float material_inputPrice();
 tMaterial material_fillMaterial();
 void *material_add(tMaterial*,unsigned int,tMaterial);
 

#endif	/* MATERIAL_H */