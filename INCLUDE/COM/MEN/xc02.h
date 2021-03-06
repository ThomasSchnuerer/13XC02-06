/***********************  I n c l u d e  -  F i l e  ************************/
/*!  
 *        \file  xc02.h
 *
 *      \author  thomas.schnuerer@men.de
 * 
 *  	 \brief  Header file for XC02 MEN DC board controller 
 *                      
 *     Switches: -
 */
/*
 *---------------------------------------------------------------------------
 * Copyright 2006-2019, MEN Mikro Elektronik GmbH
 ****************************************************************************/
/*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _XC02_H
#define _XC02_H

#ifdef __cplusplus
	extern "C" {
#endif


/*--------------------------------------+
|   DEFINES                             |
+--------------------------------------*/

/*! \defgroup _XC02 PIC Firmware Register defines (cmd+byte access) */
/**@{*/
#define XC02C_FLAG			0x01	/**< common flag */
 
#define XC02C_WOT_L			0x00	/**< WOT [min] - low byte (r/w) */
#define XC02C_WOT_H			0x01	/**< WOT [min] - high byte (r/w) */
#define XC02C_ONACK			0x02	/**< ON acknowledge (w) */
#define XC02C_ONACK_TOUT	0x03	/**< ON acknowledge timeout (r/w) */
#define XC02C_ONACK_ERR		0x04	/**< ON acknowledge error count (r) */

#define XC02C_WDOG_STATE	0x05	/**< watchdog state (r/w) */
# define XC02C_WDOG_OFF		0x00	/**< watchdog OFF */
# define XC02C_WDOG_ON		0x01	/**< watchdog ON */

#define XC02C_WDOG_TRIG		0x06	/**< watchdog trigger (w) */
#define XC02C_WDOG_TOUT		0x07	/**< WDOG timeout [100ms] (r/w) */

# define XC02C_WDOG_TOUT_MINMODE	0x01	/**< 100ms   */
# define XC02C_WDOG_TOUT_MAXMODE	0xff	/**< 25,5sec */

#define XC02C_WDOG_ERR		0x08	/**< WDOG error count (r) */
#define XC02C_SWOFF			0x09	/**< initiate a power down (w) */
#define XC02C_OFFACK		0x0a	/**< OFF acknowledge (w) */
#define XC02C_DOWN_DELAY	0x0b	/**< shutdown delay (r/w) */
#define XC02C_OFF_DELAY		0x0c	/**< off delay (r/w) */

#define XC02C_STATUS		0x0d	/**< PSU status flags (r) */
# define XC02C_STATUS_DOWN_EVT	0x01	/**< Shutdown Event flag */
# define XC02C_STATUS_PROTECT	0x02	/**< display in protect state flag */

#define XC02C_IN			0x0e	/**< binary inputs state (r) */

#define XC02C_TEMP			0x12	/**< temp [ADC-Value] (r) */

#define XC02C_TEMP_HIGH		0x13	/**< temp high limit [ADC-Value] (r/w) */

#define XC02C_VOLT			0x14	/**< 12V supply voltage [ADC-Value] (r) */

#define XC02C_SET_BR		0x17	/**< set brightness to level 0x0..0xc8*/
#define XC02C_TEMP_LOW		0x18	/**< temp low limit [ADC-Value] (r/w) */

#define XC02C_BR_SRC		0x19	/**< Brightness control source */
#define XC02C_SW_DISP		0x20	/**< switch display on/off (r/w)*/

#define XC02C_VOLT_HIGH		0x21	/**< volt high limit [ADC-Value] (r/w) */
#define XC02C_VOLT_LOW		0x22	/**< volt low limit [ADC-Value] (r/w) */
#define XC02C_INIT_DS		0x25	/**< initial display State (r/w) */
#define XC02C_TIMESTAMP		0x2a	/**< readout EEPROM timestamp string (r) */

/* R01 specific defines */
#define XC02C_SW_MINICARD   0x2b	/**< DC1 R01: minicard slot power (r/w) */
#define XC02C_SET_BR_2		0x2c	/**< set 2nd brightness to 0x0-0xc8 (r/w) */

#define XC02C_INIT_BR1		0x2d	/**< initial brightness disp.1  (r/w) */
#define XC02C_INIT_BR2		0x2e	/**< initial brightness disp.2  (r/w) */

#define XC02C_AUTO_BR_FAK	0x30	/**< multiplier for auto brightness (r/w) */
#define XC02C_AUTO_BR_OFFS  0x31    /**< offset for brightness input (r/w)*/

/* SC21-xx specific defines */
#define SC21C_BL_CURR		0x32	/**< BL current (SC21 only) (r) 		 */
#define SC21C_BR_DIR		0x33	/**< autobright direct. (r/w) 0: default */
#define SC21C_BR_RAW		0x34	/**< raw ADRESH value from photo diode   */

/* new SC21R01 functions */
#define SC21C_USER_LED		0x35	/**< switch 2 free User LEDs  */
#define SC21C_KEY_CTRL		0x36	/**< if 0: KEY_IN switches SC21, if 1: always on 	*/


#define XC02C_TEST1_NOTEST	0x00	/**< no test mode (default) */
#define XC02C_TEST1_TMODE1	0x61	/**< enable test mode 1:
									   - reset redirected to XC02C_TEST2_RST flag
									   - power-on redirected to XC02C_TEST2_PWR flag */

