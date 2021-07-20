#include <windows.h>
#include <stdio.h>
#include <random>
#include <string>

#include "Debug.h"

typedef enum TerminalColor { DarkBlue = 1, DarkGreen, DarkLightBlue, DarkRed, DarkPurple, DarkYellow, DarkWhite, Grey, Blue, Green, LightBlue, Red, Purple, Yellow, White } TerminalColor;
int counter = 0;
int lowerLimit = Blue;
int upperLimit = Yellow;

using namespace std;

/// <summary>
/// Returns a random integer in the specified range, inclusive.
/// </summary>
/// <param name="min">Minimum random number</param>
/// <param name="max">Maximum random number</param>
/// <returns></returns>
int Debug::randomNumberInRange(int min, int max) {
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist6(min, max); // distribution in range [x, y]
	return dist6(rng);
}

/// <summary>
/// Sets the console to a random color
/// </summary>
void Debug::randomConsoleColor() {
	HANDLE  hConsole;
	int randomColor;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	randomColor = randomNumberInRange(lowerLimit, upperLimit);
	SetConsoleTextAttribute(hConsole, randomColor);
}

/// <summary>
/// Resets the console to print in white
/// </summary>
void Debug::resetConsole() {
	HANDLE  hConsole;
	int k = White; //https://stackoverflow.com/questions/4053837/colorizing-text-in-the-console-with-c
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, k);
}

