#pragma once

enum class eComponentType
{
	TRANSFORM,
	SCRIPT,
	CAMERA,
	SPRITE,
	END
};

enum class eLayerType
{
	NONE,
	BACKGROUND,
	LAYER1,
	LAYER2,
	LAYER3,  
	END
};

enum class eResourceType
{
	NONE,
	TEXTURE,
	ANIMATION,
	SOUNDCLIP,
	END
};

enum class eTextureType
{
	BMP,
	PNG,
	JPG,
	END
};