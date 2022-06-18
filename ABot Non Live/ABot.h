#pragma once

namespace ABot
{
	enum class ClickType
	{
		NormalClick = 0, SoftClick = 1, HardClick = 2
	};

	std::string CreateClickType(const std::string& ClickPack, FrameAction Action, float Fps);
}