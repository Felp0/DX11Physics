#pragma once
#include<iostream>
#include<math.h>
#include<assert.h>

class Vector3D
{
public:
	float x, y, z;

	//Constructor
	Vector3D();
	~Vector3D();
	
	Vector3D(float xl, float yl, float zl = 0);

	//Operators
	Vector3D operator+(const Vector3D &vec); //addition
	Vector3D &operator+=(const Vector3D &vec); //assign new result to vector
	Vector3D operator-(const Vector3D &vec); //Subtraction
	Vector3D &operator-=(const Vector3D &vec); //assign new result to vector
	Vector3D operator*(float value); //multiplication
	Vector3D &operator*=(float value); //assign new result to vector
	Vector3D operator/(float value); //division
	Vector3D &operator/=(float value); //assign new result to vector
	Vector3D &operator=(const Vector3D &vec);

	//Vector operations
	float Dot_product(const Vector3D& vec); //scalar dot_product
	Vector3D Cross_product(const Vector3D& vec); //cross_prodcut
	Vector3D Normalization(); //normalized vector

	//Scalar operations
	float Square(); //gives square of the vector
	float Distance(const Vector3D &vec); //disctance between two vectors
	float Magnitude(); //magnitured of the vector


};

