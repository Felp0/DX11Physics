#pragma once
#include <directxmath.h>
#include <d3d11_1.h>
#include "Vector3D.h"
#include "Debug.h"

class Transform;

using namespace DirectX;
using namespace std;

class ParticalModel
{
public:

	ParticalModel();
	~ParticalModel();

	void Update(float t);

	void MoveConstantVelocity( float deltaTime);
	void SetConstantVelocity(Vector3D m_setVelocity);
	void SetAcceleration(Vector3D m_setAcceleration);

	Vector3D GetConstantVelocity() { return m_velocity; }

	Vector3D GetAcceleration() { return m_acceleration; }

	Vector3D m_velocity;
	Vector3D m_setVelocity;

	Vector3D m_acceleration;
	Vector3D m_setAcceleration;

	Transform* _transform;
};