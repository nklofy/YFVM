################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Interpreter/Interpreter.cpp 

OBJS += \
./src/Interpreter/Interpreter.o 

CPP_DEPS += \
./src/Interpreter/Interpreter.d 


# Each subdirectory must supply rules for building sources it contributes
src/Interpreter/%.o: ../src/Interpreter/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


