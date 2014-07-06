#include "mechanic.h"

tMechanic *InsertMechanic(tMechanic *mechanic, unsigned int *currentNrOfMechanics, tGarage *garage,
        short unsigned int currentNrOfGarages) {


    mechanic = (tMechanic*) realloc(mechanic, sizeof (tMechanic) * (*currentNrOfMechanics + 1));

    mechanic[*currentNrOfMechanics].nr = (*currentNrOfMechanics) + 1;
    mechanic[*currentNrOfMechanics].name = NULL;
    mechanic[*currentNrOfMechanics].name = GetMechanicName();
    mechanic[*currentNrOfMechanics].dateOfBirth = GetMechanicBirthDay();
    mechanic[*currentNrOfMechanics].speciality = GetGarageSpeciality();
    mechanic[*currentNrOfMechanics].nrOfShifts = GetMechanicNrOfShifts();
    mechanic = GetMechanicShift(mechanic, *currentNrOfMechanics, *currentNrOfMechanics, garage, currentNrOfGarages);

    (*currentNrOfMechanics)++;
    return mechanic;
}

short unsigned int GetMechanicNrOfShifts() {
    short unsigned int nrOfShifts;

    do {
        printf("\nInsira o numero de turnos: ");
        scanf("%hu", &nrOfShifts);
        ClearBuffer();

    } while (!IsNrHiggerThanZeroOrEqual(nrOfShifts));

    return nrOfShifts;
}

char *GetMechanicName() {
   
    char *name = NULL;


    do {
        printf("\nInsira o nome do mecanico: ");
        scanf("%ms", &name);
        ClearBuffer();
    } while (name == NULL);
    
    string_removeNewLineFromArray(name);
    
    return name;
}

Date GetMechanicBirthDay() {
    Date inputBirthDate;
    short unsigned int inputDay, inputMonth, inputYear;
    do {
        printf("\nInsira o dia de nascimento: ");
        scanf("%hu", &inputDay);
        ClearBuffer();
        printf("\nInsira o mes de nascimento: ");
        scanf("%hu", &inputMonth);
        ClearBuffer();
        printf("\nInsira o ano de nascimento: ");
        scanf("%hu", &inputYear);
        ClearBuffer();
        fillDate(&inputBirthDate,inputDay, inputMonth, inputYear);
    } while (!isCorrectDate(inputBirthDate));

    return inputBirthDate;
}

short unsigned int GetMechanicSpeciality() {
    short unsigned int inputSpeciality;
    do {
        ShowSpecialityList();
        printf("\nInsira a especialidade do mecanico: ");
        scanf("%hu", &inputSpeciality);
        ClearBuffer();
    } while (!IsSpecialityValid(inputSpeciality));

    return inputSpeciality;
}

tMechanic *GetMechanicShift(tMechanic *mechanic, unsigned int currentNrOfMechanics, unsigned int mechanicNrToGiveShift,
        tGarage *garage, short unsigned int currentNrOfGarages) {

    short unsigned int inputGarageNr, i, i2;
    time inputStartShift, inputEndShift;
    char shiftTimeStar [6], shiftTimeEnd [6];
    bool shiftIsAvaiable, garageIsValid = false;
    short unsigned int nrOfGaragesAvaiable = 0;
    short unsigned int *avaiableGarageNrs;

    mechanic[mechanicNrToGiveShift].shift = (tSchedule*) realloc(mechanic[mechanicNrToGiveShift].shift,
            sizeof (tSchedule) * mechanic[mechanicNrToGiveShift].nrOfShifts);
    for (i = 0; i < mechanic[mechanicNrToGiveShift].nrOfShifts; i++) {
        do {
            avaiableGarageNrs = CheckGarageAvaiableForMechanic(mechanic[mechanicNrToGiveShift].speciality,
                    garage, currentNrOfGarages, &nrOfGaragesAvaiable);

            if (nrOfGaragesAvaiable > 0) {
                do {


                    for (i2 = 0; i2 < nrOfGaragesAvaiable; i2++) {
                        ShowGarage(garage, avaiableGarageNrs[i2]);
                    }
                    printf("\nInsira o numero de garagem onde o mecanico vai realizar o turno: ");
                    scanf("%hu", &inputGarageNr);
                    ClearBuffer();
                    for (i2 = 0; i2 < nrOfGaragesAvaiable; i2++) {
                        if (inputGarageNr == avaiableGarageNrs[i2] + 1) {
                            garageIsValid = true;
                        }
                    }

                } while (!(IsValidGarageNr(inputGarageNr, currentNrOfGarages) && garageIsValid));
            } else {
                printf("\nNao existe oficinas com a especialidade deste mecanico");
                return mechanic;
            }
            do {
                do {
                    printf("\nInsira a hora de inicio do turno numero %hu (ex: hh:mm): ", i);
                    fgets(shiftTimeStar, 6, stdin);
                    ClearBuffer();
                } while (!IsShiftTimeValid(shiftTimeStar, &inputStartShift.hour,
                        &inputStartShift.minute));

                do {
                    printf("\nInsira a hora de fim do turno numero %hu (ex: hh:mm): ", i);
                    fgets(shiftTimeEnd, 6, stdin);
                    ClearBuffer();
                } while (!IsShiftTimeValid(shiftTimeEnd, &inputEndShift.hour, &inputEndShift.minute));

            } while (!IsShiftStartTimeAndEndTimeValid(inputStartShift, inputEndShift));
            shiftIsAvaiable = ShiftIsAvaiable(mechanic, currentNrOfMechanics, inputGarageNr,
                    inputStartShift, inputEndShift);

        } while (!shiftIsAvaiable);
        mechanic[mechanicNrToGiveShift].shift->nrOfGarage = inputGarageNr;
        mechanic[mechanicNrToGiveShift].shift->startWork = inputStartShift;
        mechanic[mechanicNrToGiveShift].shift->finishWork = inputEndShift;

    }
    return mechanic;
}

