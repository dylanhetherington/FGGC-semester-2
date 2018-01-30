#include "Transform.h"



Transform::Transform()
{
	_position = Vector();
	_rotation = Vector();
	_scale = Vector(1.0f, 1.0f, 1.0f);
}

Transform::~Transform()
{
}

void Transform::UpdateWorldMatrix(float dt)
{
	XMMATRIX scale = XMMatrixScaling(_scale.x, _scale.y, _scale.z);
	XMMATRIX rotation = XMMatrixRotationX(_rotation.x) * XMMatrixRotationY(_rotation.y) * XMMatrixRotationZ(_rotation.z);
	XMMATRIX translation = XMMatrixTranslation(_position.x, _position.y, _position.z);

	XMStoreFloat4x4(&_world, scale * rotation * translation);

	if (_parent != nullptr)
	{
		XMStoreFloat4x4(&_world, this->GetWorldMatrix() * _parent->GetWorldMatrix());
	}
}
