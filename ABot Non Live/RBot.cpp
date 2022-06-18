#include "pch.h"
#define TotalActionsInBytes 6

void RBot::Parse(std::ifstream Replay)
{
	Replay.seekg(0, std::ios::end);
	m_Actions.reserve(Replay.tellg() / TotalActionsInBytes);
	Replay.seekg(0, std::ios::beg);

	m_Fps = ReadBinary<uint32_t>(Replay);
	Replay.ignore(sizeof(int));

	while (!Replay.fail())
	{
		uint32_t Frame = ReadBinary<uint32_t>(Replay);
		bool IsHolding = ReadBinary<bool>(Replay);
		Replay.ignore(sizeof(bool));

		m_Actions.push_back(FrameAction(Frame, IsHolding));
	}

	m_Actions.pop_back();
}