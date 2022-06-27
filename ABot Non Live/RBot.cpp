#include "pch.h"
#define TotalActionsInBytes 6

RBot::RBot(std::ifstream& Macro)
{
	this->Parse(Macro);
}

void RBot::Parse(std::ifstream& Macro)
{
	Actions.allocate(GetTotalBytes(Macro) / TotalActionsInBytes);

	Fps = ReadBinary<int>(Macro);
	Macro.ignore(sizeof(int));

	while (!Macro.fail())
	{
		uint32_t Frame = ReadBinary<uint32_t>(Macro);
		bool IsHolding = ReadBinary<bool>(Macro);
		Macro.ignore(sizeof(bool));

		Actions.push_back(FrameAction(Frame, IsHolding));
	}
	
	Actions.pop_back();
}