#include "ParticalModel.h"
#include "Transform.h"

ParticalModel::ParticalModel()
{
	m_velocity = Vector3D(1.0f, 0.0f, 0.0f);
	m_acceleration = Vector3D();

}

void ParticalModel::Update(float t)
{
	if (GetKeyState('7') & 0x8000)
	{
		
		MoveConstantVelocity(t);
	}
}

void ParticalModel::MoveConstantVelocity( float deltaTime)
{
	_transform->SetPosition(_transform->GetPosition() + GetConstantVelocity() * deltaTime + m_acceleration * 0.5f * deltaTime * deltaTime);

	m_velocity = GetConstantVelocity() + m_acceleration * deltaTime;
}

void ParticalModel::SetConstantVelocity(Vector3D m_setVelocity)
{
	m_velocity = m_setVelocity;
}

void ParticalModel::SetAcceleration(Vector3D m_setAcceleration)
{
	m_acceleration = m_setAcceleration;
}
