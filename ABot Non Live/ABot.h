#pragma once

namespace ABot
{
	enum class ClickType
	{
		NormalClick = 0, SoftClick, HardClick
	};

	std::string CreateClickType(const std::string& ClickPack, FrameAction Action, float Fps);
}