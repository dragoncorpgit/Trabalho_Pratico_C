#include "speciality.h"

bool IsSpecialityValid (unsigned short int inputSpeciality) {
    if (inputSpeciality < 0 || inputSpeciality > 5){
        printf("Especialidade inválido, insira corretamente");
        return false;
    }else {
        return true;
    }
}
