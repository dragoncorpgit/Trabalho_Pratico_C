#ifndef GARAGE_H
#define	GARAGE_H
 #include "material.h"
 #include "speciality.h"
 #include "mechanic.h"

#define MAX_GARAGE 10
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

void AddGarage(tGarage*, short unsigned int*);
void SeachGarage(tGarage*, short unsigned int);
void ListGarage(tGarage*, short unsigned int);
void DeleteGarage(tGarage*, short unsigned int*);
void EditGarage(tGarage*, short unsigned int);
void ShowListHangar();
void ShowSpecialityList();
void ShowAllGarageFields();
void ShowGarage(tGarage*,short unsigned int);

short int ChooseGarage(tGarage*, short unsigned int);
short int SearchForNumber(tGarage*, short unsigned int, short int);
short int SearchForArea(tGarage*, short unsigned int);
short int SearchForSpeciality(tGarage*,short unsigned int);
short int SearchForFloor(tGarage*, short unsigned int);
short int SearchForHanger(tGarage*, short unsigned int);

bool IsValidGarageNr(short unsigned int, short unsigned int);
bool IsValidHangar(short unsigned int);
bool IsValidFloor(short unsigned int);
bool IsAreaValid(float*);
bool IsInputSearchFieldValid (short unsigned int,short unsigned int, short unsigned int);

short int CheckMultiplyOccurences(tGarage*, short unsigned int,short unsigned int*);

float GetGarageArea();

short unsigned int* FoundOccurrence(short unsigned int*,short unsigned int*,short unsigned int);
short unsigned int GetGarageFloor();
short unsigned int GetGarageHangar();
short unsigned int GetGarageSpeciality();
short unsigned int multiplyOcurrencesFound(tGarage*,short unsigned int,short unsigned int*);
#endif	/* GARAGE_H */
