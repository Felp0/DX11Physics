#include "RigidBody.h"


RigidBody::RigidBody()
{
	m_intertiaTensor = XMFLOAT3X3(m_intertiaTensor._11 = 11.0f, m_intertiaTensor._12 = 12.0f, m_intertiaTensor._13 = 13.0f, m_intertiaTensor._21 = 14.0f, m_intertiaTensor._22 = 22.0f,
								m_intertiaTensor._23 = 23.0f, m_intertiaTensor._31 = 31.0f, m_intertiaTensor._32 = 32.0f, m_intertiaTensor._33 = 33.0f);

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
	
	XMMATRIX m_intertia = XMLoadFloat3x3(&m_intertiaTensor);

	XMMATRIX m_inverse = XMMatrixInverse(&TorqueVector(XMFLOAT3(1.0f, 1.0f, 1.0f), XMFLOAT3(1.0f, 1.0f, 1.0f)), m_intertia);

	XMVECTOR m_angular = XMVector3Transform(TorqueVector(XMFLOAT3(1.0f,1.0f,1.0f),XMFLOAT3(1.0f,1.0f,1.0f)), m_intertia);

	XMVECTOR temp = XMLoadFloat3(&m_angularAcceleration);

	temp = XMVector3Transform(TorqueVector(XMFLOAT3(1.0f, 1.0f, 1.0f), XMFLOAT3(1.0f, 1.0f, 1.0f)), m_inverse);

	XMStoreFloat3(&m_angularAcceleration, temp);
}

void RigidBody::updateAngularVelocity(float deltaTime)
{
	XMFLOAT3 zero = XMFLOAT3(0.0f, 0.0f, 0.0f);

	XMVECTOR angularV = XMLoadFloat3(&zero);

	XMVECTOR temp = XMLoadFloat3(&m_angularVelocity);
	XMVECTOR tempAcceleration = XMLoadFloat3(&m_angularAcceleration);

	temp = angularV + tempAcceleration * deltaTime;

	XMStoreFloat3(&m_angularVelocity, temp);
	XMStoreFloat3(&m_angularAcceleration, tempAcceleration);



}

void RigidBody::addDamping(float deltatime)
{
	XMVECTOR temp = XMLoadFloat3(&m_angularVelocity);
	

	temp = temp * m_angularDamping * deltatime;

	XMStoreFloat3(&m_angularVelocity, temp);
}

void RigidBody::calculateAngle(float deltatime)
{
	Quaternion quaternion = Quaternion(2.0f, 2.0f, 2.0f, 1.0f);
	XMMATRIX m_intertia = XMLoadFloat3x3(&m_intertiaTensor);
	

	Vector3D bullshit;
	bullshit.x = m_angularVelocity.x;
	bullshit.y = m_angularVelocity.y;
	bullshit.z = m_angularVelocity.z;


	quaternion.addScaledVector(bullshit, deltatime);
	quaternion.normalise();

	CalculateTransformMatrixRowMajor(m_intertia, Vector3D(1.0f, 1.0f, 1.0f), quaternion);



}

void RigidBody::update(float deltaTime)
{
	angularAcceleration();
	TorqueVector(XMFLOAT3(5.0f, 5.0f, 5.0f), XMFLOAT3(1.0f, 1.0f, 1.0f));
	updateAngularVelocity(deltaTime);
	calculateAngle(deltaTime);
	addDamping(deltaTime);
}
