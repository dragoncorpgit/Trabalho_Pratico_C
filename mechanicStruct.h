/* 
 * File:   mechanicStruct.h
 * Author: y2l1
 *
 * Created on July 5, 2014, 2:43 PM
 */

#ifndef MECHANICSTRUCT_H
#define	MECHANICSTRUCT_H
 #include "time.h"
 #include "material.h"
 typedef struct {
    short unsigned int nrOfGarage;
    time startWork;
    time finishWork;
 } tSchedule;

 typedef struct {
    char *name;
    unsigned int nr;
    enumSpeciality speciality;
    Date dateOfBirth;
    tSchedule *shift;
    short unsigned int nrOfShifts;
    //time startWorkHour;
    //time stopWorkHour;
 } tMechanic;
#endif	/* MECHANICSTRUCT_H */

