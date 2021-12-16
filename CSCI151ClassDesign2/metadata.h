
#pragma once

#include <ostream>
#include <string>
#include <vector>
#include <stdexcept>

bool isLeapYear(int year);

class Metadata
{
public:
	Metadata(
		std::string filename,
		std::string imageType,
		std::vector<int> dateCreated, // year-month-day
		double size,
		std::string authorName,
		std::vector<int> dimensions, // width-height
		int apertureSize,
		int exposureTime,
		int ISO,
		bool flashEnabled
	);

	std::string getFilename() const;
	std::string getImageType() const;
	std::vector<int> getDateCreated() const;
	double getSize() const;
	std::string getAuthorName() const;
	std::vector<int> getDimensions() const;
	int getApertureSize() const;
	int getExposureTime() const;
	int getISO() const;
	bool getFlashEnabled() const;

	void setFilename(std::string filename);
	void setImageType(std::string imageType);
	void setDateCreated(std::vector<int> dateCreated);
	void setSize(double size);
	void setAuthorName(std::string authorName);
	void setDimensions(std::vector<int> dimensions);
	void setApertureSize(int apertureSize);
	void setExposureTime(int exposureTime);
	void setISO(int ISO);
	void setFlashEnabled(bool flashEnabled);

private:
	std::string _filename;
	std::string _imageType;
	std::vector<int> _dateCreated; // year-month-day
	double _size;
	std::string _authorName;
	std::vector<int> _dimensions; // width-height
	int _apertureSize;
	int _exposureTime;
	int _ISO;
	bool _flashEnabled;
};

std::ostream& operator<<(std::ostream& out, const Metadata& md);
