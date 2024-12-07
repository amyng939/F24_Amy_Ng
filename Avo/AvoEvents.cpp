#include "pch.h"
#include "AvoEvents.h"

namespace Avo
{
	KeyEvent::KeyEvent(int keyCode, KeyAction action) : mKeyCode(keyCode), mAction(action)
	{
	}

	int KeyEvent::GetKeyCode() const
	{
		return mKeyCode;
	}

	KeyEvent::KeyAction KeyEvent::GetKeyAction() const
	{
		return mAction;
	}



	WindowEvent::WindowEvent(WindowAction action) : mAction(action)
	{
	}

	WindowEvent::WindowAction WindowEvent::GetWindowAction() const
	{
		return mAction;
	}
}