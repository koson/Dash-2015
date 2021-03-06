	/*
 * revolve_can_definitions.h
 *
 * Created: 20.01.2013 18:47:51
 *  Author: Bruker
 */ 


#ifndef REVOLVE_CAN_DEFINITIONS_H_
#define REVOLVE_CAN_DEFINITIONS_H_

//ID
//Module ID
//Bytemapping

//------------------------------------------------------------------------------
// EXAMPLE: function = command, group = dash, module ID = 0
/* .id = CANR_FCN_CMD_ID | CANR_GRP_DASH_ID | CANR_MODULE_ID0 */
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/*	-------	ARBITRATION ID DEFINITIONS ---------------------------------------*/
//------------------------------------------------------------------------------

//- ID[10..8]
#define CANR_FCN_PRI_ID				0x000		// Most significant
#define CANR_FCN_BOOT_ID			0x200		// Priority data
#define CANR_FCN_CMD_ID				0x400		// Module_id control
#define CANR_FCN_DATA_ID			0x600		// Data

//- ID[7..3]
#define CANR_GRP_SENS_ROTARY_ID		0x10		// Torque and steering encoder
#define CANR_GRP_SENS_BRK_ID		0x18		// Brake encoder
#define CANR_GRP_SENS_SPEED_ID		0x20		// Wheel speed
#define CANR_GRP_BMS_ID				0x28		// BMS-data
#define CANR_GRP_ECU_ID				0x30		// ECU
#define CANR_GRP_INVERTER_ID		0x38		// Inverter data
#define CANR_GRP_SUSP_ID			0x40		// Suspension
#define CANR_GRP_SENS_IMU_ID		0x48		// IMU master
#define CANR_GRP_SENS_DAMPER_ID		0x50		// Damper position
#define CANR_GRP_SENS_TEMP_ID		0x56		// Gearbox and water temp
#define CANR_GRP_SENS_GLVBMS_ID		0x58		// GLV BMS
#define CANR_GRP_DASH_ID			0x60		// Dashboard
#define CANR_GRP_SENS_BSPD_ID	 	0x68		// BSPD
#define CANR_GRP_SENS_IMD_ID		0x70		// Laptimer
#define CANR_GRP_TELEMETRY_ID		0x78		// Telemetry
#define CANR_GRP_FAN_CTRL_ID		0x80		// Fan control
//#define CANR_GRP_					0x88		// 
//#define CANR_GRP_					0x90		// 

//- ID[2..0]
#define CANR_MODULE_ID0_ID			0x0
#define CANR_MODULE_ID1_ID			0x1
#define CANR_MODULE_ID2_ID			0x2
#define CANR_MODULE_ID3_ID			0x3
#define CANR_MODULE_ID4_ID			0x4
#define CANR_MODULE_ID5_ID			0x5
#define CANR_MODULE_ID6_ID			0x6
#define CANR_MODULE_ID7_ID			0x7


//------------------------------------------------------------------------------
/*	-------	MASKS ---------------------------------------------------------*/
//------------------------------------------------------------------------------
/*MASK function:
	ID = ID in CAN controller filter
	MASK = Mask in CAN controller filter
	ID_msg = ID from incoming message
	
	Accept = (ID xor ID_msg) | (~MASK);
	if(Accept == 0xFF)  Message recieved
	else				Message rejected
*/

//Mask for recieving one group specifically,
//Group together to add more messages
//High bit means bit is significant in ID_ext
#define MASK_RECIEVE_FCN		(0x600)
#define MASK_RECIEVE_GRP		(0x1F8)
#define MASK_RECIEVE_MODULE		(0x007)
#define MASK_RECIEVE_ALL		(MASK_RECIEVE_FCN|MASK_RECIEVE_GRP|MASK_RECIEVE_MODULE)


//------------------------------------------------------------------------------
/*	-------	ALIVE	 ---------------------------------------------------------*/
//------------------------------------------------------------------------------

// ---------------------------------------------------------------------//
// Functionality description:											//
// Each module sends out a message with the following properties:		//
// ID = CANR_FCN_DATA_ID | CANR_GRP_DASH_ID	| CANR_MODULE_ID7_ID		//
// DATA[0] = MODULE ID													//
// Frequency = 1 Hz														//
// ---------------------------------------------------------------------//

//-ALIVE ID
#define CAN_ALIVE_MSG_ID			(CANR_FCN_DATA_ID	|CANR_GRP_DASH_ID|CANR_MODULE_ID7_ID)

