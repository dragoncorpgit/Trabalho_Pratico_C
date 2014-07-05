#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/471842843/fromFile.o \
	${OBJECTDIR}/_ext/471842843/toFile.o \
	${OBJECTDIR}/additionalFunctions.o \
	${OBJECTDIR}/date.o \
	${OBJECTDIR}/garage.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/material.o \
	${OBJECTDIR}/mechanic.o \
	${OBJECTDIR}/speciality.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${TESTDIR}/TestFiles/f1

${TESTDIR}/TestFiles/f1: ${OBJECTFILES}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.c} -o ${TESTDIR}/TestFiles/f1 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/471842843/fromFile.o: /home/y2l1/Dropbox/NetBeansProjects/Projects_C/Trabalho_Pratico_C/fromFile.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/471842843
	${RM} "$@.d"
	$(COMPILE.c) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/471842843/fromFile.o /home/y2l1/Dropbox/NetBeansProjects/Projects_C/Trabalho_Pratico_C/fromFile.c

${OBJECTDIR}/_ext/471842843/toFile.o: /home/y2l1/Dropbox/NetBeansProjects/Projects_C/Trabalho_Pratico_C/toFile.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/471842843
	${RM} "$@.d"
	$(COMPILE.c) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/471842843/toFile.o /home/y2l1/Dropbox/NetBeansProjects/Projects_C/Trabalho_Pratico_C/toFile.c

${OBJECTDIR}/additionalFunctions.o: additionalFunctions.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/additionalFunctions.o additionalFunctions.c

${OBJECTDIR}/date.o: date.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/date.o date.c

${OBJECTDIR}/garage.o: garage.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/garage.o garage.c

${OBJECTDIR}/main.o: main.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.c

${OBJECTDIR}/material.o: material.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/material.o material.c

${OBJECTDIR}/mechanic.o: mechanic.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/mechanic.o mechanic.c

${OBJECTDIR}/speciality.o: speciality.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/speciality.o speciality.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${TESTDIR}/TestFiles/f1

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
