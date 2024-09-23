#pragma once

#include "AvoUtilities.h"

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
		bool ShouldContinue{ true };
	};
}