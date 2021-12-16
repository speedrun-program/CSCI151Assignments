
#include "URL.h"
#include <iostream>

int main()
{
    std::cout << "testing URL class\n\n";
	URL testURL("https://example.com/");
	
	std::cout << testURL;

	std::string exitInput = "";
	std::cout << "\nType visible character(s) and press Enter to end program.\n";
	std::cin >> exitInput;
}
