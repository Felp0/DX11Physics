#include "Vector3D.h"

Vector3D::Vector3D()
{
	x = 0;
	y = 0;
	z = 0;
}

Vector3D::Vector3D(float xl, float yl, float zl )
{
	x = xl;
	y = yl;
	z = zl;
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
	float ni = y * vec.z - z * vec.y;
	float nj = z * vec.x - x * vec.z;
	float nk = x * vec.y - y * vec.x;

	return Vector3D(ni, nj, nk);
}

float Vector3D::Dot_product(const Vector3D& vec)
{
	return x * vec.x + vec.y * y + vec.z * z;
}

Vector3D Vector3D::Normalization()
{
	assert(Magnitude()!= 0);
	*this /= Magnitude();
	return *this;
}

float Vector3D::Magnitude()
{
	return sqrt(Square());
}

float Vector3D::Square()
{
	return x * x + y * y + z * z;
}

float Vector3D::Distance(const Vector3D& vec)
{
	Vector3D distance = *this - vec;
	return distance.Magnitude();

}
