/* 
 * File:   material.h
 * Author: y2l1
 *
 * Created on June 10, 2014, 6:40 PM
 */

#ifndef MATERIAL_H
#define	MATERIAL_H
typedef struct
{
 char *denomination;
 float price;
 char nSerie[12];
 Date acquisitionDate;
}tMaterial;



#endif	/* MATERIAL_H */