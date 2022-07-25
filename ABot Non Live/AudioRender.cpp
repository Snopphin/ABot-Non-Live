#include "pch.h"

AudioRender::AudioRender(const fast_vector<FrameAction>& Actions, float Fps, std::string ClickPack, bool SoftClick, bool HardClick)
{
	for (const auto& Action : Actions)
	{
		OnAction(Action, ClickPack, Fps, SoftClick, HardClick);
	}

	m_Output.Export("Output.wav");
}

void AudioRender::OnAction(FrameAction Action, const std::string& ClickPack, float Fps, bool SoftClick, bool HardClick)
{
	float Time = Action.Frame / Fps;

	std::string ClickPath = ABot::CreateClickType(Action, ClickPack, Fps, SoftClick, HardClick);
	int8_t RandomClick = Random::IntRandom(1, FileSystem::CountFiles(ClickPath));

	m_Output.Overlay(ClickPath + std::to_string(RandomClick) + ".wav", Time);
}