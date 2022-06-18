#pragma once

class RBot
{
public:
	uint32_t m_Fps;
	fast_vector<FrameAction> m_Actions;
public:
	void Parse(std::ifstream Replay);
};