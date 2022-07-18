#include "pch.h"

int wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	std::ios_base::sync_with_stdio(false);
	glfwInit();

	GuiLayer Gui;
	Gui.RunLoop();
}