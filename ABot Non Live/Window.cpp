#include "pch.h"

void Window::Create(const char* Name, uint32_t Width, uint32_t Height)
{
	m_Window = glfwCreateWindow(Width, Height, Name, NULL, NULL);
	glfwMakeContextCurrent(m_Window);
}

void Window::NewFrame()
{
	glfwPollEvents();
}

void Window::Display()
{
	glfwSwapBuffers(m_Window);
}

void Window::Clear()
{
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
}
