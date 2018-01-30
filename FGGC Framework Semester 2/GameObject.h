#pragma once

#include <directxmath.h>
#include <d3d11_1.h>
#include <string>
#include "Vector.h"
#include "Transform.h"
#include "Structures.h"
#include "Particle.h"

using namespace DirectX;
using namespace std;



class GameObject
{
public:
	GameObject(string type, Geometry geometry, Material material);
	~GameObject();

	string GetType() const { return _type; }

	Geometry GetGeometryData() const { return _geometry; }

	Material GetMaterial() const { return _material; }

	void SetTextureRV(ID3D11ShaderResourceView * textureRV) { _textureRV = textureRV; }
	ID3D11ShaderResourceView * GetTextureRV() const { return _textureRV; }
	bool HasTexture() const { return _textureRV ? true : false; }

	void Update(float t);
	void Draw(ID3D11DeviceContext * pImmediateContext);

	Transform* _transform;
private:

	string _type;
	Particle* _particle;
	Geometry _geometry;
	Material _material;

	ID3D11ShaderResourceView * _textureRV;
};

