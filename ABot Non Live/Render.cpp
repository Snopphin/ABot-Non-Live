#include "pch.h"

Render::Render(fast_vector<FrameAction>& Actions, float Fps, std::string ClickPack, float Volume)
{
	m_Output.CreateSilence(Actions.back().Frame / Fps + 5);

	for (auto& Action : Actions)
	{
		OnAction(Action, Fps, ClickPack, Volume);
	}

	m_Output.Export("Output.wav");
}

void Render::OnAction(FrameAction Action, float Fps, const std::string& ClickPack, float Volume)
{
	const float Time = Action.Frame / Fps;

	std::string ClickPath = ABot::CreateClickType(ClickPack, Action, Fps);
	int8_t RandomClick = Random::IntRandom(1, FileSystem::CountFiles(ClickPath));

	m_Output.Overlay(ClickPath + std::to_string(RandomClick) + ".wav", Time, Volume);
}
