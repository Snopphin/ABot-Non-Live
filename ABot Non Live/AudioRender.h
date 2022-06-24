#pragma once

class AudioRender
{
public:
	void Process(const fast_vector<FrameAction>& ActionData, float Volume, float Fps, std::string Clickpack);
private:
	void OnAction(FrameAction Action, const std::string& ClickPack, float Volume, float Fps);
private:
	AudioEngine m_Output;
};
