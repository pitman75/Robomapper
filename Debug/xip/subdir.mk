################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../xip/evkmimxrt1010_flexspi_nor_config.c \
../xip/fsl_flexspi_nor_boot.c 

OBJS += \
./xip/evkmimxrt1010_flexspi_nor_config.o \
./xip/fsl_flexspi_nor_boot.o 

C_DEPS += \
./xip/evkmimxrt1010_flexspi_nor_config.d \
./xip/fsl_flexspi_nor_boot.d 


# Each subdirectory must supply rules for building sources it contributes
xip/%.o: ../xip/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_MIMXRT1011DAE5A -DCPU_MIMXRT1011DAE5A_cm7 -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -DXIP_EXTERNAL_FLASH=1 -DXIP_BOOT_HEADER_ENABLE=1 -DSERIAL_PORT_TYPE_UART=1 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"D:\work\Robomapper\FW\Robomapper\board" -I"D:\work\Robomapper\FW\Robomapper\source" -I"D:\work\Robomapper\FW\Robomapper\drivers" -I"D:\work\Robomapper\FW\Robomapper\xip" -I"D:\work\Robomapper\FW\Robomapper\component\serial_manager" -I"D:\work\Robomapper\FW\Robomapper\component\uart" -I"D:\work\Robomapper\FW\Robomapper\utilities" -I"D:\work\Robomapper\FW\Robomapper\component\lists" -I"D:\work\Robomapper\FW\Robomapper\CMSIS" -I"D:\work\Robomapper\FW\Robomapper\device" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m7 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


