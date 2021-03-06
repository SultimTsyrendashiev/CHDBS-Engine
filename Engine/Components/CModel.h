#pragma once

#include "IComponent.h"
#include <Engine/DataStructures/StaticArray.h>
#include <Engine/ResourceManager/ModelResource.h>
#include <Engine/Rendering/IModel.h>
#include <Engine/Math/Matrix.h>

// Represents static model
class CModel : public IComponent, public IModel
{
	CLASSDECLARATION(CModel)

public:
	UINT				modelId;

	// Resource, loaded from file
	const ModelResource	*modelResource;
	// Transformation matrix for correction for loaded model
	Matrix4				correctionMatrix;

	// Arrays for rendering
	StaticArray<UINT>	vaos, vbos, ibos;

	// Path to file
	String				path;

	// Shader to use
	String				shader;

	// Forced diffuse texture path
	// Use this if there are no textures
	String				forcedDiffuseTexture;

public:
	// Does model cast shadows?
	bool IsCastingShadows;
	// Does model receive shadows?
	bool IsReceivingShadows;

protected:
	static void InitMesh(const MeshResource *resource, UINT &vao, UINT &vbo, UINT &ibo, bool useTan, bool dynamic);
	// Init as static model
	void InitStatic();

public:
	// Default constructor
	CModel();

	// Loads model from file
	void Init() override;
	void Update() override;
	void SetProperty(const String &key, const String &value) override;

	// Bind shader for each material
	void BindShader(const char *shaderName);

	const StaticArray<MeshResource*>		&GetMeshes()	const override;
	const StaticArray<StandardMaterial*>	&GetMaterials()	const override;
	const StaticArray<UINT>					&GetVAO()		const override;

	// Calculate tranformation matrices foreach mesh
	// with current entity's tranform
	const StaticArray<Matrix4>				&GetTranforms()	const override;

	// Calculate tranformation matrices foreach mesh
	// with current entity's tranform converted to global space
	const StaticArray<Matrix4>				&GetTranforms(const Matrix4 &global) const override;
};

inline const StaticArray<Matrix4> &CModel::GetTranforms() const
{
	return modelResource->GetHierarchy().GetTranforms(correctionMatrix * owner->GetTransform().GetTransformMatrix());
}

inline const StaticArray<Matrix4>& CModel::GetTranforms(const Matrix4 &global) const
{
	return modelResource->GetHierarchy().GetTranforms(correctionMatrix * owner->GetTransform().GetTransformMatrix() * global);
}
