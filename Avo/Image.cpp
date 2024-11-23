#include "pch.h"
#include "Image.h"

namespace Avo
{
	bool Image::HasImage() const
	{
		return implementation->HasImage();
	}

	int Image::GetWidth() const
	{
		return implementation->GetWidth();
	}

	int Image::GetHeight() const
	{
		return implementation->GetHeight();
	}
}