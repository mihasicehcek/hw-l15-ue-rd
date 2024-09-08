#ifdef _WIN32
#include <windows.h>
#endif
#include <string>

void setConsoleTextColor(const std::string& colorCode) {
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int color;

    if (colorCode == "black") color = 0;
    else if (colorCode == "red") color = 4;
    else if (colorCode == "green") color = 2;
    else if (colorCode == "yellow") color = 6;
    else if (colorCode == "blue") color = 1;
    else if (colorCode == "magenta") color = 5;
    else if (colorCode == "cyan") color = 3;
    else if (colorCode == "white") color = 7;
    else color = 7;

    SetConsoleTextAttribute(hConsole, color);
#else
    std::string ansiCode;

    if (colorCode == "black") ansiCode = "30";
    else if (colorCode == "red") ansiCode = "31";
    else if (colorCode == "green") ansiCode = "32";
    else if (colorCode == "yellow") ansiCode = "33";
    else if (colorCode == "blue") ansiCode = "34";
    else if (colorCode == "magenta") ansiCode = "35";
    else if (colorCode == "cyan") ansiCode = "36";
    else if (colorCode == "white") ansiCode = "37";
    else ansiCode = "0";

    std::cout << "\033[" << ansiCode << "m";
#endif
}
