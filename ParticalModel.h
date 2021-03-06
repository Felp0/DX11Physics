#pragma once
#include <directxmath.h>
#include <d3d11_1.h>
#include "Vector3D.h"
#include "Debug.h"

#include <vector>


class Transform;



using namespace DirectX;
using namespace std;

class ParticleModel
{
public:

	ParticleModel(Transform* transform, bool useConstVelocity, bool useDrag, float mass, Vector3D netForce, Vector3D velocity, Vector3D acceleration);
	ParticleModel() {}
	~ParticleModel() {}

	void Update(float deltatime);
	void UpdateAcceleration(float deltatime);
	void UpdateNetForce(float deltatime);
	void DragForce();
	void DragLamForce(Vector3D velocity);
	void DragTurbForce(Vector3D velocity);
	void MoveConstantVelocity( float deltaTime);
	void SetConstantVelocity(Vector3D velocity);
	void SetAcceleration(Vector3D acceleration);
	void SetAcceleration(float x, float y, float z) { m_acceleration.x = x, m_acceleration.y = y, m_acceleration.z = z; }
	void SetVelocity(float x, float y, float z) { m_velocity.x = x, m_velocity.y = y, m_velocity.z = z; }
	void SetMass(float mass);
	void SetNetForce(Vector3D netforce);
	void SetUsingConstVec(bool set);
	void SetWeight(Vector3D weight);
	void SetGravity(Vector3D gravity);
	void Move(float deltaTime);
	void Break(float deltaTime);
	void AddForce(Vector3D IncomingForce);
	void SetUseGravity(bool in) { m_UseGravity = in; }

	Vector3D GetConstantVelocity() { return m_velocity; }
	Vector3D GetAcceleration() { return m_acceleration; }
	Vector3D GetNetForce() { return m_netForce; }
	Vector3D GetWeight() { return m_weight; }
	Vector3D GetGravity() { return m_gravity; }
	
	Vector3D m_velocity;
	Vector3D m_acceleration;
	Vector3D m_netForce;
	Vector3D m_force;
	Vector3D m_weight;
	Vector3D m_gravity;
	Vector3D m_cubeDragForce;

	Transform* _transform;

	float GetMass() { return m_mass; }

	float m_mass;
	float m_density;
	float m_dragCoefficient;
	float m_referenceArea;
	float m_dragFactor;

	bool m_useConstVelocity;
	bool m_useDrag;
	bool m_UseGravity = true;

	

	//vector<GameObject*> _gameObjects;
};