#pragma once

#include "AvoUtilities.h"

namespace Avo
{
	class AVO_API KeyEvent
	{
	public:
		enum class KeyAction { Press, Release, Repeat };

		KeyEvent(int keyCode, KeyAction action = KeyAction::Press);

		int GetKeyCode() const;
		KeyAction GetKeyAction() const;

	private:
		int mKeyCode{ -1 };
		KeyAction mAction{ KeyAction::Press };
	};

	class AVO_API WindowEvent
	{
	public:
		enum class WindowAction{Close, Minimize, Maximize, Resize};

		WindowEvent(WindowAction action);

		WindowAction GetWindowAction() const;

	private:
		WindowAction mAction{ WindowAction::Resize };
	};
}