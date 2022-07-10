#pragma once

class AudioRender
{
public:
	void Process(const fast_vector<FrameAction>& Actions, float Fps, float Volume, std::string Clickpack);
private:
	void OnAction(FrameAction Action, const std::string& ClickPack, float Fps);
private:
	AudioEngine m_Output;
};