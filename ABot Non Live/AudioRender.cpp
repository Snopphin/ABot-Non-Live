#include "pch.h"

void AudioRender::Process(const fast_vector<FrameAction>& Actions, float Fps, float Volume, std::string ClickPack)
{
	m_Output.CreateSilence(Actions.back().Frame / Fps + 5);
		
	for (const auto& Action : Actions)
	{
		OnAction(Action, ClickPack, Volume, Fps);
	}

	m_Output.Export("Output.wav");
}

void AudioRender::OnAction(FrameAction Action, const std::string& ClickPack, float Volume, float Fps)
{
	float Time = Action.Frame / Fps;
	
	std::string ClickPath = ABot::CreateClickType(ClickPack, Action, Fps);
	int8_t RandomClick = Random::IntRandom(1, FileSystem::CountFiles(ClickPath));

	m_Output.Overlay(ClickPath + std::to_string(RandomClick) + ".wav", Time, Volume);
}