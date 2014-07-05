#ifndef GARAGE_H
#define	GARAGE_H
 #include "material.h"
 #include "speciality.h"

#define MAX_GARAGE 10

typedef enum {
    CARS = 0,
    SIMPLE_MOTORCYLES = 1,
    HIGH_CYLINDER_MOTORCYLES = 2,
    TRUCKS = 3,
    BOATS_MOTOR = 4,
    BOATS_BI_MOTOR = 5
} enumSpeciality;

typedef enum hangar {
    NORTH = 0,
    SOUTH = 1,
    EAST = 2,
    WEST = 3
} enumHangar;

typedef struct {
    short unsigned  int number;
    float area;
    short unsigned  int floor;
    enumHangar hangarLocation;
    bool enable;
    enumSpeciality speciality;
    tMaterial *material;
    unsigned int nrOfMaterials;
    tMechanic *mechanic;
    unsigned int nrOfMechanics;
} tGarage;

void AddGarage(tGarage*, short unsigned  int*);
void SeachGarage(tGarage*, short unsigned  int);
void ListGarage(tGarage*, short unsigned  int);
void DeleteGarage(tGarage*, short unsigned  int*);
void EditGarage(tGarage*, short unsigned  int);
void ShowListHangar();
void ShowSpecialityList();
void ShowAllGarageFields();
void ShowGarage(tGarage*,short unsigned  int);

short int ChooseGarage(tGarage*, short unsigned  int);
short int SearchForNumber(tGarage*, short unsigned  int, short int);
short int SearchForArea(tGarage*, short unsigned  int);
short int SearchForSpeciality(tGarage*,short unsigned  int);
short int SearchForFloor(tGarage*, short unsigned  int);
short int SearchForHanger(tGarage*, short unsigned  int);

bool IsValidGarageNr(short unsigned  int, short unsigned  int);
bool IsValidHangar(short unsigned  int);
bool IsValidFloor(short unsigned  int);
bool IsSpecialityValid(short unsigned  int);
bool IsAreaValid(float*);
bool IsInputSearchFieldValid (short unsigned  int,short unsigned  int, short unsigned  int);

short int CheckMultiplyOccurences(tGarage*, short unsigned  int,short unsigned  int*);

float GetGarageArea();

short unsigned  int* FoundOccurrence(short unsigned  int*,short unsigned  int*,short unsigned  int);
short unsigned  int GetGarageFloor();
short unsigned  int GetGarageHangar();
short unsigned  int GetGarageSpeciality();
short unsigned  int multiplyOcurrencesFound(tGarage*,short unsigned  int,short unsigned  int*);
#endif	/* GARAGE_H */
