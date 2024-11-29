#pragma once

#include "pch.h"
#include "AvoUtilities.h"
#include "Image.h"
#include "Shaders.h"

namespace Avo
{
	class AVO_API Renderer
	{
	public:
		static void Init();

		static void Draw(Image& pic, int xCoord, int yCoord);
		static void Draw(Image& pic, int xCoord, int yCoord, Shaders shaders);

	private:
		Renderer();

		std::unique_ptr<RendererImpl> mImplementation;
		inline static std::unique_ptr<Renderer> mInstance;
	};
}
