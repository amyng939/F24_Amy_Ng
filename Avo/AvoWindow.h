#pragma once

#include "pch.h"
#include "WindowImpl.h"
#include "AvoUtilities.h"

namespace Avo
{
	class AVO_API AvoWindow
	{
	public:
		static void Init();
		static std::unique_ptr<AvoWindow>& GetWindow();

		void CreateWindow(int width, int height, std::string windowName);
		int GetWidth() const;
		int GetHeight() const;

	private:
		std::unique_ptr<WindowImpl> implementation{nullptr};

		AvoWindow();

		inline static std::unique_ptr<AvoWindow> instance;
	};
}