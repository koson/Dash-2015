#ifndef CANMESSAGES_H_
#define CANMESSAGES_H_


#include "sam4e-base/RevolveDrivers/can.h"
#include "DriversNotInBase/revolve_can_definitions.h"
#include "canID_definitions.h"


struct CanMessage TorquePedalCalibrationMax = {
	.data.u8[0] = 0xF0,
	.dataLength = 1,
	.messageID = ID_TORQUE_PEDAL_CALIBRATION
};
struct CanMessage TorquePedalCalibrationMin = {
	.data.u8[0] = 0x0F,
	.dataLength = 1,
	.messageID = ID_TORQUE_PEDAL_CALIBRATION
};
struct CanMessage SteeringCalibrationLeft = {
	.data.u8[0] = 0xF0,
	.dataLength = 1,
	.messageID = ID_STEERING_CALIBRATION
};
struct CanMessage SteeringCalibrationRight = {
	.data.u8[0] = 0x0F,
	.dataLength = 1,
	.messageID = ID_STEERING_CALIBRATION
};

struct CanMessage Acknowledge = {
	.messageID = ID_DASH_ACKNOWLEDGE,
	.dataLength = 0
};

struct CanMessage FinishedRTDS = {
	.messageID = ID_FINISHED_RTDS,
	.dataLength = 0
};
struct CanMessage RequestDriveDisable = {
	.messageID = ID_ECU_DRIVE,
	.dataLength = 1,
	.data.u8[0] = 0
};
struct CanMessage RequestDriveEnable = {
	.messageID = ID_ECU_DRIVE,
	.dataLength = 1,
	.data.u8[0] = 1
};

struct CanMessage RequestLCInit = {
	.messageID = ID_ECU_LC,
	.dataLength = 1,
	.data.u8[0] = 1
};

struct CanMessage RequestLCArmed = {
	.messageID = ID_ECU_LC,
	.dataLength = 1,
	.data.u8[0] = 2
};

struct CanMessage EcuParameters = {
	.messageID = ID_ECU_PARAMETERS,
	.dataLength = 4,
	.data.u32[0] = 0
	};

	



#endif /* CANMESSAGES_H_ */