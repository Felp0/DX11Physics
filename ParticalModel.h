#pragma once
#include <directxmath.h>
#include <d3d11_1.h>
#include "Vector3D.h"
#include "Debug.h"
#include <vector>


class Transform;


using namespace DirectX;
using namespace std;

class ParticalModel
{
public:

	ParticalModel(Transform* transform, bool useConstVelocity, Vector3D mass, Vector3D netForce, Vector3D velocity, Vector3D acceleration);
	~ParticalModel();

	void Update(float t);
	void MoveConstantVelocity( float deltaTime);

	void SetConstantVelocity(Vector3D velocity);
	void SetAcceleration(Vector3D acceleration);
	void SetVelocity(float x, float y, float z) { m_acceleration.x = x, m_acceleration.y = y, m_acceleration.z = z; }
	void SetMass(Vector3D mass);
	void SetNetForce(Vector3D netforce);
	void SetUsingConstVec(bool set);

	void Move(int objectNumber,float deltaTime);
	void Break(int objectNumber, float deltaTime);
	

	Vector3D GetConstantVelocity() { return m_velocity; }
	Vector3D GetAcceleration() { return m_acceleration; }
	Vector3D GetMass() { return m_mass; }
	Vector3D GetNetForce() { return m_netForce; }
	

	Vector3D m_velocity;
	Vector3D m_acceleration;
	Vector3D m_mass;
	Vector3D m_netForce;

	bool m_useConstVelocity;

	Transform* _transform;

	//vector<GameObject*> _gameObjects;
};