#define XC02C_TEST1			0x77	/**< test register #1 (r/w) */
#define XC02C_TEST2			0x78	/**< test register #2 (r/w) */
#define XC02C_TEST2_RST		0x01	/**< 1: indicate reset, cleared by host */
#define XC02C_TEST2_SWON	0x02	/**< 1: signal imediate WOT, clear by uC */

#define XC02C_TEST3			0x79	/**< test register #3 (r) */
# define XC02C_TEST3_PWR	0x01	/**< 1: indicating power-on */

#define XC02C_TEST4			0x7a	/**< testreg#4(r) = XC02_SM_STATES */

#define XC02C_ID			0xfe	/**< identification byte '0xc2' (r) */ 
#define XC02C_REV			0xff	/**< firmware revision (r) */ 

#define XC02_FIRMWARE_ID	0xc2


/**
 * @defgroup _XC02_DOWN_DELAY Shutdown Delay defines
 * Possible modes:
 * \code
   Mode        :   0  | 1 | 2 |  3 | 4 |  5 |  6 |  7 
   Delay [min] : none | 1 | 2 |  4 | 8 | 16 | 32 | 64 
   \endcode
 * @{ */
/** macro to convert mode to delay [min] */
#	define XC02C_DOWN_DELAY_MIN( mode )		((mode) ? (1<<((mode)-1)) : 0)

#	define XC02C_DOWN_DELAY_MINMODE		0
#	define XC02C_DOWN_DELAY_MAXMODE		7
/** @} */

#define XC02_SMB_HIGH_LIMIT_ON_ACK     0x0b /**< Maxmode val for ON-Ack */
#define XC02_SMB_HIGH_LIMIT_DOWN_DELAY 0x07 /**< Maxmode val for Down-Delay  */
#define XC02_SMB_HIGH_LIMIT_OFF_DELAY  0x05 /**< Max mode val for Off-Delay */

/**
 * @defgroup _XC02_OFF_DELAY OFF Delay defines
 * Possible modes:
 * \code
   Mode        :   0  | 1 | 2 | 3 | 4 |  5
   Delay [min] : none | 1 | 2 | 4 | 8 | 16
   \endcode
 * @{ */
/** macro to convert mode to delay [min] */
#	define XC02C_OFF_DELAY_MIN( mode )		((mode) ? (1<<((mode)-1)) : 0)

#	define XC02C_OD_MINMODE	0
#	define XC02C_OD_MAXMODE	5
/** @} */


#define XC02C_ON_ACK_MAX_ERR   5  /**< Max num of tries to reset system 
                                       after ON-Ack was not received in time */

#define XC02C_WDOG_MAX_ERR     5  /**< Max. number of attempts to reset system 
                                       after WDOG-Trigger was not received 
                                       in time */
#define XC02C_WAIT_OFF      1000 /**< Time in ms to ensure proper power-off */

/**
 * @defgroup XC02_DEFAULTS Default Values programmed to EEPROM at startup
 * \n
 * When a completely new DC is powered up, the firmware detects the EEPROM
 * is empty and programs default values to the EEPROM which are defined below:
 * @{ */
#define XC02_DEFAULT_NOM_TEMP	0x30 /**< first initial temp value */
#define XC02_DEFAULT_BCON_SRC   0x00 /**< Display brightness control source */
#define XC02_DEFAULT_DISP_STAT  0x03 /**< Display powerup state */
#define XC02_DEFAULT_PWM 		0x80 /**< brightness */
#define XC02_DEFAULT_BRIGHTNESS 0x64 /**< initial display brightness */

#define VOLT_TRESH	   			0x02  /**< voltage threshold */
#define TEMP_TRESH				0x03  /**< temperature threshold */


/** default wide Volt/Temp ranges, are overwritten at 1st MDIS M_open call */
#define	XC02C_TEMP_MIN	(TEMP_TRESH+1)
#define	XC02C_TEMP_MAX	(0xff-TEMP_TRESH)
#define	XC02C_VOLT_MIN	(VOLT_TRESH+1)
#define	XC02C_VOLT_MAX	(0xff-VOLT_TRESH)
/** @} */


/*--------------------------------------*/
/*	TYPEDEFS		            		*/
/*--------------------------------------*/

/** States in which the firmware can be */
typedef enum {
	SM_STATE_OFF,       /**< Power OFF: Wait for ON-Event 					 */
	SM_STATE_WAIT_SOA, 	/**< Power ON: Wait for ON-Ack (no further use) 	 */
	SM_STATE_ON,        /**< Power ON: Wait for OFF-Event, handle WDOG 		 */
	SM_STATE_WAIT_SD,	/**< Power ON: Wait for SD-Time 					 */
	SM_STATE_WAIT_OD,  	/**< Power ON: Wait for OFF-Delay-Time 				 */
	SM_STATE_WAIT_OFF,  /**< Power OFF: Wait defined time to proper poweroff */
	SM_STATE_ERROR_OFF, /**< Power OFF: Error OFF state, never left (severe) */
	SM_STATE_DISP_PROT  /**< Power ON: BL off due to temp/vold range exceed */
} XC02C_SM_STATES;

/**@}*/

#ifdef __cplusplus
	}
#endif

#endif	/* _XC02_H */
