#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "garage.h"
#define MAX 10




/*int main(void) {
    unsigned short int currentNrOfGarages = 0;
    tGarage garage[10];
    //AddGarage(garage, &currentNrOfGarages);
    //printf ("%hu", currentNrOfGarages);
    garage[0].area = 1;
    garage[0].enable = true;
    garage[0].floor = 1;
    garage[0].hangarLocation = 0;
    garage[0].number = 1;
    garage[0].speciality = 1;


    garage[1].area = 1;
    garage[1].enable = true;
    garage[1].floor = 1;
    garage[1].hangarLocation = 0;
    garage[1].number = 2;
    garage[1].speciality = 1;

    currentNrOfGarages += 2;
    ListGarage(garage, currentNrOfGarages);
    AddGarage(garage, &currentNrOfGarages);
    //DeleteGarage(garage, &currentNrOfGarages);
    //SeachGarage(garage, currentNrOfGarages);
    //ListGarage(garage, currentNrOfGarages);
    EditGarage(garage, currentNrOfGarages);
    ListGarage(garage, currentNrOfGarages);
    return (EXIT_SUCCESS);
}
*/
void AddGarage(tGarage *garage, unsigned short int *currentNrOfGarages) {
    unsigned short int inputHangar, inputFloor, inputSpeciality;
    float inputArea;
    if (*currentNrOfGarages < MAX){
    garage[*currentNrOfGarages].number = (*currentNrOfGarages) + 1;

    do {
        printf("\nInsira a area da oficina: ");
    } while (!IsAreaValid(&inputArea));
    garage[*currentNrOfGarages].area;
    do {
        printf("\nInsira o andar a que pertece a oficina (0-2): ");
        scanf("%hu", &inputFloor);
        ClearBuffer();

    } while (!IsValidFloor(inputFloor));
    garage[*currentNrOfGarages].floor = inputFloor;

    do {
        ShowListHangar();
        printf("\nInsira o hanger a que pertece a oficina: ");
        scanf("%hu", &inputHangar);
        ClearBuffer();
    } while (!IsValidHangar(inputHangar));

    do {
        ShowSpecialityList();
        printf("\nInsira a especialidade da oficina:");
        scanf("%hu", &inputSpeciality);
        ClearBuffer();
    } while (!IsSpecialityValid(inputSpeciality));

    garage[*currentNrOfGarages].speciality = inputSpeciality;
    garage[*currentNrOfGarages].hangarLocation = inputHangar;
    garage[*currentNrOfGarages].enable = true;
    (*currentNrOfGarages)++;
    }else {
        printf("\nNumero de oficinas maximo atingido");
    }
}

void ListGarage(tGarage *garage, unsigned short int currentNrOfGarages) {
    int i;

    for (i = 0; i < currentNrOfGarages; i++) {

        ShowGarage(garage, i);
    }
}

void ShowGarage(tGarage *garage, unsigned short int garageToShow) {
    printf("\nGaragens:");

    if (garage[garageToShow].number != -1) {
        printf("\nNumero: %i", garage[garageToShow].number);
    } else {
        printf("\nNumero: -1 (Desativa)");
    }
    printf("\nArea: %f", garage[garageToShow].area);
    printf("\nPiso: %i", garage[garageToShow].floor);
    printf("\nHangar: ");

    switch (garage[garageToShow].hangarLocation) {
        case NORTH: printf("norte\n");
            break;
        case SOUTH: printf("sul\n");
            break;
        case EAST: printf("este\n");
            break;
        case WEST: printf("oeste\n");
            break;
        default:
            printf(" inválido");
            break;
    }
}

void DeleteGarage(tGarage *garage, unsigned short int *currentNrOfGarages) {
    unsigned short int garageToDelete, i;

    printf("\nInsira o número da garagem que pretende apagar: ");
    do {
        scanf("%hu", &garageToDelete);
        ClearBuffer();
    } while (!IsValidGarageNr(garageToDelete, *currentNrOfGarages));

    //ver se tem materiais associados
    printf("\nExistem materiais associados a esta oficina");
    printf("\n0 - Apagar materiais");
    printf("\n1 - Transferir materiais para outra oficina");
    printf("\n2 - Desassociar materiais da oficina a apagar");
    for (i = garageToDelete; i < (*currentNrOfGarages); i++) {
        garage[i] = garage[i + 1];
    }
    (*currentNrOfGarages)--;
}

