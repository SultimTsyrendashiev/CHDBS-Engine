#pragma once

#include <Engine\Rendering\Shader.h>
#include <Engine\Rendering\Texture.h>
#include <vector>

class Material
{
	friend class RenderingSystem;

private:
	MaterialID materialId;

protected:
	Shader shader;
	// must be <= 16
	std::vector<ITexture> textures;

public:
	Material(std::vector<ITexture> textures = std::vector<ITexture>());

	// Init material from XML element
	bool Init(void* xmlElem);

	// Activate material
	void Activate() const;
	// Add texture to material
	void AddTexture(const ITexture &t);
	// Bind shader
	void BindShader(const Shader &shader);
	// Bind model matrix
	void BindModelMatrix(const Matrix4 &model);

	// Getters
	Shader &GetShader();
	const Shader &GetShader() const;
};