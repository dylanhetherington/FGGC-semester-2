#pragma once
#include "Transform.h"
#include <String>
//#include "Vector.h"
class Particle
{
public:
	Particle(Transform * transform);
	~Particle();
	void ParticleMoveForward();

	void SetVelocity(Vector velocity) { _velocity = velocity; }
	void SetVelocity(float x, float y, float z) { _velocity.x = x; _velocity.y = y; _velocity.z = z; }
	Vector GetVelocity() const { return _velocity; }

	void SetAcceleration(Vector acceleration) { _acceleration = acceleration; }
	void SetAcceleration(float x, float y, float z) { _acceleration.x = x; _acceleration.y = y; _acceleration.z = z; }
	Vector GetAcceleration() const { return _acceleration; }

	void Update(float t, std::string type);
private:
	Transform* _pTransform;
	Vector _velocity;
	Vector _acceleration;
	float _mass;
	Vector _resultantForce;

	void MoveConstantVelocity(float);
	void MoveConstantAcceleration(float);

};

