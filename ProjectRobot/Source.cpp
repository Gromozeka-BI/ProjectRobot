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
	int Xroom;
	int Yroom;
	int angle;
	int motorLeft; //Takes a value from -100 to 100 (100 full throttle forward;-100 full throttle back;0 motor stop)
	int motorRight; //Takes a value from - 100 to 100 (100 full throttle forward;-100 full throttle back;0 motor stop)
	bool reverseRightMotor = false;
	bool reverseLeftMotor = false;


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
	void SetX(int Xroom) {
		this-> = Xroom;
	}
	void SetY(int Yroom) {
		this->Yroom = Yroom;
	}
	void SetAngle(int Angle) {
		this->angle = Angle;
	}
	void AcroMod(int angle, int throttle, int& motorRight, int& motorLeght) { //Mode for testing the robot 
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
	void AutomaticMod() {
		
	}
	void TurnCleanerOn(bool cleaner) {

	}
};


int main() {

}

