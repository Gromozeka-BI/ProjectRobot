#include <Math.h>
#include <iostream>

using namespace std;
class PID {
	float kp, ki, kd;
	int minOut, maxOut;
	float integral;
	float prevErr;
	float dt;
public:
	PID() {
		kp = 0;
		ki = 0;
		kd = 0;
		minOut = 0;
		maxOut = 0;
		integral = 0;
		prevErr = 0;
		dt = 0;
	}
	void SetPID(float kp, float ki, float kd) {
		this->kp = kp;
		this->ki = ki;
		this->kd = kd;
	}
	void SetMinMax(int minOut, int maxOut) {
		this->minOut = minOut;
		this->maxOut = maxOut;
	}
	void SetDt(float dt) {
		this->dt = dt;
	}
	float computePID(float input) {
		float err = input;
		integral = integral + (float)err * dt * ki;
		if (integral > maxOut) integral = maxOut;
		if (integral < minOut) integral = minOut;

		float D = (err - prevErr) / dt;
		prevErr = err;

		float out = err * kp + integral + D * kd;
		if (out > maxOut) out = maxOut;
		if (out < minOut) out = minOut;
		return out;
	}
	int GetTest() {
		return 1;
	}
};