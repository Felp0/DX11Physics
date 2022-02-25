#include "GameObject.h"

GameObject::GameObject(string type, Geometry geometry, Material material) : _geometry(geometry), _type(type), _material(material)
{


	_transform = new Transform();


	_textureRV = nullptr;
}

GameObject::~GameObject()
{
}

void GameObject::Update(float t)
{
	// Calculate world matrix
	XMMATRIX scale = XMMatrixScaling(_transform->_scale.x, _transform->_scale.y, _transform->_scale.z);
	XMMATRIX rotation = XMMatrixRotationX(_transform->_rotation.x) * XMMatrixRotationY(_transform->_rotation.y) * XMMatrixRotationZ(_transform->_rotation.z);
	XMMATRIX translation = XMMatrixTranslation(_transform->_position.x, _transform->_position.y, _transform->_position.z);

	XMStoreFloat4x4(&_transform->_world, scale * rotation * translation);

	if (_transform->_parent != nullptr)
	{
		XMStoreFloat4x4(&_transform->_world, this->_transform->GetWorldMatrix() * _transform->GetWorldMatrix());
	}
}

void GameObject::Draw(ID3D11DeviceContext* pImmediateContext)
{
	// NOTE: We are assuming that the constant buffers and all other draw setup has already taken place

	// Set vertex and index buffers
	pImmediateContext->IASetVertexBuffers(0, 1, &_geometry.vertexBuffer, &_geometry.vertexBufferStride, &_geometry.vertexBufferOffset);
	pImmediateContext->IASetIndexBuffer(_geometry.indexBuffer, DXGI_FORMAT_R16_UINT, 0);

	pImmediateContext->DrawIndexed(_geometry.numberOfIndices, 0, 0);
}
