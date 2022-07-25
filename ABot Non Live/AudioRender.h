#pragma once

class AudioRender
{
public:
	AudioRender(const fast_vector<FrameAction>& Actions, float Fps, std::string Clickpack, bool SoftClick, bool HardClick);
private:
	void OnAction(FrameAction Action, const std::string& ClickPack, float Fps, bool SoftClick, bool HardClick);
private:
	AudioEngine m_Output;
};