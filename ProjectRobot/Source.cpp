using namespace std;

class Software {
private:
	int Xphoto;
	int Yphoto;
	int Xroom;
	int Yroom;
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
	int GetX() {
		return Xroom;
	}
	int GetY() {
		return Yroom;
	}
};
class Camera {
private:
	Mat png;
	int x;
	int y;
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
	int x;
	int y;
public:
	void SetX(int Xroom) {
		this->x = Xroom;
	}
	void SetY(int Yroom) {
		this->y = Yroom;
	}
	void GoToGraffiti(int x, int y) {

	}
	void TurnCleanerOn(bool cleaner) {

	}
};


int main() {

}

