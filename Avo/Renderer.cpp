#include "pch.h"

#include "Renderer.h"

namespace Avo
{
	Renderer::Renderer()
	{

	}

	void Renderer::Init()
	{
		if (mInstance == nullptr)
			mInstance = std::unique_ptr<Renderer>(new Renderer);
	}

	void Renderer::Draw(Image& pic, int xCoord, int yCoord)
	{
		mInstance->mImplementation->Draw(pic, xCoord, yCoord);
	}

	void Renderer::Draw(Image& pic, int xCoord, int yCoord, Shaders shaders)
	{
		mInstance->mImplementation->Draw(pic, xCoord, yCoord);
	}
}