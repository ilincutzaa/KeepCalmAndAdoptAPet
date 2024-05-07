#pragma once
#include "AdoptionList.h"
#include <fstream>
#include <windows.h>
#include <shellapi.h>

class FileAdoption: public AdoptionList {
protected:
	std::string filename;
	virtual void saveToFile() = 0;
public:
	FileAdoption(Repository& repo, std::string fname) : AdoptionList(repo), filename(fname) {};
	virtual ~FileAdoption() {};
	void addAdoptionList(Dog& d);
};

class CSVFileAdoption : public FileAdoption {
private:
	void saveToFile() override;
public:
	CSVFileAdoption(Repository& repo, std::string fname) : FileAdoption{ repo, fname } {};
	~CSVFileAdoption() {};
	void display() override;
};

class HTMLFileAdoption : public FileAdoption {
private:
	void saveToFile() override;
public:
	HTMLFileAdoption(Repository& repo, std::string fname) : FileAdoption{ repo, fname } {};
	~HTMLFileAdoption() {};
	void display() override;
};
