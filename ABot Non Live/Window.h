#pragma once

class Window
{
public:
	operator GLFWwindow*() { return m_Window; }

	void Create(const char* Name, uint32_t Width, uint32_t Height);

	static void NewFrame();
	void Display();
	void Clear();

	bool IsClosed() { return glfwWindowShouldClose(m_Window); }
	GLFWwindow* GetWindow() const { return m_Window; }
private:
	GLFWwindow* m_Window = nullptr;
};