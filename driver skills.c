#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    leftLight,      sensorLineFollower)
#pragma config(Sensor, in2,    rightLight,     sensorLineFollower)
#pragma config(Sensor, dgtl1,  sonar,          sensorSONAR_cm)
#pragma config(Sensor, I2C_1,  leftRearEnc,    sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  leftFrontEnc,   sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_3,  rightFrontEnc,  sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_4,  rightRearEnc,   sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port1,           clawMotor,     tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           leftRearMotor, tmotorVex393_MC29, openLoop, encoderPort, I2C_1)
#pragma config(Motor,  port3,           leftFrontMotor, tmotorVex393_MC29, openLoop, encoderPort, I2C_2)
#pragma config(Motor,  port4,           rightRearMotor, tmotorVex393_MC29, openLoop, encoderPort, I2C_4)
#pragma config(Motor,  port5,           rightFrontMotor, tmotorVex393_MC29, openLoop, reversed, encoderPort, I2C_3)
#pragma config(Motor,  port6,           leftMobileMotor, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           leftLiftMotor, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           rightLiftMotor, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           rightMobileMotor, tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void mgLiftUp(int speed, int time)
{
	motor[rightMobileMotor] = speed;
	motor[leftMobileMotor] = speed;
	wait1Msec(time);
}
void stopmgLift()
{
	motor[rightMobileMotor] = 0;
	motor[leftMobileMotor] = 0;
}
void mgLiftDown(int speed, int time)
{
	motor[rightMobileMotor] = -speed;
	motor[leftMobileMotor] = -speed;
	wait1Msec(time);
}
void driveForward(int leftSpeed, int rightSpeed)
{
	motor[rightRearMotor] = rightSpeed;
	motor[rightFrontMotor] = rightSpeed;
	motor[leftFrontMotor] = leftSpeed;
	motor[leftRearMotor] = leftSpeed;
	//wait1Msec(time);
}
void driveBackward(int leftSpeed, int rightSpeed)
{
	motor[rightRearMotor] = -rightSpeed;
	motor[rightFrontMotor] = -rightSpeed;
	motor[leftFrontMotor] = -leftSpeed;
	motor[leftRearMotor] = -leftSpeed;
	//wait1Msec(time);
}
void stopDrive()
{
	motor[rightRearMotor] = 0;
	motor[rightFrontMotor] = 0;
	motor[leftFrontMotor] = 0;
	motor[leftRearMotor] = 0;
}
void turnLeft(int speed, int time)
{
	motor[rightRearMotor] = speed;
	motor[rightFrontMotor] = speed;
	motor[leftFrontMotor] = -speed;
	motor[leftRearMotor] = -speed;
	wait1Msec(time);
}
void turnRight(int speed, int time)
{
	motor[rightRearMotor] = -speed;
	motor[rightFrontMotor] = -speed;
	motor[leftFrontMotor] = speed;
	motor[leftRearMotor] = speed;
	wait1Msec(time);
}
void openClaw(int speed, int time)
{
	motor[clawMotor] = speed;
	wait1Msec(time);
}
void closeClaw(int speed, int time)
{
	motor[clawMotor] = -speed;
	wait1Msec(time);
}
void stopClaw()
{
	motor[clawMotor] = 0;
}
void clawLiftUp(int speed, int time)
{
	motor[leftLiftMotor]	= speed;
	motor[rightLiftMotor] = speed;
	wait1Msec(time);
}
void clawLiftDown(int speed, int time)
{
	motor[leftLiftMotor] = -speed;
	motor[rightLiftMotor] = -speed;
	wait1Msec(time);
}
void stopLift()
{
	motor[leftLiftMotor] = 0;
	motor[rightLiftMotor] = 0;
}

const float fullCycle = 392;
const float fullSpeed = 127;
const int deadZone = 20;


task main()
{

slaveMotor(leftLiftMotor,rightLiftMotor);
slaveMotor(leftMobileMotor,rightMobileMotor);
  // User control code here, inside the loop
//startTask(autonRecorder);
motor[rightFrontMotor] = 60;
wait1Msec(2000);
motor[rightFrontMotor] = 0;
motor[leftFrontMotor] = 60;
wait1Msec(2000);
motor[leftFrontMotor] = 0;
motor[rightRearMotor] = 60;
wait1Msec(2000);
motor[rightRearMotor] = 0;
motor[leftRearMotor] = 60;
wait1Msec(2000);
motor[leftRearMotor] = 0;
motor[rightLiftMotor] = 60;
wait1Msec(2000);
motor[rightLiftMotor] = 0;
motor[rightMobileMotor] = 60;
wait1Msec(2000);
motor[rightMobileMotor] = 0;

while (true)
{
	//Drive Controls (main controller: left motors on left joystick; right motors on right joystick)
	if(vexRT[Ch3] > deadZone || vexRT[Ch3] < -deadZone){
 		motor[leftFrontMotor] = vexRT[Ch3];
 		motor[leftRearMotor] = vexRT[Ch3];
	}
	else{
		motor[leftFrontMotor] = 0;
 		motor[leftRearMotor] = 0;
	}

	if(vexRT[Ch2] > deadZone || vexRT[Ch2] < -deadZone){
 		motor[rightFrontMotor] = vexRT[Ch2];
 		motor[rightRearMotor] = vexRT[Ch2];
	}
		else{
		motor[leftFrontMotor] = 0;
 		motor[leftRearMotor] = 0;
	}

	//Claw Controls (secondary controller: button 6U opens claw and 6D closes claw)
	if (vexRT[Btn6UXmtr2] == 1 && vexRT[Btn6DXmtr2] == 0)
	{
		motor[clawMotor] = fullSpeed;
	}
	else if (vexRT[Btn6DXmtr2] == 1 && vexRT[Btn6UXmtr2] == 0)
	{
		motor[clawMotor] = -fullSpeed;
	}
	else
	{
		motor[clawMotor] = 0;
	}

	//Mobile Goal Carrier Driver Control

	if (vexRT[Btn6U] == 1 && vexRT[Btn6D] == 0)
	{
		//motor[leftMobileMotor] =fullSpeed;
		motor[rightMobileMotor] = fullSpeed;
	}
	else if (vexRT[Btn6D] == 1 && vexRT[Btn6U] == 0)
	{
		//motor[leftMobileMotor] = -fullSpeed;
		motor[rightMobileMotor] = -fullSpeed;
	}
	else
	{
		//motor[leftMobileMotor] = 0;
		motor[rightMobileMotor] = 0;
	}

	//Lift Controls (secondary controller; right joystick)
	//motor[leftLiftMotor] = vexRT[Ch2Xmtr2];
	if (vexRT[Ch2Xmtr2] > deadZone || vexRT[Ch2Xmtr2] < deadZone){
		motor[rightLiftMotor] = vexRT[Ch2Xmtr2];
	}
	else{
		motor[rightLiftMotor] = 0;
	}
	}
}
