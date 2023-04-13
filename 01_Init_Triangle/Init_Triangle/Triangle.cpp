#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include"iostream"

int main()
{

	GLFWwindow* window;
	
	//init the GLFW library
	if (!glfwInit())
	{
		std::cout << "GLFW could not Init " << std::endl;
		return -1;
	}

	//creating the window here by defining the heigh and width and name etc.
	window = glfwCreateWindow(600, 480, "OpenGL_Win_Tri", NULL, NULL);
	if (!window)
	{
		std::cout << "Window Could not be Created" << std::endl;
		glfwTerminate();
		return -1;
	}

	//making the window's context current
	glfwMakeContextCurrent(window);
	

	//init GLEW library
	if (glewInit() != GLEW_OK)
	{
		std::cout << "GLEW could not Init" << std::endl;
	}
	//displaying the current OpenGL version
	std::cout << glGetString(GL_VERSION) << std::endl;


	//loop until the window is closed or Main Game Loop
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		//using lagacy OpenGL to draw the triangle 
		glBegin(GL_TRIANGLES);
		glVertex2f(  0.0f,  0.5f);
		glVertex2f(  0.5f, -0.5f);
		glVertex2f( -0.5f, -0.5f);
		glEnd();

		//swap front and back buffers
		glfwSwapBuffers(window);

		// Poll for and process events 
		glfwPollEvents();

	}
	glfwTerminate();
	return 0;
}