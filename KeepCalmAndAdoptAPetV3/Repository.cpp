#include "Repository.h"

Repository::Repository(std::vector<Dog>& v) : dogs(v) {
}

Repository::~Repository() {
}

void Repository::addRepo(Dog& d) {
	if (isDogInList(d))
		throw RepoException("Dog already in list!\n");
	dogs.push_back(d);
}

void Repository::addRepoNoUndo(Dog& d) {
	if (isDogInList(d))
		throw RepoException("Dog already in list!\n");
	dogs.push_back(d);
}

std::vector<Dog> Repository::get_all() const {
	std::vector<Dog> nv = this->dogs;
	return nv;
}

int Repository::getSizeRepo() {
	return this->dogs.size();
}

void Repository::generateDogs() {
	Dog dog1("Golden Retriever", "Buddy", 3, "https://upload.wikimedia.org/wikipedia/commons/thumb/4/47/Golden_retriever.jpg/547px-Golden_retriever.jpg");
	Dog dog2("Labrador Retriever", "Max", 5, "https://upload.wikimedia.org/wikipedia/commons/thumb/4/44/Chocolate_Labrador_Retriever.jpg/800px-Chocolate_Labrador_Retriever.jpg");
	Dog dog3("Poodle", "Bailey", 2, "https://static.wikia.nocookie.net/animals-are-cool/images/6/68/Standard-white-poodle.jpg/revision/latest?cb=20180825084022");
	Dog dog4("German Shepherd", "Rocky", 0, "https://miro.medium.com/v2/resize:fit:800/0*LFS-oAro8b1qmeH9.jpg");
	Dog dog5("Beagle", "Charlie", 6, "https://www.dogster.com/wp-content/uploads/2012/05/beagle-dog-standing-outdoor_Artyom-Gantsev_Shutterstock.jpg");
	Dog dog6("Siberian Husky", "Luna", 1, "https://www.animaland.ro/wp-content/uploads/2022/04/Siberian-Husky-1200x800.jpg");
	Dog dog7("Boxer", "Duke", 7, "https://media-be.chewy.com/wp-content/uploads/2021/04/16140537/Boxer_Feature-Image.jpg");
	Dog dog8("Dachshund", "Milo", 4, "https://www.thesprucepets.com/thmb/8UgAnzf_7o7i7qPPr528XtM0IW8=/2121x0/filters:no_upscale():strip_icc()/GettyImages-839279536-313d30c290584bc0a207bc6243263bd4.jpg");
	Dog dog9("Border Collie", "Bella", 8, "https://www.dogster.com/wp-content/uploads/2024/03/blue-merle-border-collie-dog-posing-in-an-urban-setting_Koen-Adriaenssen_Shutterstock.jpg");
	Dog dog10("Rottweiler", "Roxy", 0, "https://ntbrand-wp.s3.amazonaws.com/mystart/wp-content/uploads/2020/03/12150859/My_Rotweiller_00.jpeg");
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
