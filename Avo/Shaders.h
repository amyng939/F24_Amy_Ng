#pragma once

#include "pch.h"
#include "AvoUtilities.h"
#include "ShadersImpl.h"

namespace Avo
{
	class AVO_API Shaders
	{
	public:
		Shaders();
		Shaders(const std::string& vertexSFile, const std::string& fragmentSFile);
		void LoadShaders(const std::string& vertexSFile, const std::string& fragmentSFile);
	
		void Bind();
		void SetIntUniform(const std::string& uniformName, const std::vector<int>& values);
		void SetIntUniform(const std::string& uniformName, int value);

	private:
		std::unique_ptr<ShadersImpl> implementation;
	};
}