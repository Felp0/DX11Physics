#pragma once

#include "ParticalModel.h"
#include "Quaternion.h"

class RigidBody
{
public:

	RigidBody();
	
	

	XMVECTOR TorqueVector(XMFLOAT3 force, XMFLOAT3 position);
	void updateAngularVelocity( float deltaTime);
	void addDamping(float deltatime);
	void calculateAngle(float deltaTime);
	void update(float deltaTime);

	void angularAcceleration();


	XMFLOAT3X3		m_intertiaTensor;

	XMFLOAT3		m_angularAcceleration;
	XMFLOAT3		m_torque;
	XMFLOAT3		m_angularVelocity;

	float			m_angularDamping;

};

