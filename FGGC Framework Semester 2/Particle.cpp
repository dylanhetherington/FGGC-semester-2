#include "Particle.h"

Particle::Particle(Transform* transform, float mass)
{
	_pTransform = transform;
	_mass = mass;
	_useConstAcceleration = false;
	_velocity = Vector(0.0f, 0.0f, 0.0f);
	_acceleration = Vector(0.0f, 0.0f, 0.0f);
	_resultantForce = Vector(0.0f, 0.0f, 0.0f);
	_thrustForce = Vector(0.0f, 0.0f, 0.0f);
	_weight = Vector(0.0f, -9.81f, 0.0f);
	_isAtRest = true;
	_weight = _weight * _mass;
}
Particle::~Particle()
{
	delete _pTransform;
}
void Particle::Update(float t, std::string type)
{
	if (_isAtRest == true)
	{
		_thrustForce.y = 9.81 * _mass;
	}
	UpdateResultantForce();
	UpdateAcceleration();
	Move(t);
}
void Particle::UpdateResultantForce()
{
	_resultantForce = _resultantForce + _thrustForce;
	_resultantForce = _resultantForce + _weight;
}
void Particle::UpdateAcceleration()
{
	_acceleration = _resultantForce / _mass;
}
void Particle::UpdateDragForce(float dragFactor)
{
	if (_isLaminarFlow)
	{
		CalculateLaminarDrag(dragFactor);
	}
	else
	{
		CalculateTurbulentDrag(dragFactor);
	}
}
void Particle::CalculateLaminarDrag(float dragFactor)
{
	_dragForce = _velocity * -dragFactor;
}
void Particle::CalculateTurbulentDrag(float dragFactor)
{
	float velocityMagnitude = Vector::Magnitude(_velocity);
	Vector velocityNormal = Vector::Normalize(_velocity);
	float dragMagnitude = dragFactor * velocityMagnitude * velocityMagnitude;
	_dragForce = velocityNormal * -dragMagnitude;
}
void Particle::Move(float t)
{
	Vector position = _pTransform->GetPosition();
	position = position + _velocity * t + (_acceleration * 0.5) * t * t;
	_pTransform->SetPosition(position);
	_velocity = _velocity + _acceleration * t;
}