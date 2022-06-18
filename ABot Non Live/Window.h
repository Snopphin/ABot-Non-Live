#pragma once

class Window
{
public:
	~Window();

	operator GLFWwindow*() { return m_Window; }

	void Create(const char* Name, uint32_t Width, uint32_t Height);

	static void NewFrame();
	void Render();
	static void ResetPreviousRender();

	bool IsClosed() { return glfwWindowShouldClose(m_Window); }
	GLFWwindow* GetWindow() const { return m_Window; }
private:
	GLFWwindow* m_Window = nullptr;
};