################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/view/CacheDetailsForm.cpp \
../src/view/CacheDetailsOverviewForm.cpp \
../src/view/CachesForm.cpp \
../src/view/MainForm.cpp \
../src/view/OverviewForm.cpp \
../src/view/PreferencesForm.cpp 

OBJS += \
./src/view/CacheDetailsForm.o \
./src/view/CacheDetailsOverviewForm.o \
./src/view/CachesForm.o \
./src/view/MainForm.o \
./src/view/OverviewForm.o \
./src/view/PreferencesForm.o 

CPP_DEPS += \
./src/view/CacheDetailsForm.d \
./src/view/CacheDetailsOverviewForm.d \
./src/view/CachesForm.d \
./src/view/MainForm.d \
./src/view/OverviewForm.d \
./src/view/PreferencesForm.d 


# Each subdirectory must supply rules for building sources it contributes
src/view/%.o: ../src/view/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: bada C++ Compiler'
	arm-samsung-nucleuseabi-g++ -D_DEBUG -DSHP -I"C:/bada/2.0.6/Include" -I"C:/Users/John/Documents/git_workspace/geo-c/geoc/inc" -O0 -g -Wall -c -funsigned-char -fshort-wchar -fpic -march=armv7-a -mthumb -mthumb-interwork -mfpu=vfpv3 -mfloat-abi=hard -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	arm-samsung-nucleuseabi-g++ -D_DEBUG -DSHP -I"C:/bada/2.0.6/Include" -I"C:/Users/John/Documents/git_workspace/geo-c/geoc/inc" -O0 -g -Wall -E -funsigned-char -fshort-wchar -fpic -march=armv7-a -mthumb -mthumb-interwork -mfpu=vfpv3 -mfloat-abi=hard -o"C:/Users/John/Documents/bada_workspace/repository/geoc/Target-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '


