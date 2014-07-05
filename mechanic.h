/* 
 * File:   mechanic.h
 * Author: gaming
 *
 * Created on July 2, 2014, 12:19 PM
 */

#ifndef MECHANIC_H
#define	MECHANIC_H

#define MAX_SIZE_NAME 80

typedef struct {
    unsigned short int nrOfGarage;
    time startWork;
    time finishWork;

} tSchedule;

typedef struct {
    char *name;
    unsigned int nr;
    enumSpeciality speciality;
    Date dateOfBirth;
    tSchedule *shift;
    unsigned short int nrOfShifts;
    //time startWorkHour;
    //time stopWorkHour;
} tMechanic;

tMechanic *InsertMechanic(tMechanic *mechanic, unsigned int *currentNrOfMechanics, tGarage *garage, 
        unsigned short int currentNrOfGarages);
bool IsNrHiggerThanZero(unsigned short int inputNr);
bool IsShiftTimeValid(char shiftTime [9], unsigned short int *hour, unsigned short int *minute);
unsigned short int ConcateShiftTime(char firstDigit, char secondDigit);
bool IsShiftStartTimeAndEndTimeValid (time startShiftTime, time endShiftTime);
bool ShiftIsAvaiable(tMechanic *mechanic, unsigned int currentNrOfMechanics, unsigned short int garageNr,
        time inputStartShift, time inputEndShift);

char *GetMechanicName();
Date GetMechanicBirthDay();
 unsigned short int GetMechanicSpeciality();
 unsigned short int GetMechanicNrOfShifts ();
tMechanic *GetMechanicShift(tMechanic *mechanic, unsigned int currentNrOfMechanics, unsigned int mechanicNrToGiveShift, 
        tGarage *garage, unsigned short int currentNrOfGarages);
void ShowAllMechanic(tMechanic *mechanic, int currentNrOfMechanics);
void ShowMechanic(tMechanic *mechanic, unsigned int i);
int SearchMechanic(tMechanic *mechanic, unsigned int numMechanic,unsigned int *fID);
void material_sort(tMechanic* mechanic, unsigned int numMechanic);
tMechanic *mechanic_add(tMechanic *mechanic, unsigned int *numMechanic,tMechanic elementToAdd, bool isToOrder);
unsigned int *mechanic_addID(unsigned int *fID, unsigned int numMechanic,unsigned int elementToAdd);
void mechanic_outputSearch(tMechanic mechanic, unsigned int id);
void mechanic_sort(tMechanic* mechanic, unsigned int numMechanic);
void ListMechanicEditFields();
int string_lentgh(char* str);
tMechanic *EditMechanic(tMechanic *mechanic, int currentNrOfMechanics, tGarage *garage, unsigned short int currentNrOfGarages);
short unsigned int *CheckGarageAvaiableForMechanic (short unsigned int mechanicSpeciality, 
        tGarage *garage, short unsigned int currentNrOfGarages, short unsigned int *nrOfGaragesAvaiable);

void ListShifs(tSchedule *shift, unsigned short int currentNrOfShifts);
tSchedule *DeleteShift(tSchedule *shift, unsigned short int currentNrOfShifts);
tMechanic *ShiftMenu(tMechanic *mechanic, unsigned int currentNrOfMechanics,
        unsigned int mechanicNrToGiveShift, tGarage *garage, unsigned short int currentNrOfGarages);
#endif	/* MECHANIC_H */

