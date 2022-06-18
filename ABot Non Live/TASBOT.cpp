#include "pch.h"

void TASBOT::Parse(std::ifstream Replay)
{
	rapidjson::IStreamWrapper ReplayData(Replay);
	rapidjson::Document Macro;
	Macro.ParseStream(ReplayData);

	m_Fps = Macro["fps"].GetFloat();
	
	size_t TotalActions = Macro["macro"].Size();
	m_Actions.reserve(m_Is2PMode == true ? TotalActions * 2 : TotalActions);

	for (auto& Action : Macro["macro"].GetArray())
	{
		uint32_t Frame = Action["frame"].GetUint();

		bool IsHolding = Action["player_1"]["click"] == 1;
		bool IsPlayer2Holding = Action["player_2"]["click"] == 1;

		if (bool IsPlayer = Action["player_1"]["click"] != 0)
			m_Actions.push_back(FrameAction(Frame, IsHolding));
		if (bool IsPlayer2 = Action["player_2"]["click"] != 0 && m_Is2PMode)
			m_Actions.push_back(FrameAction(Frame, IsPlayer2Holding));
	}
}