bool ShiftIsAvaiable(tMechanic *mechanic, unsigned int currentNrOfMechanics, short unsigned int garageNr,
        time inputStartShift, time inputEndShift) {
    short unsigned int i, i2;
    short unsigned int inputStartTimeTotal, inputEndTimeTotal, startTimeTotal, endTimeTotal;

    inputStartTimeTotal = inputStartShift.hour * 60 + inputStartShift.minute;
    inputEndTimeTotal = inputEndShift.hour * 60 + inputEndShift.minute;


    for (i = 0; i < currentNrOfMechanics; i++) {
        for (i2 = 0; i2 < mechanic[i].nrOfShifts; i2++) {

            if (mechanic[i].shift[i2].nrOfGarage == garageNr) {
                startTimeTotal = mechanic[i].shift[i2].startWork.hour * 60
                        + mechanic[i].shift[i2].startWork.minute;
                endTimeTotal = mechanic[i].shift[i2].finishWork.hour * 60
                        + mechanic[i].shift[i2].finishWork.minute;

                if (IsNrBetween(startTimeTotal, endTimeTotal, inputStartTimeTotal)
                        || IsNrBetween(startTimeTotal, endTimeTotal, inputEndTimeTotal)) {
                    printf("\nO mecanico numero %hu ja esta a trabalhar na oficina "
                            "selecionada e durante o horario selecionado, insira outra hora "
                            "ou outra oficina", mechanic[i].nr);

                    return false;
                }
            }
        }
    }
    return true;
}

bool IsShiftTimeValid(char shiftTime [9], short unsigned int *hour, short unsigned int *minute) {
    short unsigned int inputHour, inputMinute;

    if (shiftTime[2] == ':') {
        inputHour = ConcateShiftTime(shiftTime[0], shiftTime[1]);
        inputMinute = ConcateShiftTime(shiftTime[3], shiftTime[4]);

        if (IsNrBetween(0, 23, inputHour)) {
            if (IsNrBetween(0, 59, inputMinute)) {
                *hour = inputHour;
                *minute = inputMinute;
                return true;
            } else {
                printf("\nHora inserida invalida");
                return false;
            }
        }
    } else {
        printf("\nHora inserida invalida");

        return false;
    }
}

bool IsShiftStartTimeAndEndTimeValid(time startShiftTime, time endShiftTime) {
    int startShiftTimeTotal, endShiftTimeTotal;

    startShiftTimeTotal = startShiftTime.hour * 60 + startShiftTime.minute;
    endShiftTimeTotal = endShiftTime.hour * 60 + endShiftTime.minute;

    if (startShiftTimeTotal < endShiftTimeTotal) {
        return true;
    } else {
        printf("Fim de turno invalido");

        return false;
    }
}

short unsigned int ConcateShiftTime(char firstDigit, char secondDigit) {
    char *concateAuxiliar = (char *) malloc(2);
    strncat(concateAuxiliar, &firstDigit, 1);
    strncat(concateAuxiliar, &secondDigit, 1);

    return atoi(concateAuxiliar);
}

bool IsNrHiggerThanZeroOrEqual(short unsigned int inputNr) {
    if (inputNr < 0) {
        printf("Numero invalido");
        return false;
    } else {

        return true;
    }
}

