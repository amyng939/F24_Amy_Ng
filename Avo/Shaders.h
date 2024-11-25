#pragma once

#include "pch.h"
#include "AvoUtilities.h"

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

	private:
		std::unique_ptr<ShadersImpl> implementation;

		std::string ReadFile(const std::string fileName) const;
	};
}