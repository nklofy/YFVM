################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Loader/FileLoader.cpp \
../src/Loader/PckgManager.cpp 

OBJS += \
./src/Loader/FileLoader.o \
./src/Loader/PckgManager.o 

CPP_DEPS += \
./src/Loader/FileLoader.d \
./src/Loader/PckgManager.d 


# Each subdirectory must supply rules for building sources it contributes
src/Loader/%.o: ../src/Loader/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


