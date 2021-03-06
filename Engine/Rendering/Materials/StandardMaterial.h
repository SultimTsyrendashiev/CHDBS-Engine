#pragma once

#include <Engine/Math/Matrix.h>
#include <Engine/Rendering/Material.h>
#include <Engine/Rendering/ILight.h>

#define MAX_LIGHT_COUNT 4

// Represents material which is affected by light in 3D space
class StandardMaterial : public Material
{
private:
	// Model transformation shader location
	int modelMatrixLoc;

	// Camera position shader location
	int cameraPosLoc;
	// Camera space shader location
	int cameraSpaceLoc;
	
	// Shadowmap shader location
	int shadowLoc;

	// Main reflection cubemap
	const Cubemap *reflectionCubemap;

	// Main color shader location
	int mainColorLoc;
	// Specular color shader location
	int specularLoc;
	// Smoothness (float) shader location
	int smoothnessLoc;

	// int lightDirLoc;
	int lightSpaceLoc;
	int lightCountLoc;

	struct LightUniforms
	{
		int positionLoc;
		int colorLoc;
		int attenLoc;
		int coneAngleLoc;
		int coneDirLoc;

	} lightUniforms[MAX_LIGHT_COUNT];

private:
	void InitLightUniforms();

	void ActivateAdditional() const override;
	void DeactivateAdditional() const override;

public:
	void InitUniformLocations() override;

	void SetModel(const Matrix4 &m);

	void SetCameraPosition(const Vector3 &pos);
	void SetCameraSpace(const Matrix4 &vp);

	void SetLightCount(int count);
	void SetLight(const ILight &light, int index);

	void SetLightSpace(const Matrix4 & vp);

	void SetReflectionCubemap(const Cubemap *cubemap);

	void SetMainColor(const Color4F & c);
	void SetSpecularColor(const Color4F & c);
	void SetSmoothness(float s);

	void ActivateShadowMap();
};