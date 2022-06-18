#include "pch.h"

int wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	glfwInit();

	GuiLayer Gui;
	Gui.Run();
}