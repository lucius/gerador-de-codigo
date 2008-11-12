################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../includes/analisador-lexico/src/AnalisadorLexico.cpp \
../includes/analisador-lexico/src/AutomatoFD.cpp \
../includes/analisador-lexico/src/ErrosExecucao.cpp \
../includes/analisador-lexico/src/LogErros.cpp \
../includes/analisador-lexico/src/TabelaSimbolos.cpp 

OBJS += \
./includes/analisador-lexico/src/AnalisadorLexico.o \
./includes/analisador-lexico/src/AutomatoFD.o \
./includes/analisador-lexico/src/ErrosExecucao.o \
./includes/analisador-lexico/src/LogErros.o \
./includes/analisador-lexico/src/TabelaSimbolos.o 

CPP_DEPS += \
./includes/analisador-lexico/src/AnalisadorLexico.d \
./includes/analisador-lexico/src/AutomatoFD.d \
./includes/analisador-lexico/src/ErrosExecucao.d \
./includes/analisador-lexico/src/LogErros.d \
./includes/analisador-lexico/src/TabelaSimbolos.d 


# Each subdirectory must supply rules for building sources it contributes
includes/analisador-lexico/src/%.o: ../includes/analisador-lexico/src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


