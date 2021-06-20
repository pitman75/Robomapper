/*
 * Copyright 2016-2021 NXP
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file    Robomapper.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MIMXRT1011.h"
#include "fsl_debug_console.h"
/* TODO: insert other include files here. */

/* TODO: insert other definitions and declarations here. */

#define test_move_time  (10)

#define INT1A_HIGH()     GPIO_PortSet(BOARD_INITPINS_INT1A_PERIPHERAL, (1 << BOARD_INITPINS_INT1A_CHANNEL))
#define INT1B_HIGH()     GPIO_PortSet(BOARD_INITPINS_INT1B_PERIPHERAL, (1 << BOARD_INITPINS_INT1B_CHANNEL))
#define INT1A_LOW()      GPIO_PortClear(BOARD_INITPINS_INT1A_PERIPHERAL, (1 << BOARD_INITPINS_INT1A_CHANNEL))
#define INT1B_LOW()      GPIO_PortClear(BOARD_INITPINS_INT1B_PERIPHERAL, (1 << BOARD_INITPINS_INT1B_CHANNEL))

#define INT2A_HIGH()     GPIO_PortSet(BOARD_INITPINS_INT2A_PERIPHERAL, (1 << BOARD_INITPINS_INT2A_CHANNEL))
#define INT2B_HIGH()     GPIO_PortSet(BOARD_INITPINS_INT2B_PERIPHERAL, (1 << BOARD_INITPINS_INT2B_CHANNEL))
#define INT2A_LOW()      GPIO_PortClear(BOARD_INITPINS_INT2A_PERIPHERAL, (1 << BOARD_INITPINS_INT2A_CHANNEL))
#define INT2B_LOW()      GPIO_PortClear(BOARD_INITPINS_INT2B_PERIPHERAL, (1 << BOARD_INITPINS_INT2B_CHANNEL))

uint32_t tick_half_seconds_cnt = 0;



void LED_IRQ(void)
{
	uint32_t flags;

	flags = PIT_GetStatusFlags(PIT_PERIPHERAL, kPIT_Chnl_0);
	PIT_ClearStatusFlags(PIT_PERIPHERAL, kPIT_Chnl_0, flags);
	PIT_GetStatusFlags(PIT_PERIPHERAL, kPIT_Chnl_0);

	GPIO_PortToggle(BOARD_INITPINS_LED_PERIPHERAL, (1U << BOARD_INITPINS_LED_CHANNEL));
	tick_half_seconds_cnt++;
}

/*
 * @brief   Application entry point.
 */
int main(void) {

	uint32_t lc_timeticks = 0;
	uint8_t test_state = 0;

    /* Init board hardware. */
    BOARD_ConfigMPU();
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
    /* Init FSL debug console. */
    BOARD_InitDebugConsole();
#endif

    PRINTF("Hello World\n");

    /* Enter an infinite loop, just incrementing a counter. */
    while(1) {
    	switch (test_state)
		{
    	case 0:
    		/* Move */
    		if (lc_timeticks > tick_half_seconds_cnt) { break; }
    		INT1A_HIGH();
    		INT1B_LOW();

    		INT2A_HIGH();
    		INT2B_LOW();
    		lc_timeticks = tick_half_seconds_cnt + test_move_time;
    		test_state = 1;
    		break;

    	case 1:
    		/* Stop */
    		if (lc_timeticks > tick_half_seconds_cnt) { break; }
    		INT1A_LOW();
    		INT1B_LOW();

    		INT2A_LOW();
    		INT2B_LOW();
    		lc_timeticks = tick_half_seconds_cnt + 2;
    		test_state = 2;
    		break;

    	case 2:
    		/* Move */
    		if (lc_timeticks > tick_half_seconds_cnt) { break; }
    		INT1A_LOW();
    		INT1B_HIGH();

    		INT2A_LOW();
    		INT2B_HIGH();
    		lc_timeticks = tick_half_seconds_cnt + test_move_time;
    		test_state = 3;
    		break;

    	case 3:
    		/* Stop */
    		if (lc_timeticks > tick_half_seconds_cnt) { break; }
    		INT1A_LOW();
    		INT1B_LOW();

    		INT2A_LOW();
    		INT2B_LOW();
    		lc_timeticks = tick_half_seconds_cnt + 2;
    		test_state = 4;
    		break;

    	case 4:
    		/* Rotate */
    		if (lc_timeticks > tick_half_seconds_cnt) { break; }
    		INT1A_HIGH();
    		INT1B_LOW();

    		INT2A_LOW();
    		INT2B_HIGH();
    		lc_timeticks = tick_half_seconds_cnt + test_move_time;
    		test_state = 5;
    		break;

    	case 5:
    		/* Stop */
    		if (lc_timeticks > tick_half_seconds_cnt) { break; }
    		INT1A_LOW();
    		INT1B_LOW();

    		INT2A_LOW();
    		INT2B_LOW();
    		lc_timeticks = tick_half_seconds_cnt + 2;
    		test_state = 6;
    		break;

    	case 6:
    	    /* Rotate */
    		if (lc_timeticks > tick_half_seconds_cnt) { break; }
    	    INT1A_LOW();
    	    INT1B_HIGH();

    	    INT2A_HIGH();
    	    INT2B_LOW();
    	    lc_timeticks = tick_half_seconds_cnt + test_move_time;
    	    test_state = 7;
    	    break;

    	case 7:
    	    /* Stop */
    		if (lc_timeticks > tick_half_seconds_cnt) { break; }
    	    INT1A_LOW();
    	    INT1B_LOW();

    	    INT2A_LOW();
    	    INT2B_LOW();
    	    lc_timeticks = tick_half_seconds_cnt + 2;
    	    test_state = 0;
    	    break;
		}
    }
    return 0 ;
}
