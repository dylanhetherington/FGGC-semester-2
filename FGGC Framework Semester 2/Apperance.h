#pragma once
#include "Structures.h"
class Apperance
{
public:
	Apperance(Geometry geometry, Material material);
	~Apperance();

	void SetTextureRV(ID3D11ShaderResourceView * textureRV) { _textureRV = textureRV; }
	ID3D11ShaderResourceView * GetTextureRV() const { return _textureRV; }
	bool HasTexture() const { return _textureRV ? true : false; }

	Geometry GetGeometryData() const { return _geometry; }

	Material GetMaterial() const { return _material; }

	void DrawApperance(ID3D11DeviceContext * pImmediateContext);
private:

	ID3D11ShaderResourceView * _textureRV;
	Geometry _geometry;
	Material _material;

};

