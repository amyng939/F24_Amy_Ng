#pragma once

#include "pch.h"
#include "WindowImpl.h"
#include "AvoUtilities.h"

namespace Avo
{
	class AVO_API AvoWindow
	{
	public:
		AvoWindow();

		void CreateWindow(int width, int height, std::string windowName);
		int GetWidth() const;
		int GetHeight() const;

	private:
		WindowImpl* implementation{nullptr};
	};
}