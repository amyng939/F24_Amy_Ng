#pragma once

#include "../ImageImpl.h"

namespace Avo
{
	class OpenGLImage : public ImageImpl
	{
	public:
		OpenGLImage();
		OpenGLImage(const std::string& filePath);
		virtual void LoadImage(const std::string& filePath) override;

		virtual bool HasImage() const override;
		virtual int GetWidth() const override;
		virtual int GetHeight() const override;

		virtual void Bind() override;

	private:
		unsigned mImage{ 0 };
		int mHeight{ 0 };
		int mWidth{ 0 };
	};
}