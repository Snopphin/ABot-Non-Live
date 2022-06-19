#pragma once

class GuiLayer
{
public:
	GuiLayer();

	void RunLoop();
private:
	void NewFrame();
	void RenderFrame();

	void RenderGui();
	void SetupTheme();
private:
	Window m_Window;
	ImFont* m_ImGuiFont = nullptr;
};