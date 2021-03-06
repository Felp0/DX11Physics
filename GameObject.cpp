#include "GameObject.h"

GameObject::GameObject(string type, Apperance* apperance, Transform* transform, RigidBody* rigidbody) : _type(type)
{


	_transform = transform;
	_apperance = apperance;
	_rigid = rigidbody;

	
}

GameObject::~GameObject()
{
}

void GameObject::Update(float t)
{
	_rigid->update(t);
	_transform->Update(t);
}

void GameObject::Draw(ID3D11DeviceContext* pImmediateContext)
{
	// NOTE: We are assuming that the constant buffers and all other draw setup has already taken place

	// Set vertex and index buffers
	//pImmediateContext->IASetVertexBuffers(0, 1, &_geometry.vertexBuffer, &_geometry.vertexBufferStride, &_geometry.vertexBufferOffset);
	//pImmediateContext->IASetIndexBuffer(_geometry.indexBuffer, DXGI_FORMAT_R16_UINT, 0);

	//pImmediateContext->DrawIndexed(_geometry.numberOfIndices, 0, 0);

	_apperance->Draw(pImmediateContext);
}
