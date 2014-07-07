/* 
 * File:   mechanic.h
 * Author: gaming
 *
 * Created on July 2, 2014, 12:19 PM
 */

#ifndef MECHANIC_H
 #define	MECHANIC_H
 #include "garageStruct.h"

 tMechanic* InsertMechanic(tMechanic*,unsigned int*, tGarage*,short unsigned int);
 tMechanic* EditMechanic(tMechanic*,int,tGarage*,short unsigned int);
 tMechanic* RemoveMechanic(tMechanic*, unsigned int*);
 tMechanic* GetMechanicShift(tMechanic*,unsigned int,unsigned int,tGarage*,short unsigned int);
 tMechanic* mechanic_add(tMechanic*,unsigned int*,tMechanic,bool);
 tMechanic* ShiftMenu(tMechanic*,unsigned int,unsigned int,tGarage*,short unsigned int); 

 tSchedule* DeleteShift(tSchedule*,short unsigned int);

 char* GetMechanicName(); 

 unsigned int* mechanic_addID(unsigned int*, unsigned int,unsigned int);

 short unsigned int* CheckGarageAvaiableForMechanic(short unsigned int,tGarage*,short unsigned int,short unsigned int*);

 bool IsNrHiggerThanZeroOrEqual(short unsigned int);
 bool IsShiftTimeValid(char shiftTime[], short unsigned int*, short unsigned int*);
 bool IsShiftStartTimeAndEndTimeValid (time, time);
 bool ShiftIsAvaiable(tMechanic*, unsigned int, short unsigned int,time, time);

 short unsigned int GetMechanicSpeciality();
 short unsigned int GetMechanicNrOfShifts ();
 short unsigned int ConcateShiftTime(char, char);

 Date GetMechanicBirthDay();
 
 int SearchMechanic(tMechanic*, unsigned int,unsigned int*);
 
 void ShowAllMechanic(tMechanic*,int);
 void ShowMechanic(tMechanic*, unsigned int);
 void mechanic_sort(tMechanic*, unsigned int);
 void mechanic_outputSearch(tMechanic, unsigned int);
 void mechanic_sort(tMechanic*, unsigned int);
 void ListMechanicEditFields();
 void ListShifs(tSchedule*,short unsigned int); 
 
 
#endif	/* MECHANIC_H */

