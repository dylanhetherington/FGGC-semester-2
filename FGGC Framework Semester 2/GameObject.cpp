#include "GameObject.h"

GameObject::GameObject(string type, Geometry geometry, Material material) : _type(type)
{
	_apperance = new Apperance(geometry, material);
	_transform = new Transform();
	_particle = new Particle(_transform);
}

GameObject::~GameObject()
{
	delete _particle;
	delete _transform;
}

void GameObject::Update(float t)
{
	_transform->UpdateWorldMatrix(t);
}

void GameObject::Draw(ID3D11DeviceContext * pImmediateContext)
{
	_apperance->DrawApperance(pImmediateContext);
}