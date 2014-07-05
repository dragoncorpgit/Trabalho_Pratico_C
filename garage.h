#ifndef GARAGE_H
#define	GARAGE_H

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
    unsigned short int number;
    float area;
    unsigned short int floor;
    enumHangar hangarLocation;
    bool enable;
    enumSpeciality speciality;
    tMaterial *material;
    unsigned short int nrOfMaterials;
    tMechanic *mechanic;
    unsigned short int nrOfMechanics;
} tGarage;

void AddGarage(tGarage *garage, unsigned short int *currentNrOfGarages);
void SeachGarage(tGarage *garage, unsigned short int currentNrOfGarage);
void ListGarage(tGarage *garage, unsigned short int currentNrOfGarages);
void DeleteGarage(tGarage *garage, unsigned short int *currentNrOfGarages);
void EditGarage(tGarage *garage, unsigned short int currentNrOfGarages);
short int ChooseGarage(tGarage *garage, unsigned short int currentNrOfGarages);
short int SearchForNumber(tGarage *garage, unsigned short int currentNrOfGarages);
short int SearchForArea(tGarage *garage, unsigned short int currentNrOfGarages);
unsigned short int multiplyOcurrencesFound(tGarage *garage, unsigned short int nrOfOccurrences,
        unsigned short int *nrOfGarageFound);
short int SearchForSpeciality(tGarage *garage, unsigned short int currentNrOfGarages);
short int SearchForFloor(tGarage *garage, unsigned short int currentNrOfGarages);
short int SearchForHanger(tGarage *garage, unsigned short int currentNrOfGarages);

bool IsValidGarageNr(unsigned short int inputGarageNr, unsigned short int currentNrOfGarages);
bool IsValidHangar(unsigned short int inputHangar);
bool IsValidFloor(unsigned short int inputFloor);
void ShowListHangar();
bool IsSpecialityValid(unsigned short int inputSpeciality);
void ShowListHangar();
void ShowSpecialityList();
void ShowGarage(tGarage *garage, unsigned short int garageToShow);
short int CheckMultiplyOccurences(tGarage *garage, unsigned short int nrOfOccurrences,
        unsigned short int *nrOfGarageFound);
unsigned short int *FoundOccurrence(unsigned short int *nrOfOccurrences, 
        unsigned short int *nrOfGarageFound,
        unsigned short int i);
void ShowAllGarageFields();
bool IsAreaValid(float *inputArea);
bool IsInputSearchFieldValid (unsigned short int inputSearchField , 
        unsigned short int min, unsigned short int max);

float GetGarageArea();
unsigned short int GetGarageFloor();
unsigned short int GetGarageHangar();
unsigned short int GetGarageSpeciality();
char *RemoveBarN (char *input, int len);
#endif	/* GARAGE_H */