tMechanic *EditMechanic(tMechanic *mechanic, int currentNrOfMechanics, tGarage *garage, short unsigned int currentNrOfGarages) {
    short unsigned int inputNr;
    unsigned int searchResult;

    searchResult = SearchMechanic(mechanic, currentNrOfMechanics, NULL);
    if (searchResult != -1) {
        do {
            ListMechanicEditFields();
            printf("\nSelecione o campo que pretende alterar:");
            scanf("%hu", &inputNr);
            ClearBuffer();
        } while (!IsNrBetween(0, 3, inputNr));

        switch (inputNr) {
            case 0:
                free(mechanic[searchResult].name);
                mechanic[searchResult].name = NULL;
                mechanic[searchResult].name = GetMechanicName();

                break;

            case 1:
                mechanic[searchResult].dateOfBirth = GetMechanicBirthDay();
                break;

            case 2:
                mechanic[searchResult].speciality = GetMechanicSpeciality();
                break;

            case 3:
                mechanic = ShiftMenu(mechanic, currentNrOfMechanics, searchResult, garage, currentNrOfGarages);
                break;

            default:
                printf("\nOpcao Invalida");
                break;
        }
    }
    return mechanic;
}

int SearchMechanic(tMechanic *mechanic, unsigned int numMechanic, unsigned int *fID) {
    int i = -1;
    tMechanic *fMechanic = NULL;
    unsigned int fundMechanic = 0;
    unsigned int* fundID = NULL;
    char* str = NULL;
    char* denToFind = NULL;
    bool byDenomination = true;

    if (fID != NULL) {
        printf("\n\nID: -1 (para re-procurar por nome): ");
        scanf("%i", &i);
        ClearBuffer();
        if (i != -1) {
            byDenomination = false;
            fundMechanic = i;
        } else {
            do {
                printf("\nNome a procurar: ");
                scanf("%ms", &denToFind);
            } while (denToFind == NULL);
            denToFind = string_removeNewLineFromPointer(denToFind);
        }
    } else {
        do {
            printf("\nNome a procurar: ");
            scanf("%ms", &denToFind);
        } while (denToFind == NULL);
        denToFind = string_removeNewLineFromPointer(denToFind);
    }

    if (byDenomination) {
        for (i = 0; i < numMechanic; i++) {
            str = strstr((mechanic[i].name), denToFind);
            if (str != NULL) {
                if (fID == NULL) {
                    fMechanic = (tMechanic*) mechanic_add(fMechanic,
                            &fundMechanic, mechanic[i], false);
                    fundID = (unsigned int*) mechanic_addID(fundID, fundMechanic - 1, i);
                } else {
                    fMechanic = (tMechanic*) mechanic_add(fMechanic,
                            &fundMechanic, mechanic[fID[i]], false);
                    fundID = (unsigned int*) mechanic_addID(fundID, fundMechanic - 1, fID[i]);
                }
            }
        }

        if (fundMechanic != 0) {
            if (fundMechanic != 1) {
                for (i = 0; i < fundMechanic; i++) {
                    mechanic_outputSearch(fMechanic[i], fundID[i]);
                }
                return SearchMechanic(fMechanic, fundMechanic, fundID);
            } else {
                fundMechanic = (fundID)[0];
                free(fMechanic);
                free(fundID);
                return fundMechanic;
            }
        } else {
            printf("\nNão existem procuras com a descrição inserida");
            return -1;
        }
    } else {
        return fundMechanic;
    }
}

unsigned int *mechanic_addID(unsigned int *fID, unsigned int numMechanic,
        unsigned int elementToAdd) {
    fID = (unsigned int*) realloc(fID, (sizeof (unsigned int)*(numMechanic)));
    if (fID != NULL) {
        fID[numMechanic] = elementToAdd;
    }
    return (unsigned int*) fID;
}

void mechanic_outputSearch(tMechanic mechanic, unsigned int id) {
    printf("\nNumero: %i", id);
    printf("\nNome: %s ", mechanic.name);

}

tMechanic * mechanic_add(tMechanic *mechanic, unsigned int *numMechanic,
        tMechanic elementToAdd, bool isToOrder) {
    mechanic = (tMechanic*) realloc(mechanic, (sizeof (tMechanic)*(*numMechanic + 1)));
    if (mechanic != NULL) {
        mechanic[*numMechanic] = elementToAdd;
        (*numMechanic)++;
    }
    if (isToOrder) {
        mechanic_sort(mechanic, *numMechanic);
    }
    return (tMechanic*) mechanic;
}

