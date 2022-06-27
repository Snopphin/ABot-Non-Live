#include "pch.h"

namespace ABot
{
	constexpr ClickType CheckClickType(const std::string& ClickPack, FrameAction Action, uint32_t PreviousFrame, float Fps)
	{
		float CurrentTime = (Action.Frame - PreviousFrame) / Fps;

		if (CurrentTime < 0.13f && std::filesystem::exists(ClickPack + "/SoftClicks/"))
		{
			return ClickType::SoftClick;
		}

		if (CurrentTime < 0.24f && std::filesystem::exists(ClickPack + "/HardClicks/"))
		{
			return ClickType::HardClick;
		}

		return ClickType::NormalClick;
	}

	std::string CreateClickType(const std::string& ClickPack, FrameAction Action, float Fps)
	{
		static uint32_t PreviousFrame = 0;
		const ClickType CurrentClickType = CheckClickType(ClickPack, Action, PreviousFrame, Fps);
		
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