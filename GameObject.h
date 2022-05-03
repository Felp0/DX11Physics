

#pragma once

#include <directxmath.h>
#include <d3d11_1.h>
#include <string>
#include "Transform.h"
#include "Apperance.h"
#include "RigidBody.h"

using namespace DirectX;
using namespace std;

//struct Geometry
//{
//	ID3D11Buffer* vertexBuffer;
//	ID3D11Buffer* indexBuffer;
//	int numberOfIndices;
//
//	UINT vertexBufferStride;
//	UINT vertexBufferOffset;
//};
//
//struct Material
//{
//	XMFLOAT4 diffuse;
//	XMFLOAT4 ambient;
//	XMFLOAT4 specular;
//	float specularPower;
//};

class GameObject
{
public:
	GameObject(string type, Apperance* apperance, Transform* transform, RigidBody* rigidbody);
	~GameObject();

	// Setters and Getters for position/rotation/scale
	/*void SetPosition(XMFLOAT3 position) { _position = position; }
	void SetPosition(float x, float y, float z) { _position.x = x; _position.y = y; _position.z = z; }

	XMFLOAT3 GetPosition() const { return _position; }

	void SetScale(XMFLOAT3 scale) { _scale = scale; }
	void SetScale(float x, float y, float z) { _scale.x = x; _scale.y = y; _scale.z = z; }

	XMFLOAT3 GetScale() const { return _scale; }

	void SetRotation(XMFLOAT3 rotation) { _rotation = rotation; }
	void SetRotation(float x, float y, float z) { _rotation.x = x; _rotation.y = y; _rotation.z = z; }

	XMFLOAT3 GetRotation() const { return _rotation; }*/

	string GetType() const { return _type; }

	//Geometry GetGeometryData() const { return _geometry; }

	/*Material GetMaterial() const { return _material; }*/

	/*XMMATRIX GetWorldMatrix() const { return XMLoadFloat4x4(&_world); }*/

	/*void SetTextureRV(ID3D11ShaderResourceView* textureRV) { _textureRV = textureRV; }
	ID3D11ShaderResourceView* GetTextureRV() const { return _textureRV; }
	bool HasTexture() const { return _textureRV ? true : false; }*/

	/*void SetParent(GameObject * parent) { _parent = parent; }*/

	void Update(float t);
	void Draw(ID3D11DeviceContext* pImmediateContext);


	Transform* _transform;
	ParticleModel* _model;
	Apperance* _apperance;
	RigidBody* _rigid;
	

	Apperance* GetApperance() const { return _apperance; }
	Transform* GetTransform() const { return _transform; }
	RigidBody* GetRigidBody() const { return _rigid; }



private:
	//XMFLOAT3 _position; //3D position
	//XMFLOAT3 _rotation; //3D position
	//XMFLOAT3 _scale; //3D position

	string _type;

	//XMFLOAT4X4 _world;

	//Geometry _geometry;
	/*Material _material;*/

	/*ID3D11ShaderResourceView* _textureRV;*/

	//GameObject * _parent;

};

