(cd na directoria do projeto)
mkdir -p build/Debug/GNU-Linux-x86
rm -f "build/Debug/GNU-Linux-x86/additionalFunctions.o.d"
gcc    -c -g -MMD -MP -MF "build/Debug/GNU-Linux-x86/additionalFunctions.o.d" -o build/Debug/GNU-Linux-x86/additionalFunctions.o additionalFunctions.c

rm -f "build/Debug/GNU-Linux-x86/date.o.d"
gcc    -c -g -MMD -MP -MF "build/Debug/GNU-Linux-x86/date.o.d" -o build/Debug/GNU-Linux-x86/date.o date.c

rm -f "build/Debug/GNU-Linux-x86/fromFile.o.d"
gcc    -c -g -MMD -MP -MF "build/Debug/GNU-Linux-x86/fromFile.o.d" -o build/Debug/GNU-Linux-x86/fromFile.o fromFile.c

rm -f "build/Debug/GNU-Linux-x86/garage.o.d"
gcc    -c -g -MMD -MP -MF "build/Debug/GNU-Linux-x86/garage.o.d" -o build/Debug/GNU-Linux-x86/garage.o garage.c


rm -f "build/Debug/GNU-Linux-x86/main.o.d"
gcc    -c -g -MMD -MP -MF "build/Debug/GNU-Linux-x86/main.o.d" -o build/Debug/GNU-Linux-x86/main.o main.c

rm -f "build/Debug/GNU-Linux-x86/toFile.o.d"
gcc    -c -g -MMD -MP -MF "build/Debug/GNU-Linux-x86/toFile.o.d" -o build/Debug/GNU-Linux-x86/toFile.o toFile.c

rm -f "build/Debug/GNU-Linux-x86/material.o.d"
gcc    -c -g -MMD -MP -MF "build/Debug/GNU-Linux-x86/material.o.d" -o build/Debug/GNU-Linux-x86/material.o material.c


rm -f "build/Debug/GNU-Linux-x86/mechanic.o.d"
gcc    -c -g -MMD -MP -MF "build/Debug/GNU-Linux-x86/mechanic.o.d" -o build/Debug/GNU-Linux-x86/mechanic.o mechanic.c

rm -f "build/Debug/GNU-Linux-x86/speciality.o.d"
gcc    -c -g -MMD -MP -MF "build/Debug/GNU-Linux-x86/speciality.o.d" -o build/Debug/GNU-Linux-x86/speciality.o speciality.c


gcc     -o dist/Debug/GNU-Linux-x86/fix_project build/Debug/GNU-Linux-x86/additionalFunctions.o build/Debug/GNU-Linux-x86/date.o build/Debug/GNU-Linux-x86/fromFile.o build/Debug/GNU-Linux-x86/garage.o build/Debug/GNU-Linux-x86/main.o build/Debug/GNU-Linux-x86/material.o build/Debug/GNU-Linux-x86/mechanic.o build/Debug/GNU-Linux-x86/speciality.o build/Debug/GNU-Linux-x86/toFile.o 
