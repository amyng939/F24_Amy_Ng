#include "pch.h"

#include "WindowGLFW.h"
#include "AvoUtilities.h"

namespace Avo
{
	WindowGLFW::WindowGLFW()
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	}

	void WindowGLFW::Create(int width, int height, std::string windowName)
	{
		mWindowPtr = glfwCreateWindow(width, height, windowName.c_str(), NULL, NULL);
	
		if (!mWindowPtr)
			AVO_ERROR("GLFW failed to create a window!!!");

		glfwMakeContextCurrent(mWindowPtr);
	}

	int WindowGLFW::GetWidth() const
	{
		int width{ 0 };
		int height{ 0 };

		glfwGetWindowSize(mWindowPtr, &width, &height);

		return width;
	}

	int WindowGLFW::GetHeight() const
	{
		int width{ 0 };
		int height{ 0 };

		glfwGetWindowSize(mWindowPtr, &width, &height);

		return height;
	}

	void WindowGLFW::SwapBuffers()
	{
		glfwSwapBuffers(mWindowPtr);
	}

	void WindowGLFW::PollEvents()
	{
		glfwPollEvents();
	}

}