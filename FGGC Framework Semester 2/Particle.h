#pragma once
#include "Transform.h"
class Particle
{
public:
	Particle(Transform * transform);
	~Particle();
	void ParticleMoveForward();

private:
	Transform* _transform;
};

