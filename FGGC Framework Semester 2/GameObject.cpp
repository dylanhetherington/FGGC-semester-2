#include "GameObject.h"

GameObject::GameObject(string type, Geometry geometry, Material material) : _geometry(geometry), _type(type), _material(material)
{
	_textureRV = nullptr;
	_transform = new Transform();
	_particle = new Particle(_transform);
}

GameObject::~GameObject()
{
	delete _particle;
	delete _transform;
	delete _textureRV;
}

void GameObject::Update(float t)
{
	_transform->UpdateWorldMatrix(t);
}

void GameObject::Draw(ID3D11DeviceContext * pImmediateContext)
{
	// NOTE: We are assuming that the constant buffers and all other draw setup has already taken place

	// Set vertex and index buffers
	pImmediateContext->IASetVertexBuffers(0, 1, &_geometry.vertexBuffer, &_geometry.vertexBufferStride, &_geometry.vertexBufferOffset);
	pImmediateContext->IASetIndexBuffer(_geometry.indexBuffer, DXGI_FORMAT_R16_UINT, 0);
	pImmediateContext->DrawIndexed(_geometry.numberOfIndices, 0, 0);
}
