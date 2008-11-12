################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../includes/analisador-sintatico/src/AnalisadorSintatico.cpp \
../includes/analisador-sintatico/src/ConteudoHash.cpp \
../includes/analisador-sintatico/src/NoArvoreSintatica.cpp \
../includes/analisador-sintatico/src/TabelaHash.cpp 

OBJS += \
./includes/analisador-sintatico/src/AnalisadorSintatico.o \
./includes/analisador-sintatico/src/ConteudoHash.o \
./includes/analisador-sintatico/src/NoArvoreSintatica.o \
./includes/analisador-sintatico/src/TabelaHash.o 

CPP_DEPS += \
./includes/analisador-sintatico/src/AnalisadorSintatico.d \
./includes/analisador-sintatico/src/ConteudoHash.d \
./includes/analisador-sintatico/src/NoArvoreSintatica.d \
./includes/analisador-sintatico/src/TabelaHash.d 


# Each subdirectory must supply rules for building sources it contributes
includes/analisador-sintatico/src/%.o: ../includes/analisador-sintatico/src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


