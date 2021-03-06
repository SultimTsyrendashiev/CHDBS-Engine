#pragma once
#include "Vector.h"

// Stores only refernces to points
class Triangle
{
public:
	union
	{
		Vector3 ABC[3];
		struct
		{
			Vector3 A, B, C;
		};
	};

public:
	Triangle() {}
	Triangle(const Vector3 & a, const Vector3 & b, const Vector3 & c);

	inline Vector3 &operator[](int index);
	inline const Vector3 &operator[](int index) const;

	// Get closest point on triangle abc
	static Vector3 GetClosestPoint(const Vector3 &p, const Vector3 &a, const Vector3 &b, const Vector3 &c);
	// Get closest point on this triangle
	inline Vector3 GetClosestPoint(const Vector3 &p) const;
	// Get cartesian coords from barycentric
	inline Vector3 GetCartesian(const Vector3 &barycentric) const;
	// Get normal
	inline Vector3 GetNormal() const;
};

inline Vector3 Triangle::GetClosestPoint(const Vector3 & p) const
{
	return GetClosestPoint(p, A, B, C);
}

inline Vector3 Triangle::GetCartesian(const Vector3 & barycentric) const
{
	return A * barycentric[0] + B * barycentric[1] + C * barycentric[2];
}

inline Vector3 Triangle::GetNormal() const
{
	Vector3 ab = B - A;
	Vector3 ac = C - A;

	return Vector3::Cross(ab, ac);
}

inline Vector3 &Triangle::operator[](int index)
{
	ASSERT(index >= 0 && index <= 2);
	return ABC[index];
}

inline const Vector3 & Triangle::operator[](int index) const
{
	ASSERT(index >= 0 && index <= 2);
	return ABC[index];
}