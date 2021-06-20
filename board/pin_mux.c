/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v9.0
processor: MIMXRT1011xxxxx
package_id: MIMXRT1011DAE5A
mcu_data: ksdk2_0
processor_version: 9.0.1
board: MIMXRT1010-EVK
pin_labels:
- {pin_num: '3', pin_signal: GPIO_09, label: UART1_RXD, identifier: UART1_RXD}
- {pin_num: '2', pin_signal: GPIO_10, label: UART1_TXD, identifier: UART1_TXD}
- {pin_num: '65', pin_signal: GPIO_SD_10, label: FlexSPI_CLK, identifier: FlexSPI_CLK}
- {pin_num: '66', pin_signal: GPIO_SD_09, label: FlexSPI_D0_A, identifier: FlexSPI_D0_A}
- {pin_num: '68', pin_signal: GPIO_SD_07, label: FlexSPI_D1_A, identifier: FlexSPI_D1_A}
- {pin_num: '67', pin_signal: GPIO_SD_08, label: FlexSPI_D2_A, identifier: FlexSPI_D2_A}
- {pin_num: '64', pin_signal: GPIO_SD_11, label: FlexSPI_D3_A, identifier: FlexSPI_D3_A}
- {pin_num: '69', pin_signal: GPIO_SD_06, label: FlexSPI_SS0, identifier: FlexSPI_SS0}
- {pin_num: '1', pin_signal: GPIO_11, label: GPIO_11, identifier: GPIO_11;LED}
- {pin_num: '11', pin_signal: GPIO_02, label: 'I2C1_SCL/U10[17]/J57[20]/U26[4]', identifier: I2C1_SCL;INT1B}
- {pin_num: '12', pin_signal: GPIO_01, label: 'I2C1_SDA/U10[18]/J57[18]/U26[6]', identifier: I2C1_SDA;INT2B}
- {pin_num: '9', pin_signal: GPIO_04, label: 'SAI1_TXD0/U10[14]', identifier: SAI1_TXD0;INT1A}
- {pin_num: '4', pin_signal: GPIO_08, label: 'SAI1_MCLK/U10[11]', identifier: SAI1_MCLK;INT2A}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

#include "fsl_common.h"
#include "fsl_iomuxc.h"
#include "fsl_gpio.h"
#include "pin_mux.h"

/* FUNCTION ************************************************************************************************************
 * 
 * Function Name : BOARD_InitBootPins
 * Description   : Calls initialization functions.
 * 
 * END ****************************************************************************************************************/
