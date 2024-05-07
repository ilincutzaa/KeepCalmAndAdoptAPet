#pragma once
#include "Repository.h"
#include <fstream>

class FileRepository : public Repository {
private:
	std::string filename;
	void saveToFile();
	void loadFromFile();
public:
	FileRepository(std::vector<Dog> v, std::string fname);
	~FileRepository() {};
	void addRepo(Dog& d) override;
	void delRepo(Dog& d) override;
	void updateBreed(Dog& d, std::string new_breed) override;
	void updateName(Dog& d, std::string new_name) override;
	void updateAge(Dog& d, int new_age) override;
	void updatePhoto(Dog& d, std::string new_photo) override;
};
