#include "Particle.h"



Particle::Particle(Transform* transform)
{
	_transform = transform;
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