/// <summary>
/// Set console to a specified color
/// </summary>
/// <param name="color">An int that represents the color. The color enum can be used.</param>
void Debug::setConsoleColorTo(int color) {
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

/// <summary>
/// Print a white statement with the counter prefix and neutral prefix
/// </summary>
/// <param name="fmt">Inputted string</param>
/// <param name="">Variadic argument</param>
void Debug::NormalPrint(const char* fmt, ...)
{
	counter++;
	va_list arg;
	va_start(arg, fmt);

	auto my_cstr = fmt;
	std::string s(my_cstr);
	std::string prefix = "[" + std::to_string(counter) + "] [=] ";
	s.insert(0, prefix);
	auto back_to_cstr = s.c_str();

	vprintf(back_to_cstr, arg);

	va_end(arg);
}

/// <summary>
/// Print a white statement with no prefixes
/// </summary>
/// <param name="fmt">Inputted string</param>
/// <param name="">Variadic argument</param>
void Debug::printf(const char* fmt, ...)
{
	va_list arg;
	va_start(arg, fmt);

	auto format = fmt;
	auto my_cstr = "";
	std::string s(my_cstr);
	auto back_to_cstr = s.c_str();

	vprintf(back_to_cstr, arg);
	vprintf(fmt, arg);

	va_end(arg);
}

/// <summary>
/// Print a green, positive prefix then a white input
/// </summary>
/// <param name="fmt">Inputted string</param>
/// <param name="">Variadic argument</param>
void Debug::GreenPrint(const char* fmt, ...)
{
	counter++;
	va_list arg;
	va_start(arg, fmt);

	auto format = fmt;
	auto my_cstr = "[" + std::to_string(counter) + "] [+] ";
	std::string s(my_cstr);
	auto back_to_cstr = s.c_str();

	setConsoleColorTo(Green);
	vprintf(back_to_cstr, arg);
	resetConsole();
	vprintf(fmt, arg);

	va_end(arg);
}

/// <summary>
/// Print a red, negative prefix then a white input
/// </summary>
/// <param name="fmt">Inputted string</param>
/// <param name="">Variadic argument</param>
void Debug::RedPrint(const char* fmt, ...)
{
	counter++;
	va_list arg;
	va_start(arg, fmt);

	auto format = fmt;
	auto my_cstr = "[" + std::to_string(counter) + "] [-] ";
	std::string s(my_cstr);
	auto back_to_cstr = s.c_str();

	setConsoleColorTo(Red);
	vprintf(back_to_cstr, arg);
	resetConsole();
	vprintf(fmt, arg);

	va_end(arg);
}

/// <summary>
/// Print a fully green statement with all prefixes included. Prints a positive prefix.
/// </summary>
/// <param name="fmt">Inputted string</param>
/// <param name="">Variadic argument</param>
void Debug::GoodOutput(const char* fmt, ...)
{
	counter++;
	va_list arg;
	va_start(arg, fmt);

	auto format = fmt;
	auto my_cstr = "[" + std::to_string(counter) + "] [+] ";
	std::string s(my_cstr);
	auto back_to_cstr = s.c_str();

	setConsoleColorTo(Green);
	vprintf(back_to_cstr, arg);
	vprintf(fmt, arg);
	resetConsole();

	va_end(arg);
}

/// <summary>
/// Print a fully red statement with all prefixes included. Prints a negative prefix.
/// </summary>
/// <param name="fmt">Inputted string</param>
/// <param name="">Variadic argument</param>
void Debug::BadOutput(const char* fmt, ...)
{
	counter++;
	va_list arg;
	va_start(arg, fmt);

	setConsoleColorTo(Red);
	auto format = fmt;
	auto my_cstr = "[" + std::to_string(counter) + "] [-] ";
	std::string s(my_cstr);
	auto back_to_cstr = s.c_str();

	vprintf(back_to_cstr, arg);
	vprintf(fmt, arg);
	resetConsole();

	va_end(arg);
}

/// <summary>
/// Print a grey, neutral prefix then a white input
/// </summary>
/// <param name="fmt">Inputted string</param>
/// <param name="">Variadic argument</param>
void Debug::GreyPrint(const char* fmt, ...)
{
	counter++;
	va_list arg;
	va_start(arg, fmt);

	auto format = fmt;
	auto my_cstr = "[" + std::to_string(counter) + "] [=] ";
	std::string s(my_cstr);
	auto back_to_cstr = s.c_str();

	setConsoleColorTo(Grey);
	vprintf(back_to_cstr, arg);
	resetConsole();
	vprintf(fmt, arg);

	va_end(arg);
}

/// <summary>
/// Prints a random prefix then a white input
/// </summary>
/// <param name="fmt">Inputted string</param>
/// <param name="">Variadic argument</param>
void Debug::RandomPrint(const char* fmt, ...)
{
	counter++;
	va_list arg;
	va_start(arg, fmt);

	auto format = fmt;
	auto my_cstr = "[" + std::to_string(counter) + "] [=] ";
	std::string s(my_cstr);
	auto back_to_cstr = s.c_str();

	randomConsoleColor();
	vprintf(back_to_cstr, arg);
	resetConsole();
	vprintf(fmt, arg);

	va_end(arg);
}

/// <summary>
/// Prints a randomly colored string with no prefixes
/// </summary>
/// <param name="fmt">Inputted string</param>
/// <param name="">Variadic argument</param>
void Debug::RandomPrintNoLog(const char* fmt, ...)
{
	va_list arg;
	va_start(arg, fmt);

	auto format = fmt;
	auto my_cstr = "";
	std::string s(my_cstr);
	auto back_to_cstr = s.c_str();

	randomConsoleColor();
	vprintf(fmt, arg);
	resetConsole();

	va_end(arg);
}

/// <summary>
/// Print a randomly colored address with no prefixes
/// </summary>
/// <param name="fmt">Inputted string</param>
/// <param name="">Variadic argument</param>
void Debug::PrintAddressNoLog(const char* fmt, ...)
{
	va_list arg;
	va_start(arg, fmt);

	auto format = fmt;
	auto my_cstr = "0x";
	std::string s(my_cstr);
	auto back_to_cstr = s.c_str();

	randomConsoleColor();
	vprintf(back_to_cstr, arg);
	vprintf(fmt, arg);
	resetConsole();

	va_end(arg);
}

Debug::Debug()
{




}

Debug::~Debug()
{
	/*if (DriverHandle != INVALID_HANDLE_VALUE)
		CloseHandle(DriverHandle);*/
}
