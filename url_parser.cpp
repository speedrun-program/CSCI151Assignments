
#include <iostream>
#include <string>

int main()
{
	std::cout << "Please enter a URL: ";
	std::string url = "";
	std::cin >> url;

	int authorityStart = url.find("/");
	int pathStart = url.find("/", authorityStart + 2);

	std::string scheme = url.substr(0, authorityStart);
	std::string authority = url.substr(authorityStart, pathStart - authorityStart);
	std::string path = url.substr(pathStart);

	std::cout << "scheme = " << scheme << "\n";
	std::cout << "authority = " << authority << "\n";
	std::cout << "path = " << path << "\n";

	std::cout << "\nType visible character(s) and press Enter to end program.\n";
	std::cin >> url;

	return 0;
}
