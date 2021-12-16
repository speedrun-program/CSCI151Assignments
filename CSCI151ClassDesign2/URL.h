
#pragma once

#include <string>
#include <ostream>

class URL
{
public:
	URL(std::string myURL);

	std::string getURL() const;
	std::string getScheme() const;
	std::string getAuthority() const;
	std::string getPath() const;

private:
	std::string _myURL;
	std::string _scheme;
	std::string _authority;
	std::string _path;
};

std::ostream& operator<<(std::ostream& out, const URL& url);
