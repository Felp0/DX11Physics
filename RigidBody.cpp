#include "RigidBody.h"
#include "Transform.h"


RigidBody::RigidBody(Transform* transform, bool useConstVelocity, bool useDrag, float mass, Vector3D netForce, Vector3D velocity, Vector3D acceleration) : 
	ParticleModel(transform, useConstVelocity, useDrag, mass, netForce, velocity, acceleration)
{
	XMFLOAT3X3 m_intertiaMatrix = XMFLOAT3X3();

	

	m_intertiaMatrix._11 = mass* ( std::pow(1,2) / 6 );//mass
	m_intertiaMatrix._12 = 0;
	m_intertiaMatrix._13 = 0;

	m_intertiaMatrix._21 = 0;
	m_intertiaMatrix._22 = mass * (std::pow(1, 2) / 6);//mass
	m_intertiaMatrix._23 = 0;

	m_intertiaMatrix._31 = 0;
	m_intertiaMatrix._32 = 0;
	m_intertiaMatrix._33 = mass * (std::pow(1, 2) / 6);//mass

	m_intertiaTensor = XMLoadFloat3x3(&m_intertiaMatrix);


	m_angularDamping = 0.99f;
	m_angularAcceleration = XMFLOAT3(0.0f, 0.0f, 0.0f);
	m_angularVelocity = XMFLOAT3(0.0f, 0.0f, 0.0f);
	m_torque = XMFLOAT3(0.0f, 0.0f, 0.0f);

}

XMVECTOR RigidBody::TorqueVector(XMFLOAT3 force, XMFLOAT3 position)
{

	XMVECTOR vectorPosition = XMLoadFloat3(&position);
	XMVECTOR vectorForce = XMLoadFloat3(&force);

	XMVECTOR temp = XMLoadFloat3(&m_torque);

	temp = XMVector3Cross(vectorPosition, vectorForce);

	XMStoreFloat3(&m_torque, temp);

	return temp;
	
}
void RigidBody::angularAcceleration()
{
	
	

	XMMATRIX m_inverse = XMMatrixInverse(nullptr, m_intertiaTensor);

	XMVECTOR m_angular = XMVector3Transform(XMLoadFloat3(&m_torque), m_intertiaTensor);

	XMVECTOR temp = XMLoadFloat3(&m_angularAcceleration);

	//temp = XMVector3Transform(TorqueVector(XMFLOAT3(1.0f, 1.0f, 1.0f), XMFLOAT3(1.0f, 1.0f, 1.0f)), m_inverse);

	XMStoreFloat3(&m_angularAcceleration, m_angular);
}

void RigidBody::updateAngularVelocity(float deltaTime)
{
	XMVECTOR angularV = XMLoadFloat3(&m_angularVelocity);
	XMVECTOR tempAcceleration = XMLoadFloat3(&m_angularAcceleration);

	angularV = angularV + tempAcceleration * deltaTime;

	XMStoreFloat3(&m_angularVelocity, angularV);
	m_angularAcceleration = XMFLOAT3(0, 0, 0);
	m_torque = XMFLOAT3(0.0f, 0.0f, 0.0f);
}

void RigidBody::addDamping(float deltatime)
{
	XMVECTOR temp = XMLoadFloat3(&m_angularVelocity);
	

	temp = temp * m_angularDamping;

	XMStoreFloat3(&m_angularVelocity, temp);
}

void RigidBody::calculateAngle(float deltatime)
{
	
	Quaternion rotation = _transform->GetRotation();


	Vector3D angularVelocity;
	angularVelocity.x = m_angularVelocity.x;
	angularVelocity.y = m_angularVelocity.y;
	angularVelocity.z = m_angularVelocity.z;


	rotation.addScaledVector(angularVelocity, deltatime);
	rotation.normalise();

	
	_transform->SetRotation(rotation);
}

void RigidBody::update(float deltaTime)
{
	ParticleModel::Update(deltaTime);

	//TorqueVector(XMFLOAT3(0.0f, 0.0f, 2.0f), XMFLOAT3(1.0f, 1.0f, -1.0f));
	angularAcceleration();
	updateAngularVelocity(deltaTime);
	addDamping(deltaTime);
	calculateAngle(deltaTime);
}
