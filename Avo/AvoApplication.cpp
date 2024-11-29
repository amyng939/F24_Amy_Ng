#include "pch.h"

#include "AvoApplication.h"
#include "AvoWindow.h"
#include "Image.h"
#include "Shaders.h"

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

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			AVO_ERROR("Failed to initiate GLAD");
		}

		Initialize();

		//// Vertex code /////
		
		float vertices[] = {
			100.0f, 100.0f, 0.0f, 0.0f,
			100.0f, 300.0f, 0.0f, 1.0f,
			300.0f, 300.0f, 1.0f, 1.0f,
			300.0f, 100.0f, 1.0f, 0.0f
		};

		unsigned int indices[] = {
			0, 1, 2, // first triangle
			0, 2, 3  // second triangle
		};

		unsigned int VAO;
		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);

		unsigned int VBO;
		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2*sizeof(float)));
		glEnableVertexAttribArray(1);

		unsigned int EBO;
		glGenBuffers(1, &EBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);


		//// Shaders /////

		Avo::Shaders shaders{
			"../Avo/AvoAssets/Shaders/defaultVertexShader.glsl",
			"../Avo/AvoAssets/Shaders/defaultFragmentShader.glsl" };

		shaders.SetIntUniform("ScreenDim", { 800, 600 });

		//// Texture /////

		Avo::Image pic{ "../Avo/AvoAssets/Images/Slowpoke.png" };

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		while (ShouldContinue)
		{
			Update();

			glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			shaders.Bind();
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