#pragma once
#include "Vector.h"
#include "Structures.h"
class Transform
{
public:
	Transform();
	~Transform();


	// Setters and Getters for position/rotation/scale
	void SetPosition(Vector position) { _position = position; }
	void SetPosition(float x, float y, float z) { _position.x = x; _position.y = y; _position.z = z; }

	Vector GetPosition() const { return _position; }

	void SetScale(Vector scale) { _scale = scale; }
	void SetScale(float x, float y, float z) { _scale.x = x; _scale.y = y; _scale.z = z; }

	Vector GetScale() const { return _scale; }

	void SetRotation(Vector rotation) { _rotation = rotation; }
	void SetRotation(float x, float y, float z) { _rotation.x = x; _rotation.y = y; _rotation.z = z; }

	Vector GetRotation() const { return _rotation; }

	XMMATRIX GetWorldMatrix() const { return XMLoadFloat4x4(&_world); }
	void SetParent(Transform * parent) { _parent = parent; }
	void UpdateWorldMatrix(float dt);
private:
	Vector _position;
	Vector _rotation;
	Vector _scale;
	XMFLOAT4X4 _world;
	Transform * _parent;
};