void BOARD_InitBootPins(void) {
    BOARD_InitPins();
    BOARD_InitDEBUG_UARTPins();
}

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'true', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '1', peripheral: GPIO1, signal: 'gpiomux_io, 11', pin_signal: GPIO_11, identifier: LED, direction: OUTPUT}
  - {pin_num: '9', peripheral: GPIO1, signal: 'gpiomux_io, 04', pin_signal: GPIO_04, identifier: INT1A, direction: OUTPUT}
  - {pin_num: '11', peripheral: GPIO1, signal: 'gpiomux_io, 02', pin_signal: GPIO_02, identifier: INT1B, direction: OUTPUT}
  - {pin_num: '4', peripheral: GPIO1, signal: 'gpiomux_io, 08', pin_signal: GPIO_08, identifier: INT2A, direction: OUTPUT}
  - {pin_num: '12', peripheral: GPIO1, signal: 'gpiomux_io, 01', pin_signal: GPIO_01, identifier: INT2B, direction: OUTPUT}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitPins(void) {
  CLOCK_EnableClock(kCLOCK_Iomuxc);           

  /* GPIO configuration of INT2B on GPIO_01 (pin 12) */
  gpio_pin_config_t INT2B_config = {
      .direction = kGPIO_DigitalOutput,
      .outputLogic = 0U,
      .interruptMode = kGPIO_NoIntmode
  };
  /* Initialize GPIO functionality on GPIO_01 (pin 12) */
  GPIO_PinInit(GPIO1, 1U, &INT2B_config);

  /* GPIO configuration of INT1B on GPIO_02 (pin 11) */
  gpio_pin_config_t INT1B_config = {
      .direction = kGPIO_DigitalOutput,
      .outputLogic = 0U,
      .interruptMode = kGPIO_NoIntmode
  };
  /* Initialize GPIO functionality on GPIO_02 (pin 11) */
  GPIO_PinInit(GPIO1, 2U, &INT1B_config);

  /* GPIO configuration of INT1A on GPIO_04 (pin 9) */
  gpio_pin_config_t INT1A_config = {
      .direction = kGPIO_DigitalOutput,
      .outputLogic = 0U,
      .interruptMode = kGPIO_NoIntmode
  };
  /* Initialize GPIO functionality on GPIO_04 (pin 9) */
  GPIO_PinInit(GPIO1, 4U, &INT1A_config);

  /* GPIO configuration of INT2A on GPIO_08 (pin 4) */
  gpio_pin_config_t INT2A_config = {
      .direction = kGPIO_DigitalOutput,
      .outputLogic = 0U,
      .interruptMode = kGPIO_NoIntmode
  };
  /* Initialize GPIO functionality on GPIO_08 (pin 4) */
  GPIO_PinInit(GPIO1, 8U, &INT2A_config);

  /* GPIO configuration of LED on GPIO_11 (pin 1) */
  gpio_pin_config_t LED_config = {
      .direction = kGPIO_DigitalOutput,
      .outputLogic = 0U,
      .interruptMode = kGPIO_NoIntmode
  };
  /* Initialize GPIO functionality on GPIO_11 (pin 1) */
  GPIO_PinInit(GPIO1, 11U, &LED_config);

  IOMUXC_SetPinMux(IOMUXC_GPIO_01_GPIOMUX_IO01, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_02_GPIOMUX_IO02, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_04_GPIOMUX_IO04, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_08_GPIOMUX_IO08, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_11_GPIOMUX_IO11, 0U); 
  IOMUXC_GPR->GPR26 = ((IOMUXC_GPR->GPR26 &
    (~(BOARD_INITPINS_IOMUXC_GPR_GPR26_GPIO_SEL_MASK))) 
      | IOMUXC_GPR_GPR26_GPIO_SEL(0x00U)      
    );
}


/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitDEBUG_UARTPins:
- options: {callFromInitBoot: 'true', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '3', peripheral: LPUART1, signal: RXD, pin_signal: GPIO_09}
  - {pin_num: '2', peripheral: LPUART1, signal: TXD, pin_signal: GPIO_10}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitDEBUG_UARTPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitDEBUG_UARTPins(void) {
  CLOCK_EnableClock(kCLOCK_Iomuxc);           

  IOMUXC_SetPinMux(IOMUXC_GPIO_09_LPUART1_RXD, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_10_LPUART1_TXD, 0U); 
}


/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitQSPIPins:
- options: {coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '65', peripheral: FLEXSPI, signal: FLEXSPI_A_SCLK, pin_signal: GPIO_SD_10}
  - {pin_num: '66', peripheral: FLEXSPI, signal: FLEXSPI_A_DATA0, pin_signal: GPIO_SD_09}
  - {pin_num: '68', peripheral: FLEXSPI, signal: FLEXSPI_A_DATA1, pin_signal: GPIO_SD_07}
  - {pin_num: '67', peripheral: FLEXSPI, signal: FLEXSPI_A_DATA2, pin_signal: GPIO_SD_08}
  - {pin_num: '64', peripheral: FLEXSPI, signal: FLEXSPI_A_DATA3, pin_signal: GPIO_SD_11}
  - {pin_num: '69', peripheral: FLEXSPI, signal: FLEXSPI_A_SS0_B, pin_signal: GPIO_SD_06}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitQSPIPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitQSPIPins(void) {
  CLOCK_EnableClock(kCLOCK_Iomuxc);           

  IOMUXC_SetPinMux(IOMUXC_GPIO_SD_06_FLEXSPI_A_SS0_B, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_SD_07_FLEXSPI_A_DATA1, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_SD_08_FLEXSPI_A_DATA2, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_SD_09_FLEXSPI_A_DATA0, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_SD_10_FLEXSPI_A_SCLK, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_SD_11_FLEXSPI_A_DATA3, 0U); 
}

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/