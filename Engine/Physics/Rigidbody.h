#pragma once
#include <Engine/Components/IComponent.h>
#include <Engine/Math/Vector.h>
#include <Engine/Math/Transform.h>
#include <Engine/DataStructures/DynamicArray.h>
#include <Engine/Math/AABB.h>

class Rigidbody : public IComponent
{
private:
	// pointer to current transform
	Transform	&transform;
	Vector3		velocity;
	float		mass;

	DynamicArray<Vector3> allForces;
	DynamicArray<Vector3> allImpulses;

	AABB collider;
	
public:
	void AddForce(const Vector3 &force);
	void AddImpulse(const Vector3 &impulse);

	void FixedUpdate();

public:
	// Initialization as component
	void Init() override;
	// Empty update function
	// Rigidbodies are updated in PhysicsSystem through FixedUpdate()
	void Update() override {};
};