#pragma once
#include <Engine/Components/IComponent.h>
#include <Engine/Rendering/Particle.h>
#include <Engine/Rendering/Shader.h>
#include <Engine/Rendering/ICamera.h>
#include <Engine/Rendering/IParticleSystem.h>

class CParticleSystem : public IComponent, public IParticleSystem
{
	CLASSDECLARATION(CParticleSystem)

private:
	UINT vao;
	UINT vertexBuffer;
	UINT positionBuffer;
	UINT colorBuffer;
	
	UINT maxParticleCount = 0;
	// for finding
	UINT lastUsedParticle;
	// render only this number of particles
	// amount of alive particles
	UINT particleCount;

	Vector3 startVelocity;
	Vector3	velocityRandomness;
	bool	isWorldVelocity;

	Color4	startColor;
	float	colorRandomness;

	float	startSize;
	float	sizeRandomness;

	float	startRotation;
	float	rotationRandomness;

	float	startLifetime;
	float	lifetimeRandomness;

	float	gravityMultiplier;
	float	gravityMultRandomness;

	float	emitRate;
	bool	isLooping;

	// array of particles
	Particle		*particles;
	// array of positions and sizes
	Vector4			*positionsAndSizes;
	Color4			*colors;

	static float	quadVertices[];

	// special shader for rendering particles
	const Shader	*particleShader;
	String			shaderVert, shaderFrag;

	// store pointer to current transform
	// for fast access
	Transform *transform;

	// store pointer to camera
	// for sorting and aligning
	const ICamera *cam;

private:
	UINT FindDeadParticle();
	void GenerateParticle(const Vector3 &pos, const Vector3 &vel, const Color4 &col, float life, float rot, float size);

	void Simulate();
	void SortParticles();
	void StoreData();
	void ActivateShader();
	void LoadAndDraw();

public:
	~CParticleSystem();

	// Start emit particles with current emit rate
	void Start();
	// Emit particles
	void Emit(UINT count);
	// Emit particles with specified direction
	void Emit(UINT count, const Vector3 &direction);
	void Emit(UINT count, const Vector3 &direction, const Color4 &color);

	// Bind camera to render
	void BindCamera(const ICamera *cam) override;
	void Render() override;

public:
	void Init() override;
	void Update() override;

	void SetProperty(const String &key, const String &value) override;
};