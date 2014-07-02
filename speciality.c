typedef enum {
    CARS = 0,
    SIMPLE_MOTORCYLES = 1,
    HIGH_CYLINDER_MOTORCYLES  = 2,
    TRUCKS = 3,
    BOATS_MOTOR = 4,
    BOATS_BI_MOTOR = 5
} enumSpeciality;

bool IsSpecialityValid (unsigned short int inputSpeciality) {
    if (inputSpeciality < 0 || inputSpeciality > 5){
        printf("Especialidade inválido, insira corretamente");
        return false;
    }else {
        return true;
    }
}
