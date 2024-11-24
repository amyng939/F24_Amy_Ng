#pragma once

#include "pch.h"
#include "AvoUtilities.h"
#include "ImageImpl.h"

namespace Avo
{
	class AVO_API Image
	{
	public:
		Image();
		Image(const std::string& filePath);
		void LoadImage(const std::string& filePath);

		bool HasImage() const;
		int GetWidth() const;
		int GetHeight() const;

	private:
		void Bind();

		std::unique_ptr<ImageImpl> implementation;

		friend class Renderer;
	};
}