void EditGarage(tGarage *garage, unsigned short int currentNrOfGarages) {
    short int garageFound;
    unsigned short int inputFieldToEdit;
    float inputArea;
    unsigned short int inputNr;
    
    printf("\nInsira a oficina que pretende editar: ");
    garageFound = ChooseGarage(garage, currentNrOfGarages);
    if (garageFound != -1) {
        printf("\nSelecionou a seguinte oficina:");
        ShowGarage(garage, garageFound);
        printf("\n0 - Area");
        printf("\n1 - Especialidade");
        printf("\n2 - Piso");
        printf("\n3 - Hangar");
       
        do {
            printf("\nInsira o campo que pretende editar: ");
            scanf("%hu", &inputFieldToEdit);
           ClearBuffer();
        } while (!IsInputSearchFieldValid(inputFieldToEdit,0,3));

        switch (inputFieldToEdit) {
            case 0:
                do {
                    printf("\nInsira a nova area: ");
                } while (!IsAreaValid(&inputArea));
                garage[garageFound].area = inputArea;
                break;
            case 1:
                do {
                    ShowAllGarageFields();
                    printf("\nInsira a nova nova especialidade: ");
                    scanf("%hu", &inputNr);
                   ClearBuffer();
                } while (!IsSpecialityValid(inputNr));
                garage[garageFound].speciality = inputNr;
                break;
            case 2:
                do {
                    printf("\nInsira o novo andar (0-2): ");
                    scanf("%hu", &inputNr);
                    ClearBuffer();
                } while (!IsValidFloor(inputNr));
                garage[garageFound].floor = inputNr;
                break;
            case 3:
                do {
                    printf("\nInsira o novo hangar: ");
                    scanf("%hu", &inputNr);
                   ClearBuffer();
                } while (!IsValidHangar(inputNr));
                garage[garageFound].hangarLocation = inputNr;
                break;
            default:
                printf("\nOpcao invalida");
                break;
        }
        

    } else {
        printf("\nNão foram encontrados resultados");
    }
}

void SeachGarage(tGarage *garage, unsigned short int currentNrOfGarage) {
    short int garageFound;
    garageFound = ChooseGarage(garage, currentNrOfGarage);

    if (garageFound != -1) {
        ShowGarage(garage, garageFound);
    } else {
        printf("\nNão foram encontrados resultados");
    }

}

bool IsInputSearchFieldValid( unsigned short int inputSearchField , 
        unsigned short int min, unsigned short int max){
    if (inputSearchField < min || inputSearchField > max){
        printf("\nValor Inserido Invalido");
        return false;
    }
    else {
        return true;
    }
}

short int ChooseGarage(tGarage *garage, unsigned short int currentNrOfGarages) {
    unsigned short int inputSearchField;
    
    do {
        ShowAllGarageFields();
        printf("\nInsira o campo pelo qual quer pesquisar a oficina: ");
        scanf("%hu", &inputSearchField);
        ClearBuffer();
    } while (!IsInputSearchFieldValid(inputSearchField, 0, 4));

    switch (inputSearchField) {
        case 0:
            return SearchForNumber(garage, currentNrOfGarages);
            break;
        case 1:
            return SearchForArea(garage, currentNrOfGarages);
            break;
        case 2:
            return SearchForSpeciality(garage, currentNrOfGarages);
            break;
        case 3:
            return SearchForFloor(garage, currentNrOfGarages);
            break;
        case 4:
            return SearchForHanger(garage, currentNrOfGarages);
            break;
        default:
            printf("\nOpcao invalida");
            break;
    }

}

short int SearchForNumber(tGarage *garage, unsigned short int currentNrOfGarages) {
    unsigned short int inputNr;

    printf("\nInsira o numero da oficina:");
    scanf("%hu", &inputNr);
    ClearBuffer();
    if (inputNr <= currentNrOfGarages) {
        return inputNr - 1;
    } else {
        return -1;
    }
}

short int SearchForArea(tGarage *garage, unsigned short int currentNrOfGarages) {
    unsigned short int i = 0, nrOfOccurrences = 0;
    unsigned short int *nrOfGarageFound = NULL;
    float inputArea;

    do {
        printf("\nInsira a área da oficina:");
        scanf("%f", &inputArea);
        ClearBuffer();
    } while (inputArea < 0);
    while (i < currentNrOfGarages) {
        if (inputArea == garage[i].area) {
            nrOfGarageFound = FoundOccurrence(&nrOfOccurrences, nrOfGarageFound, i);
        }
        i++;
    }

    return CheckMultiplyOccurences(garage, nrOfOccurrences, nrOfGarageFound);

}

short int SearchForSpeciality(tGarage *garage, unsigned short int currentNrOfGarages) {
    unsigned short int inputSpeciality;
    unsigned short int i = 0, nrOfOccurrences = 0, inputNr = 0;
    unsigned short int *nrOfGarageFound = NULL;

    printf("\nInsira a specialidade da oficina:");
    ShowSpecialityList();
    scanf("%hu", &inputSpeciality);
    ClearBuffer();
    while (i < currentNrOfGarages) {
        if (inputSpeciality == garage[i].speciality) {
            nrOfGarageFound = FoundOccurrence(&nrOfOccurrences, nrOfGarageFound, i);
        }
        i++;
    }

    return CheckMultiplyOccurences(garage, nrOfOccurrences, nrOfGarageFound);
}

unsigned short int *FoundOccurrence(unsigned short int *nrOfOccurrences, unsigned short int *nrOfGarageFound,
        unsigned short int i) {
    int temp = *nrOfOccurrences;
    (*nrOfOccurrences)++;
    nrOfGarageFound = (unsigned short int *) realloc(nrOfGarageFound,
            *nrOfOccurrences * sizeof (unsigned short int));
    nrOfGarageFound[temp] = i;

    return nrOfGarageFound;
}

