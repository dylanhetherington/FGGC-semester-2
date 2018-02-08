#include "GameObject.h"

GameObject::GameObject(string type, Geometry geometry, Material material) : _type(type)
{
	_pApperance = new Apperance(geometry, material);
	_pTransform = new Transform();
	_pParticle = new Particle(_pTransform);
}

GameObject::~GameObject()
{
	delete _pParticle;
//	delete _transform;
}

void GameObject::Update(float t)
{
	_pTransform->UpdateWorldMatrix(t);
	_pParticle->Update(t, _type);
}

void GameObject::Draw(ID3D11DeviceContext * pImmediateContext)
{
	_pApperance->DrawApperance(pImmediateContext);
}