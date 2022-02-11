#include "Vector3D.h"

Vector3D::Vector3D()
{
	x = 0;
	y = 0;
	z = 0;
}

Vector3D::Vector3D(float xl, float yl, float zl = 0)
{
	x = xl;
	y = yl;
	z = yl;
}


#pragma region Operators


Vector3D Vector3D::operator+(const Vector3D &vec)
{
	return Vector3D(x += vec.x, y += vec.y, z += vec.z);
}

Vector3D &Vector3D::operator+=(const Vector3D &vec)
{
	x += vec.x;
	y += vec.y;
	z += vec.z;

	return *this;

}

Vector3D Vector3D::operator-(const Vector3D& vec)
{
	return Vector3D(x -= vec.x, y -= vec.y, z -= vec.z);
}

Vector3D& Vector3D::operator-=(const Vector3D& vec)
{
	x -= vec.x;
	y -= vec.y;
	z -= vec.z;

	return *this;
}

Vector3D Vector3D::operator*(float value)
{
	return Vector3D(x * value, y * value, z * value);
}

Vector3D& Vector3D::operator*=(float value)
{
	x *= value;
	y *= value;
	z *= value;

	return *this;

}

Vector3D Vector3D::operator/(float value)
{
	assert(value != 0);
	return Vector3D(x / value, y / value, z / value);
}

Vector3D& Vector3D::operator/=(float value)
{
	assert(value != 0);
	x /= value;
	y /= value;
	z /= value;
	return *this;
}

Vector3D& Vector3D::operator=(const Vector3D& vec)
{
	x = vec.x;
	y = vec.y;
	z = vec.z;
	return *this;
}


#pragma endregion

Vector3D Vector3D::Cross_product(const Vector3D& vec)
{
	float ni = y*
}