short int CheckMultiplyOccurences(tGarage *garage, unsigned short int nrOfOccurrences,
        unsigned short int *nrOfGarageFound) {

    if (nrOfOccurrences > 1) {
        return (int) multiplyOcurrencesFound(garage, nrOfOccurrences, nrOfGarageFound);
    } else if (nrOfOccurrences == 1) {

        return (int) *nrOfGarageFound;
    } else {
        return -1;
    }
}

short int SearchForFloor(tGarage *garage, unsigned short int currentNrOfGarages) {
    unsigned short int inputFloor;
    unsigned short int i = 0, nrOfOccurrences = 0;
    unsigned short int *nrOfGarageFound = NULL;

    do {
        printf("\nInsira o andar da oficina (0-2):");
        scanf("%hu", &inputFloor);
       ClearBuffer();
    } while (!IsValidFloor(inputFloor));
    while (i < currentNrOfGarages) {
        if (inputFloor == garage[i].floor) {
            nrOfGarageFound = FoundOccurrence(&nrOfOccurrences, nrOfGarageFound, i);
        }
        i++;
    }

    return CheckMultiplyOccurences(garage, nrOfOccurrences, nrOfGarageFound);
}

short int SearchForHanger(tGarage *garage, unsigned short int currentNrOfGarages) {
    unsigned short int inputHangar;
    unsigned short int i = 0, nrOfOccurrences = 0, inputNr = 0;
    unsigned short int *nrOfGarageFound = NULL;

    do {
        printf("\nInsira o hangar da oficina:");
        scanf("%hu", &inputHangar);
        ClearBuffer();
    } while (!IsValidHangar(inputHangar));
    while (i < currentNrOfGarages) {
        if (inputHangar == garage[i].hangarLocation) {
            nrOfGarageFound = FoundOccurrence(&nrOfOccurrences, nrOfGarageFound, i);
        }
        i++;
    }

    return CheckMultiplyOccurences(garage, nrOfOccurrences, nrOfGarageFound);
}

unsigned short int multiplyOcurrencesFound(tGarage *garage, unsigned short int nrOfOccurrences,
        unsigned short int *nrOfGarageFound) {
    unsigned short int i;
    unsigned short int inputNr = 0;
    bool isNumberValid = false;
    printf("\nForam encontrados diversos resultados");
    do {

        for (i = 0; i < nrOfOccurrences; i++) {
            printf("\nnumero: %hu", garage[nrOfGarageFound[i]].number);
        }
        printf("\nInsira o numero da garagem que pretende: ");
        scanf("%hu", &inputNr);
        ClearBuffer();
        inputNr--;
        for (i = 0; i < nrOfOccurrences; i++) {
            if (inputNr == nrOfGarageFound[i]) {
                isNumberValid = true;
            }
        }

    } while (!isNumberValid);
    return inputNr;
}

bool IsValidGarageNr(unsigned short int inputGarageNr, unsigned short int currentNrOfGarages) {

    if (inputGarageNr <= 0 || inputGarageNr > currentNrOfGarages) {
        printf("Numero de oficina inválido, insira corretamente");
        return false;
    } else {
        return true;
    }
}

bool IsValidHangar(unsigned short int inputHangar) {

    if (inputHangar < 0 || inputHangar > 3) {
        printf("Hangar inválido, insira corretamente");
        return false;
    } else {
        return true;
    }
}

bool IsAreaValid(float *inputArea) {
    if (scanf("%f", inputArea) <= 0) {
        ClearBuffer();
        printf("\nArea invalida");
        return false;
    } else {
        ClearBuffer();
        return true;
    }   
}

bool IsValidFloor(unsigned short int inputFloor) {

    if (inputFloor < 0 || inputFloor > 2) {
        printf("\nPiso inválido, insira corretamente");
        return false;
    } else {
        return true;
    }
}

void ShowListHangar() {
    printf("\n0 - Norte");
    printf("\n1 - Sul");
    printf("\n2 - Este");
    printf("\n3 - Oeste\n");
}

bool IsSpecialityValid(unsigned short int inputSpeciality) {
    if (inputSpeciality < 0 || inputSpeciality > 6) {
        printf("\nEspecialidade inválido, insira corretamente");
        return false;
    } else {
        return true;
    }
}

void ShowSpecialityList() {
    printf("\n0 - Automoveis");
    printf("\n1 - Motociclos Simples");
    printf("\n2 - Motociclos de alta cilindrada");
    printf("\n4 - Camioes");
    printf("\n5 - Barcos a motor");
    printf("\n6 - Bi-motor");
}

void ShowAllGarageFields() {
    printf("\n0 - Numero");
    printf("\n1 - Area");
    printf("\n2 - Especialidade");
    printf("\n3 - Piso");
    printf("\n4 - Hangar");
}

void ClearBuffer() {
    int c;
while((c = getchar()) != '\n' && c != EOF);
}