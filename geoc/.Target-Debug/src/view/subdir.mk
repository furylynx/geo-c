################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/view/Cachedetail.cpp \
../src/view/Caches.cpp \
../src/view/MainForm.cpp \
../src/view/Overview.cpp \
../src/view/Preferences.cpp 

OBJS += \
./src/view/Cachedetail.o \
./src/view/Caches.o \
./src/view/MainForm.o \
./src/view/Overview.o \
./src/view/Preferences.o 

CPP_DEPS += \
./src/view/Cachedetail.d \
./src/view/Caches.d \
./src/view/MainForm.d \
./src/view/Overview.d \
./src/view/Preferences.d 


# Each subdirectory must supply rules for building sources it contributes
src/view/%.o: ../src/view/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: bada C++ Compiler'
	arm-samsung-nucleuseabi-g++ -D_DEBUG -DSHP -I"C:/bada/2.0.6/Include" -I"C:/Users/John/Documents/git_workspace/geo-c/geoc/inc" -O0 -g -Wall -c -funsigned-char -fshort-wchar -fpic -march=armv7-a -mthumb -mthumb-interwork -mfpu=vfpv3 -mfloat-abi=hard -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	arm-samsung-nucleuseabi-g++ -D_DEBUG -DSHP -I"C:/bada/2.0.6/Include" -I"C:/Users/John/Documents/git_workspace/geo-c/geoc/inc" -O0 -g -Wall -E -funsigned-char -fshort-wchar -fpic -march=armv7-a -mthumb -mthumb-interwork -mfpu=vfpv3 -mfloat-abi=hard -o"C:/Users/John/Documents/bada_workspace/repository/geoc/Target-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '


