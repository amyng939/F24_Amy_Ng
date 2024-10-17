#include "pch.h"

#include "AvoWindow.h"
#include "codeGLFW/WindowGLFW.h"

namespace Avo
{
	AvoWindow::AvoWindow()
	{
		// create an implementation object and point "implementation" pointer to it
#ifdef AVO_GLFW
		implementation = new WindowGLFW;
#else
		#window_implementation_isnt_chosen
#endif
	}

	void AvoWindow::CreateWindow(int width, int height, std::string windowName)
	{
		implementation->Create(width, height, windowName);
	}

	int AvoWindow::GetWidth() const
	{
		return implementation->GetWidth();
	}

	int AvoWindow::GetHeight() const
	{
		return implementation->GetHeight();
	}
}