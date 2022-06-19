#pragma once

class RBot
{
public:
	RBot(std::ifstream& Macro);
private:
	void Parse(std::ifstream& Macro);
public:
	float Fps;
	fast_vector<FrameAction> Actions;
};