#pragma once

class TASBOT
{
public:
	TASBOT(std::ifstream& Macro);
private:
	void Parse(std::ifstream& Macro);
public:
	float Fps;
	fast_vector<FrameAction> Actions;
};