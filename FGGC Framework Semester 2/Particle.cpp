#include "Particle.h"

Particle::Particle(Transform* transform)
{
	_pTransform = transform;
	_velocity = Vector(0.0f,0.0f, 1.0f);
	_acceleration = Vector(0.0f, 0.0f, 1.0f);

}
Particle::~Particle()
{
	delete _pTransform;
}
void Particle::ParticleMoveForward()
{
	Vector position = _pTransform->GetPosition();
	position.z -= 0.1f;
	_pTransform->SetPosition(position);
}
void Particle::MoveConstantVelocity(float t)
{
	Vector position = _pTransform->GetPosition();
	position = position + _velocity * t;
	_pTransform->SetPosition(position);
}
void Particle::MoveConstantAcceleration(float t)
{
	Vector position = _pTransform->GetPosition();
	position = position + _velocity * t + (_acceleration * 0.5) * t * t;
	_pTransform->SetPosition(position);
	_velocity = _velocity + _acceleration * t;
}
void Particle::Update(float t, std::string type)
{
	if (type != "Floor")
	{
		MoveConstantAcceleration(t);
	}
}