#include "Particle.h"

Particle::Particle(Transform* transform)
{
	_transform = transform;
	_velocity = Vector(0.0f,0.0f, 1.0f);
	_acceleration = Vector(0.0f, 0.0f, 1.0f);

}
Particle::~Particle()
{
	delete _transform;
}
void Particle::ParticleMoveForward()
{
	Vector position = _transform->GetPosition();
	position.z -= 0.1f;
	_transform->SetPosition(position);
}
void Particle::MoveConstantVelocity(float t)
{
	Vector position = _transform->GetPosition();
	position = position + _velocity;
	_transform->SetPosition(position);
}
void Particle::MoveConstantAcceleration(float t)
{
	Vector position = _transform->GetPosition();
	position = position + _velocity * t + (_acceleration * 0.5) * t * t;
	_transform->SetPosition(position);
	_velocity = _velocity + _acceleration * t;
}