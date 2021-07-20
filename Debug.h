#pragma once

class Debug
{
public:
	Debug();
	~Debug();
	int randomNumberInRange(int min, int max);
	void randomConsoleColor();
	void resetConsole();
	void setConsoleColorTo(int x);
	void NormalPrint(const char* fmt, ...);
	void GreenPrintLogOnly(const char* fmt, ...);
	void GreenPrint(const char* fmt, ...);
	void RedPrint(const char* fmt, ...);
	void GreyPrint(const char* fmt, ...);
	void RandomPrint(const char* fmt, ...);
	void RandomPrintNoLog(const char* fmt, ...);
	void BadOutput(const char* fmt, ...);
	void GoodOutput(const char* fmt, ...);
	void PrintAddressNoLog(const char* fmt, ...);
	void printf(const char* fmt, ...);
};
