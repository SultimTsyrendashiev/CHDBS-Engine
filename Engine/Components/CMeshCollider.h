#pragma once
#include <Engine/Components/IComponent.h>
#include <Engine/Physics/MeshCollider.h>

class CMeshCollider : public MeshCollider, public IComponent
{
	CLASSDECLARATION(CMeshCollider)

private:
	// True, if collider must be created 
	// from current attached model with tranformations
	bool generateFromModel;

public:
	void Init() override;
	void Update() override;

	void SetProperty(const String &key, const String &value) override;

public:
	virtual const Transform &GetTransform() const override;
};