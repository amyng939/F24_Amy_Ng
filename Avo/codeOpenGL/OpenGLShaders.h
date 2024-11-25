#pragma once

#include "../ShadersImpl.h"

namespace Avo
{
	class OpenGLShaders : public ShadersImpl
	{
	public:
		virtual void LoadShaders(const std::string& vertexSFile, const std::string& fragmentSFile) override;
		virtual void Bind() override;
		virtual void SetIntUniform(const std::string& uniformName, const std::vector<int>& values) override;
	
		~OpenGLShaders() {};
	};
}