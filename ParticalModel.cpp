#include "ParticalModel.h"
#include "Transform.h"

ParticalModel::ParticalModel(Transform* transform, bool useConstVelocity, Vector3D mass, Vector3D netForce, Vector3D velocity, Vector3D acceleration)
{
	m_velocity = velocity;
	m_acceleration = acceleration;
	m_useConstVelocity = useConstVelocity;
	m_mass = mass;
	m_netForce = netForce;



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


void ParticalModel::Move(int objectNumber,float deltaTime)
{
	//Vector3D position = _gameObjects[objectNumber]->_transform->GetPosition();
	Vector3D velocity = GetConstantVelocity();
	
	

	  _transform->SetPosition(_transform->GetPosition().x + GetConstantVelocity().x* deltaTime + m_acceleration.x * 0.5f * deltaTime * deltaTime,
		_transform->GetPosition().y + GetConstantVelocity().y * deltaTime + m_acceleration.y * 0.5f * deltaTime * deltaTime,
		_transform->GetPosition().z + GetConstantVelocity().z * deltaTime + m_acceleration.z + 0.5f * deltaTime * deltaTime);

	SetVelocity(m_velocity.x + m_acceleration.x * deltaTime,
		m_velocity.y + m_acceleration.y * deltaTime,
		m_velocity.z + m_acceleration.y * deltaTime);
}

void ParticalModel::Break(int objectNumber,float deltaTime)
{

}

void ParticalModel::SetConstantVelocity(Vector3D velocity)
{
	m_velocity = velocity;
}

void ParticalModel::SetAcceleration(Vector3D acceleration)
{
	m_acceleration = acceleration;
}

void ParticalModel::SetMass(Vector3D mass)
{
	m_mass = mass;
}

void ParticalModel::SetNetForce(Vector3D netforce)
{
	m_netForce = netforce;
}

void ParticalModel::SetUsingConstVec(bool set)
{
	m_useConstVelocity = set;
}