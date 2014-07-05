#include "garage.h"

void AddGarage(tGarage *garage, short unsigned int *currentNrOfGarages) {



    if (*currentNrOfGarages < MAX_GARAGE ) {
        garage = (tGarage*) realloc (garage, sizeof(tGarage) * (*currentNrOfGarages));
        garage[*currentNrOfGarages].number = (*currentNrOfGarages) + 1;
        garage[*currentNrOfGarages].area = GetGarageArea();

        garage[*currentNrOfGarages].floor = GetGarageFloor();
        garage[*currentNrOfGarages].speciality = GetGarageSpeciality();
        garage[*currentNrOfGarages].hangarLocation = GetGarageHangar();
        garage[*currentNrOfGarages].enable = true;
        (*currentNrOfGarages)++;

    } else {
        printf("\nNumero de oficinas maximo atingido");
    }
}

float GetGarageArea() {
    float inputArea;
    do {
        printf("\nInsira a area da oficina: ");
    } while (!IsAreaValid(&inputArea));
    
    return inputArea;
}

short unsigned int GetGarageFloor() {
    short unsigned int inputFloor;
    do {
        printf("\nInsira o andar a que pertece a oficina (0-2): ");
        scanf("%hu", &inputFloor);
        ClearBuffer();

    } while (!IsValidFloor(inputFloor));
    
    return inputFloor;
}

short unsigned int GetGarageHangar() {
    short unsigned int inputHangar;
    do {
        ShowListHangar();
        printf("\nInsira o hangar a que pertece a oficina: ");
        scanf("%hu", &inputHangar);
        ClearBuffer();
    } while (!IsValidHangar(inputHangar));
    
    return inputHangar;
}

short unsigned int GetGarageSpeciality() {
    short unsigned int inputSpeciality;
    do {
        ShowSpecialityList();
        printf("\nInsira a especialidade da oficina:");
        scanf("%hu", &inputSpeciality);
        ClearBuffer();
    } while (!IsSpecialityValid(inputSpeciality));
    
    return inputSpeciality;
}

void ListGarage(tGarage *garage, short unsigned int currentNrOfGarages) {
    int i;

    for (i = 0; i < currentNrOfGarages; i++) {

        ShowGarage(garage, i);
    }
}

void ShowGarage(tGarage *garage, short unsigned int garageToShow) {
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

void DeleteGarage(tGarage *garage, short unsigned int *currentNrOfGarages) {
    short unsigned int garageToDelete, i;

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

void EditGarage(tGarage *garage, short unsigned int currentNrOfGarages) {
    short int garageFound;
    short unsigned int inputFieldToEdit;
    float inputArea;
    short unsigned int inputNr;

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
        } while (!IsInputSearchFieldValid(inputFieldToEdit, 0, 3));

        switch (inputFieldToEdit) {
            case 0:

                garage[garageFound].area = GetGarageArea();
                break;
            case 1:

                garage[garageFound].speciality = GetGarageSpeciality();
                break;
            case 2:

                garage[garageFound].floor = GetGarageFloor();
                break;
            case 3:

                garage[garageFound].hangarLocation = GetGarageHangar();
                break;
            default:
                printf("\nOpcao invalida");
                break;
        }


    } else {
        printf("\nNão foram encontrados resultados");
    }
}

void SeachGarage(tGarage *garage, short unsigned int currentNrOfGarage) {
    short int garageFound;
    garageFound = ChooseGarage(garage, currentNrOfGarage);

    if (garageFound != -1) {
        ShowGarage(garage, garageFound);
    } else {
        printf("\nNão foram encontrados resultados");
    }

}

bool IsInputSearchFieldValid(short unsigned int inputSearchField,
        short unsigned int min, short unsigned int max) {
    if (inputSearchField < min || inputSearchField > max) {
        printf("\nValor Inserido Invalido");
        return false;
    } else {
        return true;
    }
}

