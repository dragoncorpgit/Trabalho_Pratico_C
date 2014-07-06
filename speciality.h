#ifndef SPECIALITY_H
#define	SPECIALITY_H
 #include <stdbool.h>

 typedef enum {
    CARS = 0,
    SIMPLE_MOTORCYLES = 1,
    HIGH_CYLINDER_MOTORCYLES  = 2,
    TRUCKS = 3,
    BOATS_MOTOR = 4,
    BOATS_BI_MOTOR = 5
 } enumSpeciality;

 bool IsSpecialityValid (short unsigned int);

#endif	/* SPECIALITY_H */

