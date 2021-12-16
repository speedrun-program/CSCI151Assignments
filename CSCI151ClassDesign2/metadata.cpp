
#include "metadata.h"

bool isLeapYear(int year)
{
	if (year % 4)
	{
		return false;
	}
	if ((year % 100) && !(year % 400))
	{
		return false;
	}
	return true;
}

Metadata::Metadata(
	std::string filename,
	std::string imageType,
	std::vector<int> dateCreated, // year-month-day
	double size,
	std::string authorName,
	std::vector<int> dimensions, // width-height
	int apertureSize,
	int exposureTime,
	int ISO,
	bool flashEnabled)
{
	setFilename(filename);
	setImageType(imageType);
	setDateCreated(dateCreated);
	setSize(size);
	setAuthorName(authorName);
	setDimensions(dimensions);
	setApertureSize(apertureSize);
	setExposureTime(exposureTime);
	setISO(ISO);
	setFlashEnabled(flashEnabled);
}

std::string Metadata::getFilename() const { return _filename; }
std::string Metadata::getImageType() const { return _imageType; }
std::vector<int> Metadata::getDateCreated() const { return _dateCreated; }
double Metadata::getSize() const { return _size; }
std::string Metadata::getAuthorName() const { return _authorName; }
std::vector<int> Metadata::getDimensions() const { return _dimensions; }
int Metadata::getApertureSize() const { return _apertureSize; }
int Metadata::getExposureTime() const { return _exposureTime; }
int Metadata::getISO() const { return _ISO; }
bool Metadata::getFlashEnabled() const { return _flashEnabled; }

void Metadata::setFilename(std::string filename) { _filename = filename; }

void Metadata::setImageType(std::string imageType)
{
	std::string validTypes[] = { "PNG", "GIF", "JPEG" };

	for (char& ch : imageType) // changing to uppercase
	{
		ch -= 32 * (ch >= 'a' && ch <= 'z');
	}

	int i = 0;
	for (; i < 3 && validTypes[i] != imageType; i++) {}

	if (i == 3)
	{
		throw std::invalid_argument("invalid image type\n");
	}

	_imageType = imageType;
}

void Metadata::setDateCreated(std::vector<int> dateCreated)
{
	if (dateCreated.size() < 3)
	{
		throw std::invalid_argument("invalid date vector size\n");
	}

	int year = dateCreated[0];
	int month = dateCreated[1];
	int day = dateCreated[2];

	int daysByMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	bool extraDay = month == 2 && isLeapYear(year);

	if (year < 0 || month < 1 || month > 12 || day < 1 || day > (daysByMonth[month] + extraDay))
	{
		throw std::invalid_argument("invalid date\n");
	}
	_dateCreated = dateCreated;
}

void Metadata::setSize(double size)
{
	if (size < 0)
	{
		throw std::invalid_argument("invalid size\n");
	}
	_size = size;
}

void Metadata::setAuthorName(std::string authorName) { _authorName = authorName; }

void Metadata::setDimensions(std::vector<int> dimensions)
{
	if (dimensions.size() < 2)
	{
		throw std::invalid_argument("invalid number of dimensions\n");
	}
	if (dimensions[0] < 0 || dimensions[1] < 0)
	{
		throw std::invalid_argument("invalid dimensions\n");
	}
	_dimensions = dimensions;
}

void Metadata::setApertureSize(int apertureSize)
{
	if (apertureSize < 0)
	{
		throw std::invalid_argument("invalid aperture size\n");
	}
	_apertureSize = apertureSize;
}

void Metadata::setExposureTime(int exposureTime)
{
	if (exposureTime < 0)
	{
		throw std::invalid_argument("invalid exposure time\n");
	}
	_exposureTime = exposureTime;
}

void Metadata::setISO(int ISO)
{
	if (ISO < 0)
	{
		throw std::invalid_argument("invalid ISO\n");
	}
	_ISO = ISO;
}

void Metadata::setFlashEnabled(bool flashEnabled) { _flashEnabled = flashEnabled; }

std::ostream& operator<<(std::ostream& out, const Metadata& md)
{
	std::vector<int> date = md.getDateCreated();
	std::vector<int> dimensions = md.getDimensions();

	out << "filename: " << md.getFilename() << "\n";
	out << "image type: " << md.getImageType() << "\n";
	out << "date created: " << date[0] << "-" << date[1] << "-" << date[2] << "\n";
	out << "size: " << md.getSize() << "\n";
	out << "author name: " << md.getAuthorName() << "\n";
	out << "dimensions: " << dimensions[0] << "x" << dimensions[1] << "\n";
	out << "aperture size: " << md.getApertureSize() << "\n";
	out << "exposure time: " << md.getExposureTime() << "\n";
	out << "ISO: " << md.getISO() << "\n";
	out << "flash enabled: " << (md.getFlashEnabled() ? "yes\n" : "no\n");
	return out;
}