short int ChooseGarage(tGarage *garage, short unsigned int currentNrOfGarages) {
    short unsigned int inputSearchField;

    do {
        ShowAllGarageFields();
        printf("\nInsira o campo pelo qual quer pesquisar a oficina: ");
        scanf("%hu", &inputSearchField);
        ClearBuffer();
    } while (!IsInputSearchFieldValid(inputSearchField, 0, 4));

    switch (inputSearchField) {
        case 0:
            return SearchForNumber(garage, currentNrOfGarages,-1);
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

short int SearchForNumber(tGarage *garage, short unsigned int currentNrOfGarages, short int inputNr) {
 if(inputNr==-1)
 {
  printf("\nInsira o numero da oficina:");
  scanf("%hu", &inputNr);
  ClearBuffer();
 }
    
    if (inputNr <= currentNrOfGarages) {
        return inputNr - 1;
    } else {
        return -1;
    }
}

short int SearchForArea(tGarage *garage, short unsigned int currentNrOfGarages) {
    short unsigned int i = 0, nrOfOccurrences = 0;
    short unsigned int *nrOfGarageFound = NULL;
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

short int SearchForSpeciality(tGarage *garage, short unsigned int currentNrOfGarages) {
    short unsigned int inputSpeciality;
    short unsigned int i = 0, nrOfOccurrences = 0, inputNr = 0;
    short unsigned int *nrOfGarageFound = NULL;

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

short unsigned int *FoundOccurrence(short unsigned int *nrOfOccurrences, short unsigned int *nrOfGarageFound,
        short unsigned int i) {
    int temp = *nrOfOccurrences;
    (*nrOfOccurrences)++;
    nrOfGarageFound = (short unsigned int *) realloc(nrOfGarageFound,
            *nrOfOccurrences * sizeof (short unsigned int));
    nrOfGarageFound[temp] = i;

    return nrOfGarageFound;
}

short int CheckMultiplyOccurences(tGarage *garage, short unsigned int nrOfOccurrences,
        short unsigned int *nrOfGarageFound) {

    if (nrOfOccurrences > 1) {
        return (int) multiplyOcurrencesFound(garage, nrOfOccurrences, nrOfGarageFound);
    } else if (nrOfOccurrences == 1) {

        return (int) *nrOfGarageFound;
    } else {
        return -1;
    }
}

short int SearchForFloor(tGarage *garage, short unsigned int currentNrOfGarages) {
    short unsigned int inputFloor;
    short unsigned int i = 0, nrOfOccurrences = 0;
    short unsigned int *nrOfGarageFound = NULL;

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

short int SearchForHanger(tGarage *garage, short unsigned int currentNrOfGarages) {
    short unsigned int inputHangar;
    short unsigned int i = 0, nrOfOccurrences = 0, inputNr = 0;
    short unsigned int *nrOfGarageFound = NULL;

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

short unsigned int multiplyOcurrencesFound(tGarage *garage, short unsigned int nrOfOccurrences,
        short unsigned int *nrOfGarageFound) {
    short unsigned int i;
    short unsigned int inputNr = 0;
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

bool IsValidGarageNr(short unsigned int inputGarageNr, short unsigned int currentNrOfGarages) {

    if (inputGarageNr <= 0 || inputGarageNr > currentNrOfGarages) {
        printf("Numero de oficina inválido, insira corretamente");
        return false;
    } else {
        return true;
    }
}

bool IsValidHangar(short unsigned int inputHangar) {

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

bool IsValidFloor(short unsigned int inputFloor) {

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

bool IsSpecialityValid(short unsigned int inputSpeciality) {
    if (inputSpeciality < 0 || inputSpeciality > 5) {
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
    printf("\n3 - Camioes");
    printf("\n4 - Barcos a motor");
    printf("\n5 - Bi-motor");
}

void ConvertSpecialityNrToText(short unsigned int specialityNr ) {
    
    switch (specialityNr){
        case 0 :  printf("Automoveis");
        break;
        case 1 :  printf("Motociclos Simples");
        break;
        case 2 :  printf("Motociclos de alta cilindrada");
        break;
        case 3 :  printf("Camioes");
        break;
        case 4 :  printf("Barcos a motor");
        break;
        case 5 :  printf("Bi-motor");
        break;
        
    }
}

void ShowAllGarageFields() {
    printf("\n0 - Numero");
    printf("\n1 - Area");
    printf("\n2 - Especialidade");
    printf("\n3 - Piso");
    printf("\n4 - Hangar");
}