//- ALIVE BYTES
#define CANR_ALIVE_MSG_DLC			1
#define CANR_ALIVE_MODULE_B			0

//Module Alive IDs
#define ALIVE_ECU					0x00
#define ALIVE_BSPD					0x01
#define ALIVE_TELEMETRY				0x02
#define ALIVE_DASH					0x03
#define ALIVE_ADC_FR				0x04
#define ALIVE_ADC_FL				0x05
#define ALIVE_ADC_RR				0x06
#define ALIVE_ADC_RL				0x07
#define ALIVE_INVERTER				0x08
#define ALIVE_FAN					0x09
#define ALIVE_BMS					0x0A
#define ALIVE_GLVBMS				0x0B
#define ALIVE_IMU					0x0C
#define ALIVE_IMD					0x0D
#define ALIVE_STEER_POS				0x0E
#define ALIVE_STEER_POS_UNINIT		0x0F
#define ALIVE_TRQ					0x10
#define ALIVE_TRQ_UNINIT			0x11

//-------------------------------------------------------------------------------
/*	------- Module ID overrides	 ----------------------------------------------*/
/*   If you want to make your own macro to replace module_id_x, make it here   */
//-------------------------------------------------------------------------------

/* BMS ID OVERRIDES */

#define BMS_I_AM_ALIVE_ID		(CANR_FCN_DATA_ID	|CANR_GRP_DASH_ID|CANR_MODULE_ID7_ID)



#define BMS_COMMFAULTS_MSG_ID	(CANR_FCN_DATA_ID    |CANR_GRP_BMS_ID|CANR_MODULE_ID0_ID )

#define BMS_TOTVTG_ID 			(CANR_FCN_DATA_ID  	|CANR_GRP_BMS_ID | CANR_MODULE_ID2_ID )
#define BMS_MAXMIN_TEMP_ID 		(CANR_FCN_DATA_ID 	|CANR_GRP_BMS_ID | CANR_MODULE_ID3_ID )		
#define BMS_CURRENT_ID 			(CANR_FCN_DATA_ID   |CANR_GRP_BMS_ID | CANR_MODULE_ID4_ID )
#define BMS_MAXMIN_VTG_ID		(CANR_FCN_DATA_ID   |CANR_GRP_BMS_ID | CANR_MODULE_ID5_ID )
#define BMS_TEMP_ID				(CANR_FCN_DATA_ID   |CANR_GRP_BMS_ID | CANR_MODULE_ID6_ID )		
#define BMS_VTG_ID				(CANR_FCN_DATA_ID   |CANR_GRP_BMS_ID | CANR_MODULE_ID7_ID )


#define BMS_ANALYZE_CMD_ID		(CANR_FCN_CMD_ID	|CANR_GRP_BMS_ID |CANR_MODULE_ID0_ID)
#define BMS_ANALYZE_ACK_ID 		(CANR_FCN_CMD_ID    |CANR_GRP_BMS_ID |CANR_MODULE_ID1_ID)
#define BMS_STATE_MSG_ID		(CANR_FCN_CMD_ID	|CANR_GRP_BMS_ID|CANR_MODULE_ID2_ID )		

/* GLVBMS ID OVERRIDES */

#define GLVBMS_VTG_ID			(CANR_FCN_DATA_ID | CANR_GRP_SENS_GLVBMS_ID | CANR_MODULE_ID0_ID )  // 0x658
#define GLVBMS_TEMP_ID			(CANR_FCN_DATA_ID | CANR_GRP_SENS_GLVBMS_ID | CANR_MODULE_ID1_ID )  // 0x659
#define GLVBMS_CURRENT_ID 		(CANR_FCN_DATA_ID | CANR_GRP_SENS_GLVBMS_ID | CANR_MODULE_ID2_ID )  // 0x65A
#define GLVBMS_MAXMIN_VAL_ID	(CANR_FCN_DATA_ID | CANR_GRP_SENS_GLVBMS_ID | CANR_MODULE_ID4_ID )  // 0x65C
#define GLVBMS_STATE_MSG_ID 	(CANR_FCN_DATA_ID | CANR_GRP_SENS_GLVBMS_ID | CANR_MODULE_ID5_ID )  // 0x65D
#define GLVBMS_TOTVTG_ID		(CANR_FCN_DATA_ID | CANR_GRP_SENS_GLVBMS_ID | CANR_MODULE_ID6_ID )  // 0x65E		
#define GLVBMS_ERROR_MSG_ID		(CANR_FCN_DATA_ID | CANR_GRP_SENS_GLVBMS_ID | CANR_MODULE_ID7_ID )  // 0x65F

