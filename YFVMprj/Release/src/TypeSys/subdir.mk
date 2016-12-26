################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/TypeSys/RcdFunc.cpp \
../src/TypeSys/RcdObj.cpp \
../src/TypeSys/RcdType.cpp \
../src/TypeSys/RcdVal.cpp 

OBJS += \
./src/TypeSys/RcdFunc.o \
./src/TypeSys/RcdObj.o \
./src/TypeSys/RcdType.o \
./src/TypeSys/RcdVal.o 

CPP_DEPS += \
./src/TypeSys/RcdFunc.d \
./src/TypeSys/RcdObj.d \
./src/TypeSys/RcdType.d \
./src/TypeSys/RcdVal.d 


# Each subdirectory must supply rules for building sources it contributes
src/TypeSys/%.o: ../src/TypeSys/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


