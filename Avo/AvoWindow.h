#pragma once

#include "pch.h"
#include "WindowImpl.h"
#include "AvoUtilities.h"
#include "AvoEvents.h"

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

		void SetKeyEventHandler(const std::function<void(const KeyEvent&)>& newHandler);
		void SetWindowEventHandler(std::function<void(const WindowEvent&)> newHandler);

		void SwapBuffers();
		void PollEvents();

	private:
		std::unique_ptr<WindowImpl> implementation{nullptr};

		AvoWindow();

		inline static std::unique_ptr<AvoWindow> instance;
	};
}