/* Inverter ID OVERRIDES */

#define INVERTER_RESERVED0			(CANR_FCN_DATA_ID 	|CANR_GRP_INVERTER_ID | CANR_MODULE_ID7_ID)
#define INTERTER_RESERVED1			(CANR_FCN_DATA_ID 	|CANR_GRP_INVERTER_ID | CANR_MODULE_ID6_ID)
#define INVERTER_RESERVED2			(CANR_FCN_DATA_ID 	|CANR_GRP_INVERTER_ID | CANR_MODULE_ID5_ID)

#define CAN_INVERTER_DATA_STATUS_ID		(CANR_FCN_DATA_ID 	|CANR_GRP_INVERTER_ID | CANR_MODULE_ID4_ID)
#define CAN_INVERTER_DATA_STATUS_DLC	4

#define CAN_INVERTER_DATA_ENCODER_POS_ID	(CANR_FCN_DATA_ID 	|CANR_GRP_INVERTER_ID | CANR_MODULE_ID3_ID)
#define CAN_INVERTER_DATA_ENCODER_POS_DLC	8

#define CAN_INVERTER_DATA_RPM_ID		(CANR_FCN_DATA_ID 	|CANR_GRP_INVERTER_ID | CANR_MODULE_ID2_ID)
#define CAN_INVERTER_DATA_RPM_DLC		4

#define CAN_INVERTER_DATA_CURRENT_ID	(CANR_FCN_DATA_ID 	|CANR_GRP_INVERTER_ID | CANR_MODULE_ID1_ID)
#define CAN_INVERTER_DATA_CURRENT_DLC	8

#define CAN_INVERTER_DATA_VOLTAGE_ID	(CANR_FCN_DATA_ID 	|CANR_GRP_INVERTER_ID | CANR_MODULE_ID0_ID)
#define CAN_INVERTER_DATA_VOLTAGE_DLC	4


/* Telemetry ID OVERRIDES */

#define TELEMETRY_TO_INVERTER_DATA_ID (CANR_FCN_DATA_ID | CANR_GRP_TELEMETRY_ID | CANR_MODULE_ID3_ID)

/* ECU OVERRIDES */

#define ECU_ALIVE_ID									CANR_FCN_DATA_ID | CANR_GRP_DASH_ID | CANR_MODULE_ID7_ID

#define ECU_PLAY_RTDS_DATA									0x1
#define ECU_PLAY_RTDS_ID									CANR_FCN_BOOT_ID | CANR_GRP_ECU_ID | CANR_MODULE_ID0_ID
#define ECU_PLAY_RTDS_DLC									1

#define ECU_DRIVE_ENABLED_DATA								0x2
#define ECU_DRIVE_ENABLED_ID								CANR_FCN_BOOT_ID | CANR_GRP_ECU_ID | CANR_MODULE_ID0_ID
#define ECU_DRIVE_ENABLED_DLC								1

#define ECU_DRIVE_DISABLED_DATA								0x3
#define ECU_DRIVE_DISABLED_ID								CANR_FCN_BOOT_ID | CANR_GRP_ECU_ID | CANR_MODULE_ID0_ID
#define ECU_DRIVE_DISABLED_DLC								1

#define ECU_PRAMETER_ADJUSTMENT_CONFIRMED_DATA				0x0
#define ECU_PRAMETER_ADJUSTMENT_CONFIRMED_ID				CANR_FCN_BOOT_ID | CANR_GRP_ECU_ID | CANR_MODULE_ID1_ID
#define ECU_PRAMETER_ADJUSTMENT_CONFIRMED_DLC				0
	
#define ECU_LAUNCH_CONTROL_REQUEST_CONFIRMED_DATA			0x0F
#define ECU_LAUNCH_CONTROL_REQUEST_CONFIRMED_ID				CANR_FCN_BOOT_ID | CANR_GRP_ECU_ID | CANR_MODULE_ID2_ID
#define ECU_LAUNCH_CONTROL_REQUEST_CONFIRMED_DLC			1

#define ECU_LAUNCH_CONTROL_ARMED_DATA						0xF0
#define ECU_LAUNCH_CONTROL_ARMED_ID							CANR_FCN_BOOT_ID | CANR_GRP_ECU_ID | CANR_MODULE_ID2_ID
#define ECU_LAUNCH_CONTROL_ARMED_DLC						1

