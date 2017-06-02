#pragma once
struct float3
{
	float x;
	float y;
	float z;

	float3 operator-();

	friend float3 operator-(float3, const float3&);
	friend float3 operator*(float3, const float);

	float3& operator+=(const float3& rs);
	float3& operator*=(const float s);

	void clear();
};
