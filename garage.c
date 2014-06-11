#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum hangar {
    NORTH = 0,
    SOUTH = 1,
    EAST = 2,
    WEST = 3
} enumHangar;

typedef struct garage {
    unsigned short int number;
    float area;
    unsigned short int floor;
    enumHangar hangarLocation;
    bool enable;
    enumSpeciality speciality;
} tGarage;

bool isValidHangar( unsigned short int inputHangar);
bool isValidFloor(unsigned short int inputFloor);
void AddGarage(tGarage *garage, int currentNrOfGarages) {
    unsigned short int inputHangar, inputFloor;

    garage[currentNrOfGarages].number = currentNrOfGarages + 1;
    printf("\nInsira a area da oficina: ");
    scanf("%f", &garage[currentNrOfGarages].area);
    getchar();

    do {
        printf("\nInsira o andar a que pertece a oficina (0-2): ");
        scanf("%hu", &inputFloor);
        getchar();

    } while (!isValidFloor(inputFloor));
    garage[currentNrOfGarages].floor = inputFloor;
    
    do {
        printf("\nInsira o hanger a que pertece a oficina");
        printf("0 - Norte");
        printf("1 - Sul");
        printf("2 - Este");
        printf("3 - Oeste");
        scanf("%hu", &inputHangar);
        getchar();
    } while (!isValidHangar(inputHangar));
    
    garage[currentNrOfGarages].hangarLocation = inputHangar;
    garage[currentNrOfGarages].enable = true;
}

void SeachGarage() {

}

void ListGarage(tGarage *garage, int currentNrOfGarages) {
    int i;

    for (i = 0; i < currentNrOfGarages; i++) {
        printf("\nGaragens:");

        if (garage[currentNrOfGarages].number != -1) {
            printf("\nNumero: %i", garage[currentNrOfGarages].number);
        } else {
            printf("\nNumero: -1 (Desativa)");
        }

        printf("\nPiso: %i", garage[currentNrOfGarages].floor);
        printf("\nHangar: ");

        switch (garage[currentNrOfGarages].hangarLocation) {
            case NORTH: printf(" norte");
                break;
            case SOUTH: printf(" sul");
                break;
            case EAST: printf(" este");
                break;
            case WEST: printf(" oeste");
                break;
            default:
                printf(" inválido");
                break;
        }

    }
}

void DeleteGarage(tGarage *garage, int *currentNrOfGarages) {
    unsigned short int garageToDelete, i;
    
    for (i=garageToDelete; i < currentNrOfGarages-1; i++){
        garage[i]=garage[i+1];
    }
    *currentNrOfGarages--;
}

void EditGarage(tGarage *garage, int currentNrOfGarages) {

}

int ChooseGarage(tGarage *garage, int currentNrOfGarages) {
    unsigned short int inputFloor, inputHangar, inputSearchField;
    int input;
    int i;
    do {
    printf ("\nInsira o campo pelo qual quer pesquisar a oficina");
    printf ("\n0 - Numero");
    printf ("\n1 - Area");
    printf ("\n2 - Especialidade");
    printf ("\n3 - Piso");
    printf ("\n4 - Hangar");
    scanf ("hu", &inputSearchField);
    }while (inputSearchField < 0 || inputSearchField > 4);
    
    switch (inputSearchField){
        case 0 : 
            break;
            case 1 : 
            break;
            case 2 : 
            break;
            case 3 : 
            break;
            case 4 : 
            break;
        default :
            printf ("Opcao invalida");
            break;
    }
    
    
    
    
    
    /*
    do{
    printf("\nInsira o andar a que pertece a oficina (0-2): ");
    scanf("%hu", &inputFloor);
    getchar();
    }while(!isValidFloor(inputFloor));
    
    do{
    printf("\nInsira o hangar a que pertece a oficina");
    printf("0 - Norte");
    printf("1 - Sul");
    printf("2 - Este");
    printf("3 - Oeste");
    scanf("%hu", &inputHangar);
    getchar();
    }while (!isValidHangar(inputHangar));
    
    for (i=0; i < currentNrOfGarages; i++){
        if (garage[currentNrOfGarages].floor == inputFloor && garage[currentNrOfGarages].hangar==inputHangar && )
    }
     * aa
    */
}

int SearchForNumber (tGarage *garage, int *currentNrOfGarages) {
    unsigned short int inputNr;
    printf("\nInsira o numero da oficina:");
    scanf("%hu", &inputNr);
    if (inputNr <= currentNrOfGarages) {
        return inputNr-1;
    }
}
int SearchForArea (tGarage *garage) {
    float inputArea;
}
int SearchForSpeciality (tGarage *garage) {
    unsigned short int inputSpeciality;
}
int SearchForFloor (tGarage *garage) {
    unsigned short int inputFloor;
}
int SearchForHanger (tGarage *garage) {
    unsigned short int inputHangar;
}

bool isValidHangar(unsigned short int inputHangar) {
    
    if (inputHangar < 0 || inputHangar > 3) {
        printf("Hangar inválido, insira corretamente");
        return false;
    } else {
        return true;
    }
}

bool isValidFloor(unsigned short int inputFloor) {
    
    if (inputFloor < 0 || inputFloor > 2) {
        printf("Piso inválido, insira corretamente");
        return false;
    } else {
        return true;
    }
}

