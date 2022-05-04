#include "Transform.h"
#include "GameObject.h"

Transform::Transform()
{
	_parent = nullptr;
	_position = Vector3D();
	_rotation = Vector3D();
	_scale = Vector3D(1.0f, 1.0f, 1.0f); 
}

void Transform::SetRotation(Vector3D rotation)
{
	SetRotation(rotation.x, rotation.y, rotation.z);
}

void Transform::SetRotation(float x, float y, float z)
{
	XMVECTOR quaternion = XMQuaternionRotationRollPitchYaw(XMConvertToRadians(x), XMConvertToRadians(y), XMConvertToRadians(z));
	XMFLOAT4 temp;


	XMStoreFloat4(&temp, quaternion);


	_orientation.r = temp.w;
	_orientation.i = temp.x;
	_orientation.j = temp.y;
	_orientation.k = temp.z;
}

void Transform::Update(float t)
{
	XMMATRIX scale = XMMatrixScaling(_scale.x, _scale.y, _scale.z);

	XMMATRIX rotation; 
	CalculateTransformMatrixRowMajor(rotation, Vector3D(0.0f, 0.0f, 0.0f), _orientation);

	XMMATRIX translation = XMMatrixTranslation(_position.x, _position.y, _position.z);

	XMStoreFloat4x4(&_world, scale * rotation * translation);

	if (_parent != nullptr)
	{
		XMStoreFloat4x4(&_world, this->GetWorldMatrix() * GetWorldMatrix());
	}
}