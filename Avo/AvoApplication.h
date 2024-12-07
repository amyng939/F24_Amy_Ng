#pragma once

#include "pch.h"
#include "AvoUtilities.h"

constexpr int FPS_RATE{ 60 };

namespace Avo
{
	class AVO_API AvoApplication
	{
	public:
		void Run();
		virtual void Initialize();
		virtual void Update();
		virtual void Shutdown();

	private:
		bool mShouldContinue{ true };

		std::chrono::steady_clock::time_point mNextFrameTime;
		std::chrono::milliseconds mFrameDuration{ std::chrono::milliseconds{1000} / FPS_RATE };
	};
}