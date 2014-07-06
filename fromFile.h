/* 
 * File:   fromFile.h
 * Author: y2l1
 *
 * Created on July 4, 2014, 2:33 PM
 */

#ifndef FROMFILE_H
#define	FROMFILE_H
 #include "garage.h" 
 tGarage* fromFile_importTGarage(tGarage*, unsigned int*);
 tGarage* fromFile_importTMaterial(tGarage*, unsigned int);
 tMechanic* fromFile_importTMechanic(tMechanic*, unsigned int*);
#endif	/* FROMFILE_H */

