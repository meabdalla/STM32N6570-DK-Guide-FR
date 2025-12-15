################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
C:/Users/UE\ FABLAB/Desktop/stm32objetdetec_projet_tutorat/de_base/STM32N6570-DK-Guide-FR-master/STM32N6570-DK-Guide-FR-master/STM32Cube_FW_N6/Drivers/CMSIS/Device/ST/STM32N6xx/Source/Templates/gcc/startup_stm32n657xx_fsbl.s 

C_SRCS += \
../stm32n6xx_hal_uart.c \
../stm32n6xx_hal_uart_ex.c 

OBJS += \
./startup_stm32n657xx_fsbl.o \
./stm32n6xx_hal_uart.o \
./stm32n6xx_hal_uart_ex.o 

S_DEPS += \
./startup_stm32n657xx.d 

C_DEPS += \
./stm32n6xx_hal_uart.d \
./stm32n6xx_hal_uart_ex.d 


# Each subdirectory must supply rules for building sources it contributes
startup_stm32n657xx_fsbl.o: C:/Users/UE\ FABLAB/Desktop/stm32objetdetec_projet_tutorat/de_base/STM32N6570-DK-Guide-FR-master/STM32N6570-DK-Guide-FR-master/STM32Cube_FW_N6/Drivers/CMSIS/Device/ST/STM32N6xx/Source/Templates/gcc/startup_stm32n657xx_fsbl.s subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m55 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"startup_stm32n657xx.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"
%.o %.su %.cyclo: ../%.c subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m55 -std=gnu11 -g3 -DSTM32N657xx -DUSE_FULL_ASSERT -DUSE_FULL_LL_DRIVER -DVECT_TAB_SRAM -DLL_ATON_DUMP_DEBUG_API -DLL_ATON_PLATFORM=LL_ATON_PLAT_STM32N6 -DLL_ATON_OSAL=LL_ATON_OSAL_BARE_METAL -DLL_ATON_RT_MODE=LL_ATON_RT_ASYNC -DLL_ATON_SW_FALLBACK -DLL_ATON_DBG_BUFFER_INFO_EXCLUDED=1 -c -I../../Inc -I../../../../Middlewares/ai-postprocessing-wrapper -I../../../../Middlewares/lib_vision_models_pp/lib_vision_models_pp/Inc -I../../../../Middlewares/AI_Runtime/Npu/ll_aton -I../../../../Middlewares/AI_Runtime/Npu/Devices/STM32N6XX -I../../../../STM32Cube_FW_N6/Drivers/STM32N6xx_HAL_Driver/Inc -I../../../../STM32Cube_FW_N6/Drivers/STM32N6xx_HAL_Driver/Inc/Legacy -I../../../../STM32Cube_FW_N6/Drivers/CMSIS/Device/ST/STM32N6xx/Include -I../../../../STM32Cube_FW_N6/Drivers/CMSIS/Include -I../../../../STM32Cube_FW_N6/Drivers/CMSIS/DSP/Include -I../../../../STM32Cube_FW_N6/Drivers/BSP/Components/Common -I../../../../STM32Cube_FW_N6/Drivers/BSP/STM32N6570-DK -I../../../../Middlewares/Camera_Middleware/ISP_Library/isp/Inc -I../../../../Middlewares/Camera_Middleware/ISP_Library/evision/Inc -I../../../../Middlewares/AI_Runtime/Inc -I../../../../STM32Cube_FW_N6/Utilities/lcd -I../../../../Middlewares/Camera_Middleware -I../../../../STM32Cube_FW_N6/Drivers/BSP/Components/aps256xx -I../../../../Middlewares/Camera_Middleware/sensors -I../../../../Middlewares/Camera_Middleware/sensors/imx335 -I../../../../Middlewares/Camera_Middleware/sensors/vd6g -I../../../../Middlewares/Camera_Middleware/sensors/vd55g1 -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -mcmse -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean--2e-

clean--2e-:
	-$(RM) ./startup_stm32n657xx.d ./startup_stm32n657xx_fsbl.o ./stm32n6xx_hal_uart.cyclo ./stm32n6xx_hal_uart.d ./stm32n6xx_hal_uart.o ./stm32n6xx_hal_uart.su ./stm32n6xx_hal_uart_ex.cyclo ./stm32n6xx_hal_uart_ex.d ./stm32n6xx_hal_uart_ex.o ./stm32n6xx_hal_uart_ex.su

.PHONY: clean--2e-