void mechanic_sort(tMechanic* mechanic, unsigned int numMechanic) {
    bool haTroca = true;
    int i;
    int j = -1;
    int nMechanic = (int) numMechanic;
    tMechanic exchange;
    while ((j < (nMechanic) && haTroca)) {
        j++;
        if ((nMechanic - j - 1) > 0) {
            haTroca = false;
            for (i = 0; i < (nMechanic - j - 1); i++) {
                if ((i + 1) < nMechanic) {
                    if (strcmp(mechanic[i].name, mechanic[i + 1].name) > 0) {
                        exchange = (mechanic)[i];
                        (mechanic)[i] = (mechanic)[i + 1];
                        (mechanic)[i + 1] = exchange;
                        haTroca = true;
                    }
                }
            }
        }
    }
}

void ShowAllMechanic(tMechanic *mechanic, int currentNrOfMechanics) {
    unsigned int i;
    printf("\n\nMecanicos:\n");
    for (i = 0; i < currentNrOfMechanics; i++) {
        ShowMechanic(mechanic, i);
    }
}

void ShowMechanic(tMechanic *mechanic, unsigned int i) {
    printf("\nNumero: %d", mechanic[i].nr);
    printf("\nNome: %s", mechanic[i].name);
    printf("\nData Nascimento: %hu/%hu/%hu", mechanic[i].dateOfBirth.day, mechanic[i].dateOfBirth.month, mechanic[i].dateOfBirth.year);
    printf("\nEspecialidade: ");
    ConvertSpecialityNrToText(mechanic[i].speciality);
    printf("\n");
}

void ListMechanicEditFields() {
    printf("\n0 - Nome");
    printf("\n1 - Data de Nascimento");
    printf("\n2 - Especialidade");
    printf("\n3 - Turnos");
}

short unsigned int *CheckGarageAvaiableForMechanic(short unsigned int mechanicSpeciality,
        tGarage *garage, short unsigned int currentNrOfGarages, short unsigned int *nrOfGaragesAvaiable) {
    short unsigned int i;
    short unsigned int *avaiableGarageNrs = NULL;
    short unsigned int occurencesNr = 0;
    for (i = 0; i < currentNrOfGarages; i++) {
        if (garage[i].speciality == mechanicSpeciality) {
            occurencesNr++;
            avaiableGarageNrs = (short unsigned int*) realloc(avaiableGarageNrs, sizeof (short unsigned int) * occurencesNr);
            avaiableGarageNrs[occurencesNr - 1] = i;
        }
    }
    *nrOfGaragesAvaiable = occurencesNr;
    return avaiableGarageNrs;
}

tMechanic *ShiftMenu(tMechanic *mechanic, unsigned int currentNrOfMechanics,
        unsigned int mechanicNrToGiveShift, tGarage *garage, short unsigned int currentNrOfGarages) {
    char inputOption;
    printf("\n(L) Listar turnos");
    printf("\n(I) Inserir turno");
    printf("\n(A) Apagar turno");
    fgets(&inputOption, 2, stdin);
    ClearBuffer();
    inputOption = tolower(inputOption);
    switch (inputOption) {
        case 'l':
            ListShifs(mechanic[mechanicNrToGiveShift].shift, mechanic->nrOfShifts);
            break;
        case 'i':
            mechanic = GetMechanicShift(mechanic, currentNrOfMechanics, mechanicNrToGiveShift, garage, currentNrOfGarages);
            break;
        case 'a':
            mechanic[mechanicNrToGiveShift].shift = DeleteShift(mechanic[mechanicNrToGiveShift].shift,
                    mechanic[mechanicNrToGiveShift].nrOfShifts);
            break;
    }
    return mechanic;
}

void ListShifs(tSchedule *shift, short unsigned int currentNrOfShifts) {
    short unsigned int i;
    for (i = 0; i < currentNrOfShifts; i++) {
        printf("\nNumero: %hu", i + 1);
        printf("\nOficina: %hu", shift[i].nrOfGarage);
        printf("\nEntrada: %hu:%hu", shift[i].startWork.hour, shift[i].startWork.minute);
        printf("\nSaida: %hu:%hu", shift[i].finishWork.hour, shift[i].finishWork.minute);
    }

}

tSchedule *DeleteShift(tSchedule *shift, short unsigned int currentNrOfShifts) {
    ListShifs(shift, currentNrOfShifts);
    short unsigned int inputShiftToDelete, i;
    bool isValidShift = false;
    do {
        printf("\nInsira o numero do turno a apagar: ");
        scanf("%hu", &inputShiftToDelete);
        if (inputShiftToDelete > 0 && inputShiftToDelete <= currentNrOfShifts) {
            isValidShift = true;
        }
    } while (!isValidShift);
    currentNrOfShifts--;
    for (i = inputShiftToDelete - 1; i < currentNrOfShifts; i++) {
        shift[i] = shift[i - 1];
    }
    shift = (tSchedule*) realloc(shift, sizeof (tSchedule*) * currentNrOfShifts);

    return shift;
}
