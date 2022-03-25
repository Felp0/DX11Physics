#include "ParticalModel.h"
#include "Transform.h"

ParticleModel::ParticleModel(Transform* transform, bool useConstVelocity, float mass, Vector3D netForce, Vector3D velocity, Vector3D acceleration) 
{
	m_gravity = Vector3D(0.0f, -9.8f, 0.0f);
	m_velocity = velocity;
	m_acceleration = acceleration;
	m_useConstVelocity = useConstVelocity;
	m_mass = mass;
	m_netForce = netForce;
	m_weight = m_gravity * m_mass;
	_transform = transform;

	//turbulant
	/*float temp = 0.5f * m_density * m_dragCoefficient * m_referenceArea;
	Vector3D drag = velocity;
	drag.Normalization();
	drag = drag * drag * temp;*/


	//Laminar
	//float temp = 0.5f * m_density * m_dragCoefficient * m_referenceArea;
	//Vector3D drag = velocity;
	//drag.Normalization();
	//drag = drag * temp;
}


void ParticleModel::UpdateNetForce(float deltatime)
{
	m_netForce.x += m_force.x;
	m_netForce.y += m_force.y;
	m_netForce.z += m_force.z;
}

void ParticleModel::UpdateAcceleration(float deltatime)
{
	m_acceleration.x = m_netForce.x / m_mass;
	m_acceleration.y = m_netForce.y / m_mass;
	m_acceleration.z = m_netForce.z / m_mass;
}

void ParticleModel::AddForce(Vector3D IncomingForce)
{
	m_netForce.x += IncomingForce.x;
	m_netForce.y += IncomingForce.y;
	m_netForce.z += IncomingForce.z;
}

void ParticleModel::MoveConstantVelocity( float deltaTime)
{
	_transform->SetPosition(_transform->GetPosition() + GetConstantVelocity() * deltaTime + m_acceleration * 0.5f * deltaTime * deltaTime);

	m_velocity = GetConstantVelocity() + m_acceleration * deltaTime;
}


void ParticleModel::Move(float deltaTime)
{
	
	  _transform->SetPosition(_transform->GetPosition().x + GetConstantVelocity().x* deltaTime + m_acceleration.x * 0.5f * deltaTime * deltaTime,
		_transform->GetPosition().y + GetConstantVelocity().y * deltaTime + m_acceleration.y * 0.5f * deltaTime * deltaTime,
		_transform->GetPosition().z + GetConstantVelocity().z * deltaTime + m_acceleration.z + 0.5f * deltaTime * deltaTime);

	SetVelocity(m_velocity.x + m_acceleration.x * deltaTime,
		m_velocity.y + m_acceleration.y * deltaTime,
		m_velocity.z + m_acceleration.y * deltaTime);
}

void ParticleModel::Break(float deltaTime)
{

}

void ParticleModel::Update(float deltatime)
{
	
		
	
	
	UpdateNetForce(deltatime);
	UpdateAcceleration(deltatime);

	
	Move(deltatime);

	m_netForce = Vector3D(0.0f, 0.0f, 0.0f);
	m_acceleration = Vector3D(0.0f, 0.0f, 0.0f);

}
void ParticleModel::SetConstantVelocity(Vector3D velocity)
{
	m_velocity = velocity;
}

void ParticleModel::SetAcceleration(Vector3D acceleration)
{
	m_acceleration = acceleration;
}

void ParticleModel::SetMass(float mass)
{
	m_mass = mass;
}

void ParticleModel::SetNetForce(Vector3D netforce)
{
	m_netForce = netforce;
}

void ParticleModel::SetUsingConstVec(bool set)
{
	m_useConstVelocity = set;
}

void ParticleModel::SetWeight(Vector3D weight)
{
	m_weight = weight;
}

void ParticleModel::SetGravity(Vector3D gravity)
{
	m_gravity = gravity;
}
