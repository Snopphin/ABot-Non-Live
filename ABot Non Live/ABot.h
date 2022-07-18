#pragma once

namespace ABot
{
	enum class ClickType
	{
		NormalClick = 0, SoftClick, HardClick
	};

	std::string CreateClickType(FrameAction Action, const std::string& ClickPack, float Fps);
}