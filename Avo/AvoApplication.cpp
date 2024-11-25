#include "pch.h"

#include "AvoApplication.h"
#include "AvoWindow.h"
#include "Image.h"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "glad/glad.h"

#include "stb_image.h"

namespace Avo
{
	void AvoApplication::Run()
	{
		Avo::AvoWindow::Init();
		Avo::AvoWindow::GetWindow()->CreateWindow(800, 600, "test");

		Initialize();

		//// Shaders /////
		
		const char* vertexShaderSource = R"(
			#version 330 core

			layout (location = 0) in vec2 aPos;
			layout (location = 1) in vec2 aTexCoord;

			out vec2 TexCoord;

			uniform ivec2 ScreenDim;

			void main()
			{
				gl_Position = vec4(2*aPos.x/ScreenDim.x - 1, 2*aPos.y/ScreenDim.y - 1, 0.0, 1.0);
				TexCoord = aTexCoord;
			}
			)";

		unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
		glCompileShader(vertexShader);

		int success;
		char infoLog[512];
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
			AVO_ERROR("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog);
		}

		const char* fragmentShaderSource = R"(
			#version 330 core

			in vec2 TexCoord;
			uniform sample2D ourTexture;

			out vec4 FragColor;

			void main()
			{
				FragColor = texture(ourTexture, TexCoord);
			}
			)";

		unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
		glCompileShader(fragmentShader);

		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
			AVO_ERROR("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog);
		}

		unsigned int shaderProgram = glCreateProgram();
		glAttachShader(shaderProgram, vertexShader);
		glAttachShader(shaderProgram, fragmentShader);
		glLinkProgram(shaderProgram);

		glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
			AVO_ERROR("ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog);
		}
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);

		glUseProgram(shaderProgram);
		int location{ glGetUniformLocation(shaderProgram, "ScreenDim") };
		glUniform2i(location, 800, 600);

		//// Texture /////

		Avo::Image pic{ "../AvoAssets/Images/Packman.png" };

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		while (ShouldContinue)
		{
			Update();

			glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			glUseProgram(shaderProgram);
			glBindVertexArray(VAO);
			pic.Bind();
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
			
			Avo::AvoWindow::GetWindow()->SwapBuffers();
			Avo::AvoWindow::GetWindow()->PollEvents();
		}

		Shutdown();
	}


	void AvoApplication::Initialize()
	{

	}


	void AvoApplication::Update()
	{

	}


	void AvoApplication::Shutdown()
	{
	}

}


/*

Avo::Image pic("Assets/image1.png");
Avo::Renderer::Get()->Draw(pic, 100,200);


*/