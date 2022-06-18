#pragma once

class TASBOT
{
public:
	bool m_Is2PMode;
	float m_Fps;
	fast_vector<FrameAction> m_Actions;
public:
	void Parse(std::ifstream Replay);
};