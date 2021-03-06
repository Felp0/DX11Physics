#pragma once

#include <directxmath.h>
#include <d3d11_1.h>
#include "Vector3D.h"
#include "Quaternion.h"

using namespace DirectX;
using namespace std;

class GameObject;

class Transform
{
public:

	Transform();

	void SetPosition(Vector3D position) { _position = position; }
	void SetPosition(float x, float y, float z) { _position.x = x; _position.y = y; _position.z = z; }


	Vector3D GetPosition() const { return _position; }
	
	void SetScale(Vector3D scale) { _scale = scale; }
	void SetScale(float x, float y, float z) { _scale.x = x; _scale.y = y; _scale.z = z; }

	Vector3D GetScale() const { return _scale; }

	void SetRotation(Vector3D rotation);
	void SetRotation(float x, float y, float z);
	void SetRotation(Quaternion orientation) { _orientation = orientation; }

	Quaternion GetRotation() const { return _orientation; }
	Vector3D GetRotationEuler() const{ return Vector3D(); }

	void SetParent(GameObject* parent) { _parent = parent; }

	XMMATRIX GetWorldMatrix() const { return XMLoadFloat4x4(&_world); }

	void Update(float t);
	


	Vector3D _position; //3D position
	Vector3D _rotation; //3D position
	Vector3D _scale; //3D position

	Quaternion _orientation;

	XMFLOAT4X4 _world;

	GameObject* _parent;
};