#include "Renderer.h"

namespace CCraft
{

	Renderer::Renderer()
		: logger("RENDERER", Logger::INFO), window(initializer.window), gameState(GameState::MENU), input(window)
	{

	}


	void Renderer::shutDown()
	{
		glfwTerminate();
		logger.log("Successfully terminated.", Logger::INFO);
		logger.log("Press enter to continue...", Logger::INFO);
		running = false;
		std::cin.get();
	}

	void Renderer::render()
	{
		if (glfwWindowShouldClose(window))
			shutDown();

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		if (gameState == GameState::MENU)
		{
			input.proccess();

			if (input.button1Pressed)
				menu.but1.pressed = true;
			else
				menu.but1.pressed = false;

			menu.draw();
		}
			

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	GLFWwindow* Renderer::getWindowID()
	{
		return window;
	}
}