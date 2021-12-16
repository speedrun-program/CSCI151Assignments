
#include "URL.h"
#include <iostream>

int main()
{
    std::cout << "testing URL class\n\n";
	URL testURL("https://example.com/some/path/to/file.txt");
	
	std::cout << "URL: " << testURL.getURL() << "\n";
	std::cout << "    SCHEME: " << testURL.getScheme() << "\n";
	std::cout << "    AUTHORITY: " << testURL.getAuthority() << "\n";
	std::cout << "    PATH: " << testURL.getPath() << "\n";

	std::string exitInput = "";
	std::cout << "\nType visible character(s) and press Enter to end program.\n";
	std::cin >> exitInput;
}
