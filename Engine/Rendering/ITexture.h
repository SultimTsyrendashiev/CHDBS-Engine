#pragma once


enum class TextureType
{
	Diffuse = 0,
	Specular = 1,
	Normal = 2,
	Height = 3,
	Emission = 4,
	Detail = 5,
	Cubemap = 6,
	Shadowmap = 7
};

// all texture names must be same size
// last char is for index
#define TEXTURE_NAME_DIFFUSE	"t_diff0"
#define TEXTURE_NAME_SPECULAR	"t_spec0"
#define TEXTURE_NAME_NORMAL		"t_norm0"
#define TEXTURE_NAME_HEIGHT		"t_hght0"
#define TEXTURE_NAME_EMISSION	"t_emis0"
#define TEXTURE_NAME_DETAIL		"t_detl0"
#define TEXTURE_NAME_CUBEMAP	"t_cube0"
#define TEXTURE_NAME_SHADOWMAP	"t_shdw0"

// index of varying char in texture name
#define TEXTURE_NAME_LENGTH		7
#define TEXTURE_TYPES_COUNT		8

class ITexture
{
	friend class RenderingSystem;

protected:
	TextureID textureId;
	UINT graphicsTextureId;

	int width, height;
	int channelsNumber;
	UINT format;

	TextureType type;

public:
	// Activate this texture
	virtual void Activate(int i) const = 0;
	// Deactivate this texture
	virtual void Deactivate() const = 0;

	TextureType GetType() const;
	UINT GetID() const;
	int GetWidth() const;
	int GetHeight() const;
	UINT GetFormat() const;

	void SetType(TextureType t);
};

inline UINT ITexture::GetID() const
{
	return graphicsTextureId;
}

inline void ITexture::SetType(TextureType t)
{
	type = t;
}

inline TextureType ITexture::GetType() const
{
	return type;
}

inline int ITexture::GetWidth() const
{
	return width;
}

inline int ITexture::GetHeight() const
{
	return height;
}

inline UINT ITexture::GetFormat() const
{
	return format;
}