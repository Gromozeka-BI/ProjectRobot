#include "Math.h"
#include <iostream>
using namespace std;

class Software {
private:
	int Xphoto;//replace with an array
	int Yphoto;//replace with an array
	int Xroom;//replace with an array
	int Yroom;//replace with an array
	int Angle;
public:
	void Room() {
		//Room size
		//All breakpoint (Width, Height, Length, etc.)
	}
	void Camera() {
		//Location camera (X,Y,Z)
		//Angles 
	}
	void SearchGraffiti(int Xphoto, int Yphoto, int& Xroom, int& Yroom) {
		// search for dirt coordinates
		// translation from the coordinate system of the photo to the coordinate system of the room
	}
	void SearchRobot(int Xphoto, int Yphoto, int& Xroom, int& Yroom) {
		// search for Robot coordinates
		// translation from the coordinate system of the photo to the coordinate system of the room
	}
	int GetXdirt() {
		return Xroom;
	}
	int GetYdirt() {
		return Yroom;
	}
	int GetXRobot() {
		return Xroom;
	}
	int GetYRobot() {
		return Yroom;
	}
	int GetAngleRobot() {
		return Angle;
	}
};
class Camera {
private:
	Mat png;
	int x;//replace with an array
	int y;//replace with an array
public:
	void dirtSearch() {
		TurnOnCamera();
		png = TakePhoto();
		dirtDetected(png, x, y);
	}

	void TurnOnCamera() {
		// Camera ON
	}
	Mat TakePhoto() {
		// Take Photo
		return png;
	}
	void dirtDetected(Mat png, int& x, int& y) {
		// search for dirt coordinates on photo
	}

	int  GetX() { // Return X on Photo
		return this->x;
	}

	int GetY() {// Return Y on Photo
		return this->y;
	}
};
class Robot {
private:
	int XRobot; // XRobot, YRobot =  Absolute coordinates of the robot
	int YRobot; 
	int XGoal; // XGoal, YGoal = Absolute coordinates of the target
	int YGoal;
	int XDirt;	//replace with an array
	int YDirt;	//replace with an array
	int epsilon = 2; // The distance to the dirt when the cleaner is turned on
	int angle; // angle = At what angle is the robot in absolute coordinates
	int motorLeft; //Takes a value from -100 to 100 (100 full throttle forward;-100 full throttle back;0 motor stop)
	int motorRight; //Takes a value from - 100 to 100 (100 full throttle forward;-100 full throttle back;0 motor stop)
	bool cleaner = false; 
	bool reverseRightMotor = false;
	bool reverseLeftMotor = false;

	float dt = 0; // Time of one clock cycle
	float aP = 0; // PIDs for the angle
	float aI = 0;
	float aD = 0;
	float lP = 0; // PIDs for the length
	float lI = 0;
	float lD = 0;


	bool GetRightMotor() {
		return reverseRightMotor;
	}
	bool GetLeftMotor() {
		return reverseLeftMotor;
	}

public:
	Robot(bool reverseRightMotor, bool reverseLeftMotor) {
		this->reverseRightMotor = reverseRightMotor;
		this->reverseLeftMotor = reverseLeftMotor;
	}
	void SetXRobot(int XRobot) {
		this->XRobot = XRobot;
	}
	void SetYRobot(int YRobot) {
		this->YRobot = YRobot;
	}
	void SetXGoal(int XGoal) {
		this->XGoal = XGoal;
	}
	void SetYGoal(int YGoal) {
		this->YGoal = YGoal;
	}
	void SetAngle(int angle) {
		this->angle = angle;
	}
	void SetPID(float dt, float aP, float aI, float aD, float lP, float lI, float lD) {
		this->dt = dt;
		this->aP = aP;
		this->aI = aI;
		this->aD = aD;
		this->lP = lP;
		this->lI = lI;
		this->lD = lD;
	}

	void AcroMod(int angle, int throttle, int& motorRight, int& motorLeft) { //Mode for testing the robot 
		// angle = Takes a value from -100 to 100 (100 maximum right rotation;-100 maximum left rotation)
		// throttle = Takes a value from -100 to 100 (100 full throttle forward;-100 full throttle back)
		// right rotation (motor Right -100/ motor Left 100)
		// left rotation (motor Right 100/ motor Left -100)
		// riding forward (motor Right 100/ motor Left 100)
		// riding back (motor Right 100/ motor Left 100)
		motorRight = throttle + angle * (-1);
		motorLeft = throttle + angle;
		if (GetRightMotor()) {
			motorRight = motorRight * (-1);
		}
		if (GetLeftMotor()) {
			motorLeft = motorLeft * (-1);
		}
	}
	void AutomaticMod(int angle, int XRobot, int YRobot, int XGoal, int YGoal, int& Ang, int& Thr) {
		// angle = At what angle is the robot in absolute coordinates
		// XRobot, YRobot =  Absolute coordinates of the robot
		// XGoal, YGoal = Absolute coordinates of the target
		// Ang = Takes a value from -100 to 100 (100 maximum right rotation;-100 maximum left rotation)
		// Thr = Takes a value from -100 to 100 (100 full throttle forward;-100 full throttle back)
		//	1) We rotate to get to one straight line
		//  2) We are going to the point

		//...........

		// There should be a code here

		float l_prevErr;
		float a_prevErr;

		float x1 = XRobot;
		float y1 = YRobot;
		float x2 = XGoal;
		float y2 = YGoal;
		float α = angle;
		float b = atan((y2-y1)/(x2-x1)) * 180 / 3.1415;
		float φ = α - b;
		float l = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));


		float klP = l;
		float klI = klI + l * dt;
		float klD = (l- l_prevErr) / dt;
		l_prevErr = l;

		Thr = constrain(lP * klP + lI * klI + lD * klD); // CHEK
		//...........

	}
	bool TurnCleaner(int XRobot, int YRobot, int XDirt, int YDirt) {
		if ((abs(XRobot - XDirt) < epsilon) && (abs(YRobot - YDirt) < epsilon)) {
			return true;
		}
		else {
			return false;
		}
	}
	void GetEpsilon(int epsilon) {
		this->epsilon = epsilon;
	}

	void ReturnRobot(int motorRight, int motorLeft, int cleaner) {
		// data transmission to the robot
	}
};


int main() {

	Robot bob(false, false);

	int angle = 0;
	int XRobot = 0;
	int YRobot = 0;
	int XGoal = 0;
	int YGoal = 0;
	int XDirt = 0;
	int YDirt = 0;
	int Ang = 0;
	int Thr = 0;
	int E = 0;

	bool cleaner = false;
	int motorRight = 0;
	int motorLeft = 0;

	bob.GetEpsilon(E);

	while (1) {
		bob.AutomaticMod(angle, XRobot, YRobot, XGoal, YGoal, Ang, Thr); // We pass the coordinates and get the task for the robot
		bob.AcroMod(Ang, Thr, motorRight, motorLeft); // We translate the task for the robot into the operation of engines
		cleaner = bob.TurnCleaner(XRobot, YRobot, XDirt, YDirt); // If it is close to dirt then turn on the cleaner
		bob.ReturnRobot(motorRight, motorLeft, cleaner); // Passing the task to the robot
	}




}

