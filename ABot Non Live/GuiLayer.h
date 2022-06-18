#pragma once

class GuiLayer
{
public:
	GuiLayer();
	~GuiLayer();

	void Run();
private:
	void NewFrame();
	void RenderFrame();

	void RenderGui();
	void SetupTheme();
private:
	Window m_Window;
	ImFont* m_ImGuiFont = nullptr;
};