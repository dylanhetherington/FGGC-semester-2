#pragma once

#include <directxmath.h>
#include <d3d11_1.h>
#include <string>
#include "Vector.h"
#include "Transform.h"
#include "Structures.h"
#include "Particle.h"
#include "Apperance.h"

using namespace DirectX;
using namespace std;



class GameObject
{
public:
	GameObject(string type, Geometry geometry, Material material, float mass);
	GameObject(string type, Geometry geometry, Material material);
	~GameObject();

	string GetType() const { return _type; }

	Transform* GetTransform() const { return _pTransform; }

	Particle* GetParticle() const { return _pParticle; }

	Apperance* GetApperance() const { return _pApperance; }

	void Update(float t);
	void Draw(ID3D11DeviceContext * pImmediateContext);
	
private:
	string _type;

	Transform* _pTransform;
	Particle* _pParticle;
	Apperance* _pApperance;

};

