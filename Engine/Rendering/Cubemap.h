#pragma once
#include "ITexture.h"

class Cubemap : public ITexture
{
public:
	// Default constructor
	Cubemap();

	// Init cubemap from 6 files.
	// Order: right, left, top, bottom, front, back
	void LoadCubemap(const Array<const char*, 6> &paths);

	// Activate this texture
	void Activate(int i) const override;
};