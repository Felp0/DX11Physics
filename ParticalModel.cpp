#include "ParticalModel.h"
#include "Transform.h"

ParticalModel::ParticalModel(Transform* transform, bool useConstVelocity, float mass, Vector3D netForce, Vector3D velocity, Vector3D acceleration) 
{
	m_velocity = velocity;
	m_acceleration = acceleration;
	m_useConstVelocity = useConstVelocity;
	m_mass = mass;
	m_netForce = netForce;
	_transform = transform;


}


void ParticalModel::UpdateNetForce(float deltatime)
{


	m_netForce.x += m_force.x;
	m_netForce.y += m_force.y;
	m_netForce.z += m_force.z;
}

void ParticalModel::UpdateAcceleration(float deltatime)
{

		m_acceleration.x = m_netForce.x / m_mass;
		m_acceleration.y = m_netForce.y / m_mass;
		m_acceleration.z = m_netForce.z / m_mass;

}

void ParticalModel::AddForce(Vector3D IncomingForce)
{
	//m_netForce = Vector3D(0.0f, 0.0f, 0.0f);

	m_netForce.x += IncomingForce.x;
	m_netForce.y += IncomingForce.y;
	m_netForce.z += IncomingForce.z;

	
}

void ParticalModel::MoveConstantVelocity( float deltaTime)
{
	_transform->SetPosition(_transform->GetPosition() + GetConstantVelocity() * deltaTime + m_acceleration * 0.5f * deltaTime * deltaTime);

	m_velocity = GetConstantVelocity() + m_acceleration * deltaTime;
}


void ParticalModel::Move(float deltaTime)
{
	
	  _transform->SetPosition(_transform->GetPosition().x + GetConstantVelocity().x* deltaTime + m_acceleration.x * 0.5f * deltaTime * deltaTime,
		_transform->GetPosition().y + GetConstantVelocity().y * deltaTime + m_acceleration.y * 0.5f * deltaTime * deltaTime,
		_transform->GetPosition().z + GetConstantVelocity().z * deltaTime + m_acceleration.z + 0.5f * deltaTime * deltaTime);

	SetVelocity(m_velocity.x + m_acceleration.x * deltaTime,
		m_velocity.y + m_acceleration.y * deltaTime,
		m_velocity.z + m_acceleration.y * deltaTime);
}

void ParticalModel::Break(float deltaTime)
{

}

void ParticalModel::Update(float deltatime)
{
	
		
	
	
	UpdateNetForce(deltatime);
	UpdateAcceleration(deltatime);

	
	Move(deltatime);

	m_netForce = Vector3D(0.0f, 0.0f, 0.0f);
	m_acceleration = Vector3D(0.0f, 0.0f, 0.0f);

}
void ParticalModel::SetConstantVelocity(Vector3D velocity)
{
	m_velocity = velocity;
}

void ParticalModel::SetAcceleration(Vector3D acceleration)
{
	m_acceleration = acceleration;
}

void ParticalModel::SetMass(float mass)
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