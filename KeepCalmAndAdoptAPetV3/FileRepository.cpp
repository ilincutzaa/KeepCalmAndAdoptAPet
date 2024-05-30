#include "FileRepository.h"

void FileRepository::saveToFile() {
	std::ofstream outfile{ this->filename };
	if (!outfile.is_open())
		return;
	for (Dog d : this->get_all()) {
		outfile << d;
	}

	outfile.close();
}

void FileRepository::loadFromFile() {
	std::ifstream infile{ this->filename };
	if (!infile.is_open())
		return;
	if (infile.peek() == std::ifstream::traits_type::eof()) {
		this->generateDogs();
		return;
	}
	Dog d{ "Breed", "Name", 0, "https://keepcalmandadoptapet.com/photo.jpg" };
	while (infile >> d)
		this->addRepoNoUndo(d);
	infile.close();
}

FileRepository::FileRepository(std::vector<Dog> v, std::string fname) : Repository{ v }, filename(fname) {
	std::ifstream f{ fname };
	if (!f.is_open())
		return;
	if (f.peek() == std::ifstream::traits_type::eof()) {
		this->generateDogs();
		return;
	}
	f.close();
	this->loadFromFile();
}

void FileRepository::addRepo(Dog& d) {
	Repository::addRepo(d);
	this->saveToFile();
}

void FileRepository::delRepo(Dog& d) {
	Repository::delRepo(d);
	this->saveToFile();
}

void FileRepository::updateBreed(Dog& d, std::string new_breed) {
	Repository::updateBreed(d, new_breed);
	this->saveToFile();
}

void FileRepository::updateName(Dog& d, std::string new_name) {
	Repository::updateName(d, new_name);
	this->saveToFile();
}

void FileRepository::updateAge(Dog& d, int new_age) {
	Repository::updateAge(d, new_age);
	this->saveToFile();
}

void FileRepository::updatePhoto(Dog& d, std::string new_photo) {
	Repository::updatePhoto(d, new_photo);
	this->saveToFile();
}