#define ECU_LAUNCH_CONTROL_DISARMED_DATA					0x00
#define ECU_LAUNCH_CONTROL_DISARMED_ID						CANR_FCN_BOOT_ID | CANR_GRP_ECU_ID | CANR_MODULE_ID2_ID
#define ECU_LAUNCH_CONTROL_DISARMED_DLC						1

#define ECU_TORQUE_REQUEST_DATA 							0x0
#define ECU_TORQUE_REQUEST_ID								CANR_FCN_PRI_ID | CANR_GRP_ECU_ID | CANR_MODULE_ID3_ID
#define ECU_TORQUE_REQUEST_DLC								4

#define ECU_TRACTION_CONTROL_ON_DATA 						0x0F
#define ECU_TRACTION_CONTROL_ON_ID							CANR_FCN_BOOT_ID | CANR_GRP_ECU_ID | CANR_MODULE_ID4_ID
#define ECU_TRACTION_CONTROL_ON_DLC							1


#define ECU_TRACTION_CONTROL_OFF_DATA						0xF0
#define ECU_TRACTION_CONTROL_OFF_ID							CANR_FCN_BOOT_ID | CANR_GRP_ECU_ID | CANR_MODULE_ID4_ID
#define ECU_TRACTION_CONTROL_OFF_DLC						1

#define ECU_CURRENT_MAX_DATA 								0
#define ECU_CURRENT_MAX_ID									CANR_FCN_DATA_ID | CANR_GRP_ECU_ID | CANR_MODULE_ID0_ID
#define ECU_CURRENT_MAX_DLC									4

#define ECU_CURRENT_ERROR_DATA								0
#define ECU_CURRENT_ERROR_ID								CANR_FCN_DATA_ID | CANR_GRP_ECU_ID | CANR_MODULE_ID1_ID
#define ECU_CURRENT_ERROR_DLC								4

#define ECU_CURRENT_OUTPUT_DATA								0
#define ECU_CURRENT_OUTPUT_ID								CANR_FCN_DATA_ID | CANR_GRP_ECU_ID | CANR_MODULE_ID2_ID
#define ECU_CURRENT_OUTPUT_DLC								4

#define ECU_CURRENT_INTEGRAL_DATA							0
#define ECU_CURRENT_INTEGRAL_ID								CANR_FCN_DATA_ID | CANR_GRP_ECU_ID | CANR_MODULE_ID3_ID
#define ECU_CURRENT_INTEGRAL_DLC							4

#define ECU_CURRENT_CONTROLLER_STATE_DATA					0
#define ECU_CURRENT_CONTROLLER_STATE_ID						CANR_FCN_DATA_ID | CANR_GRP_ECU_ID | CANR_MODULE_ID4_ID
#define ECU_CURRENT_CONTROLLER_STATE_DLC					1

#define ECU_CURRENT_IMPLAUSIBILITY_DATA						0
#define ECU_CURRENT_IMPLAUSIBILITY_ID						CANR_FCN_DATA_ID | CANR_GRP_ECU_ID | CANR_MODULE_ID5_ID
#define ECU_CURRENT_IMPLAUSIBILITY_DLC						1



//-------------------------------------------------------------------------------
/*	------- Byte mapping 					   --------------------------------*/
/* If you want to describe the mapping of your can bus data, make macros here  */
//-------------------------------------------------------------------------------

/* Inverter data, sent from telemetry (analyze) */
#define STATUS_BIT_FLIP_REQUEST_COMMAND 0x01
#define CONTROLLER_PARAMETER_P_SET_REQUEST_COMMAND 0x11
#define CONTROLLER_PARAMETER_I_SET_REQUEST_COMMAND 0x12
#define CONTROLLER_PARAMETER_D_SET_REQUEST_COMMAND 0x13
#define TORQUE_REQUEST_COMMAND 0x41

//GLVBMS ERROR DATA
#define GLVBMS_ERROR_NOERROR		0x00
#define GLVBMS_ERROR_OVERCURRENT	0x01
#define GLVBMS_ERROR_OVERVOLTAGE	0x02
#define GLVBMS_ERROR_OVERTEMP		0x03
#define GLVBMS_ERROR_REQUESTED		0x04

//-------------------------------------------------------------------------------------




#endif /* REVOLVE_CAN_DEFINITIONS_H_ */
