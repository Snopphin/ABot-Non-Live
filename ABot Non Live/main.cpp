#include "pch.h"

int wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	std::ios_base::sync_with_stdio(false);
	NFD_Init();
	glfwInit();

	GuiLayer Gui;
	Gui.RunLoop();

	NFD_Quit();
}