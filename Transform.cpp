#include "Transform.h"
#include "GameObject.h"

Transform::Transform()
{
	_parent = nullptr;
	_position = Vector3D();
	_rotation = Vector3D();
	_scale = Vector3D(1.0f, 1.0f, 1.0f);

}

void Transform::Update(float t)
{
	XMMATRIX scale = XMMatrixScaling(_scale.x, _scale.y, _scale.z);
	XMMATRIX rotation = XMMatrixRotationX(_rotation.x) * XMMatrixRotationY(_rotation.y) * XMMatrixRotationZ(_rotation.z);
	XMMATRIX translation = XMMatrixTranslation(_position.x, _position.y, _position.z);

	XMStoreFloat4x4(&_world, scale * rotation * translation);

	if (_parent != nullptr)
	{
		XMStoreFloat4x4(&_world, this->GetWorldMatrix() * GetWorldMatrix());
	}
}