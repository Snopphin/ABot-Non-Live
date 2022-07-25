#include "pch.h"

namespace ABot
{
	ClickType CheckClickType(FrameAction Action, uint32_t PreviousFrame, const std::string& ClickPack, float Fps, bool SoftClick, bool HardClick)
	{
		float CurrentTime = (Action.Frame - PreviousFrame) / Fps;

		if (CurrentTime < 0.1f && SoftClick)
		{
			return ClickType::SoftClick;
		}

		if (CurrentTime < 2.0f && HardClick)
		{
			return ClickType::HardClick;
		}

		return ClickType::NormalClick;
	}

	std::string CreateClickType(FrameAction Action, const std::string& ClickPack, float Fps, bool SoftClick, bool HardClick)
	{
		static uint32_t PreviousFrame = 0;
		ClickType CurrentClickType = CheckClickType(Action, PreviousFrame, ClickPack, Fps, SoftClick, HardClick);
		
		if (!Action.IsHolding)
			PreviousFrame = Action.Frame;

		switch (CurrentClickType) 
		{
		case ClickType::HardClick:
			if (Action.IsHolding)
				return ClickPack + "/HardClicks/";
			else
				return ClickPack + "/HardReleases/";
			break;

		case ClickType::SoftClick:
			if (Action.IsHolding)
				return ClickPack + "/SoftClicks/";
			else
				return ClickPack + "/SoftReleases/";
			break;

		default:
			if (Action.IsHolding)
				return ClickPack + "/Clicks/";
			else
				return ClickPack + "/Releases/";
			break;
		}

	}
}