#pragma once
#include "Transform.h"
#include <String>
//#include "Vector.h"
class Particle
{
public:
	Particle(Transform * transform, float mass);
	~Particle();
	void ToggleAtRest() { if (_isAtRest == true) _isAtRest = false; else _isAtRest = true; }
	void SetAtRest(bool state) { _isAtRest = state; }

	void ToggleLaminar() { if (_isLaminarFlow == true) _isLaminarFlow = false; else _isLaminarFlow = true; }
	void SetLaminarFlow(bool state) { _isLaminarFlow = state; }

	void SetVelocity(Vector velocity) { _velocity = velocity; }
	void SetVelocity(float x, float y, float z) { _velocity.x = x; _velocity.y = y; _velocity.z = z; }
	Vector GetVelocity() const { return _velocity; }

	void SetAcceleration(Vector acceleration) { _acceleration = acceleration; }
	void SetAcceleration(float x, float y, float z) { _acceleration.x = x; _acceleration.y = y; _acceleration.z = z; }
	Vector GetAcceleration() const { return _acceleration; }

	void SetMass(float mass) { _mass = mass; }
	float GetMass() const { return _mass; }

	Vector GetResultantForce() { return _resultantForce; }
	void Update(float t, std::string type);

	void SetThrustForce(Vector thrustForce) { _thrustForce = thrustForce; }
	void SetThrustForce(float x, float y, float z) { _thrustForce.x = x; _thrustForce.y = y; _thrustForce.z = z; }
	Vector GetThrustForce() const { return _thrustForce; }

	void SetWeight(Vector weight) { _weight = weight; }
	void SetWeight(float x, float y, float z) { _weight.x = x; _weight.y = y; _weight.z = z; }
	Vector GetWeight() const { return _weight; }
private:
	Transform* _pTransform;
	Vector _velocity;
	Vector _acceleration;
	float _mass;
	Vector _resultantForce;
	bool _useConstAcceleration;
	Vector _thrustForce;
	Vector _weight;
	bool _isAtRest;
	Vector _dragForce;
	bool _isLaminarFlow;

	void UpdateResultantForce();
	void UpdateAcceleration();
	void UpdateDragForce(float dragFactor);
	void CalculateLaminarDrag(float dragFactor);
	void CalculateTurbulentDrag( float dragFactor);

	void Move(float);
};

