#include "Repository.h"

Repository::Repository(std::vector<Dog>& v) : dogs(v) {
}

Repository::~Repository() {
}

void Repository::addRepo(Dog& d) {
	if (isDogInList(d))
		throw RepoException("Dog already in list!\n");
	this->dogs.push_back(d);
}

std::vector<Dog> Repository::get_all() const {
	std::vector<Dog> nv = this->dogs;
	return nv;
}

int Repository::getSizeRepo() {
	return this->dogs.size();
}

void Repository::generateDogs() {
	Dog dog1("Golden Retriever", "Buddy", 3, "https://keepcalmandadoptapet.com/buddy1.jpg");
	Dog dog2("Labrador", "Max", 5, "https://keepcalmandadoptapet.com/max2.jpg");
	Dog dog3("Poodle", "Bailey", 2, "https://keepcalmandadoptapet.com/bailey3.jpg");
	Dog dog4("German Shepherd", "Rocky", 4, "https://keepcalmandadoptapet.com/rocky4.jpg");
	Dog dog5("Beagle", "Charlie", 6, "https://keepcalmandadoptapet.com/charlie5.jpg");
	Dog dog6("Siberian Husky", "Luna", 1, "https://keepcalmandadoptapet.com/luna6.jpg");
	Dog dog7("Boxer", "Duke", 7, "https://keepcalmandadoptapet.com/duke7.jpg");
	Dog dog8("Dachshund", "Milo", 4, "https://keepcalmandadoptapet.com/milo8.jpg");
	Dog dog9("Border Collie", "Bella", 8, "https://keepcalmandadoptapet.com/bella9.jpg");
	Dog dog10("Rottweiler", "Roxy", 2, "https://keepcalmandadoptapet.com/roxy10.jpg");
	addRepo(dog1);
	addRepo(dog2);
	addRepo(dog3);
	addRepo(dog4);
	addRepo(dog5);
	addRepo(dog6);
	addRepo(dog7);
	addRepo(dog8);
	addRepo(dog9);
	addRepo(dog10);
}

bool Repository::isDogInList(Dog& d) {
	std::vector<Dog>::iterator it = find(dogs.begin(), dogs.end(), d);
	return (it != dogs.end());
}

void Repository::updateBreed(Dog& d, std::string new_breed) {
	if (!DogValidator::validateBreed(new_breed)) {
		throw DogException("Invalid breed");
	}
	std::vector<Dog>::iterator it = find(dogs.begin(), dogs.end(), d);
	if (it != dogs.end())
		this->dogs[it - dogs.begin()].setBreed(new_breed);
}

void Repository::updateName(Dog& d, std::string new_name) {
	if (!DogValidator::validateName(new_name)) {
		throw DogException("Invalid name");
	}
	std::vector<Dog>::iterator it = find(dogs.begin(), dogs.end(), d);
	if (it != dogs.end())
		this->dogs[it - dogs.begin()].setName(new_name);
}

void Repository::updateAge(Dog& d, int new_age) {
	if (!DogValidator::validateAge(new_age)) {
		throw DogException("Invalid age");
	}
	std::vector<Dog>::iterator it = find(dogs.begin(), dogs.end(), d);
	if (it != dogs.end())
		this->dogs[it - dogs.begin()].setAge(new_age);
}

void Repository::updatePhoto(Dog& d, std::string new_photo) {
	if (!DogValidator::validatePhotograph(new_photo)) {
		throw DogException("Invalid photograph");
	}
	std::vector<Dog>::iterator it = find(dogs.begin(), dogs.end(), d);
	if (it != dogs.end())
		this->dogs[it - dogs.begin()].setPhotograph(new_photo);
}

void Repository::delRepo(Dog& d) {
	if (!this->isDogInList(d))
		throw RepoException("Dog not in list!\n");
	std::vector<Dog>::iterator it = find(dogs.begin(), dogs.end(), d);
	if (it != dogs.end()) {
		this->dogs.erase(it);
	}
}
