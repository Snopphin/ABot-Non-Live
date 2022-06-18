#pragma once

class Render
{
public:
	explicit Render(fast_vector<FrameAction>& Actions, float Fps, std::string ClickPack, float Volume);
private:
	void OnAction(FrameAction& Action, float Fps, const std::string& ClickPack, float Volume);
private:
	AudioEngine m_Output;
};