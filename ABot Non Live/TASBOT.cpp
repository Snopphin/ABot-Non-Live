#include "pch.h"

TASBOT::TASBOT(std::ifstream& Macro)
{
	this->Parse(Macro);
}

void TASBOT::Parse(std::ifstream& Macro)
{
	rapidjson::Document MacroFile;
	rapidjson::IStreamWrapper ReplayStream(Macro);
	MacroFile.ParseStream(ReplayStream);

	Fps = MacroFile["fps"].GetFloat();

	size_t TotalActions = MacroFile["macro"].Size();
	Actions.reserve(TotalActions * 2);

	for (const auto& Action : MacroFile["macro"].GetArray())
	{
		uint32_t Frame = Action["frame"].GetUint();

		bool IsHolding = Action["player_1"]["click"] == 1;
		bool IsPlayer2Holding = Action["player_2"]["click"] == 1;

		if (bool IsPlayer = Action["player_1"]["click"] != 0)
			Actions.push_back(FrameAction(Frame, IsHolding));

		if (bool IsPlayer2 = Action["player_2"]["click"] != 0)
			Actions.push_back(FrameAction(Frame, IsPlayer2Holding));
	}
}