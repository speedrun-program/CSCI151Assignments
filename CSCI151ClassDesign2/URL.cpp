
#include "URL.h"

URL::URL(std::string myURL) : _myURL{ myURL }
{
	int authorityStart = myURL.find("/");
	int pathStart = myURL.find("/", authorityStart + 2);

	_scheme = myURL.substr(0, authorityStart);
	_authority = myURL.substr(authorityStart, pathStart - authorityStart);
	_path = myURL.substr(pathStart);
}

std::string URL::getURL() const { return _myURL; }

std::string URL::getScheme() const { return _scheme; }

std::string URL::getAuthority() const { return _authority; }

std::string URL::getPath() const { return _path; }

std::ostream& operator<<(std::ostream& out, const URL& url)
{
	out << "URL: " << url.getURL() << "\n";
	out << "    SCHEME: " << url.getScheme() << "\n";
	out << "    AUTHORITY: " << url.getAuthority() << "\n";
	out << "    PATH: " << url.getPath() << "\n";
	return out;
}
