/* 
 * File:   garageStruct.h
 * Author: y2l1
 *
 * Created on July 5, 2014, 2:39 PM
 */

#ifndef GARAGESTRUCT_H
 #define	GARAGESTRUCT_H
 #include "speciality.h"
 #include "mechanicStruct.h"
   typedef enum hangar {
    NORTH = 0,
    SOUTH = 1,
    EAST = 2,
    WEST = 3
 } enumHangar;

 typedef struct {
    short unsigned int number;
    short unsigned int floor;
    float area;
    bool enable;
    enumHangar hangarLocation;
    enumSpeciality speciality;
    tMaterial *material;
    tMechanic *mechanic;
    unsigned int numMaterial;
    unsigned int nrOfMechanics;
 }tGarage;

#endif	/* GARAGESTRUCT_H */

