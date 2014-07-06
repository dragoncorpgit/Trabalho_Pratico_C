#include "speciality.h"
#include <stdio.h>

bool IsSpecialityValid (short unsigned int inputSpeciality) {
    if (inputSpeciality < 0 || inputSpeciality > 5){
        printf("Especialidade inválido, insira corretamente");
        return false;
    }else {
        return true;
    }
}
