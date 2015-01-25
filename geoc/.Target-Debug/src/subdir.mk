################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/GeoC.cpp \
../src/geocEntry.cpp 

OBJS += \
./src/GeoC.o \
./src/geocEntry.o 

CPP_DEPS += \
./src/GeoC.d \
./src/geocEntry.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: bada C++ Compiler'
	arm-samsung-nucleuseabi-g++ -D_DEBUG -DSHP -I"C:/bada/2.0.6/Include" -I"C:/Users/John/Documents/git_workspace/geo-c/geoc/inc" -O0 -g -Wall -c -funsigned-char -fshort-wchar -fpic -march=armv7-a -mthumb -mthumb-interwork -mfpu=vfpv3 -mfloat-abi=hard -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	arm-samsung-nucleuseabi-g++ -D_DEBUG -DSHP -I"C:/bada/2.0.6/Include" -I"C:/Users/John/Documents/git_workspace/geo-c/geoc/inc" -O0 -g -Wall -E -funsigned-char -fshort-wchar -fpic -march=armv7-a -mthumb -mthumb-interwork -mfpu=vfpv3 -mfloat-abi=hard -o"C:/Users/John/Documents/bada_workspace/repository/geoc/Target-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '


