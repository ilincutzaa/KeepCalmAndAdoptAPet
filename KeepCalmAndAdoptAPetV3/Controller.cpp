#include "Controller.h"

Controller::Controller(Repository& repo) : repo(repo) {
}

Controller::~Controller() {
}

std::vector<Dog> Controller::getList() {
	return this->repo.get_all();
}

void Controller::addDog(Dog& d) {
	this->repo.addRepo(d);
}

void Controller::delDog(Dog& d) {
	this->repo.delRepo(d);
}

void Controller::updateDogName(Dog& d, std::string new_name) {
	this->repo.updateName(d, new_name);
}

void Controller::updateDogBreed(Dog& d, std::string new_breed) {
	this->repo.updateBreed(d, new_breed);
}

void Controller::updateDogAge(Dog& d, int new_age) {
	this->repo.updateAge(d, new_age);
}

void Controller::updateDogPhotograph(Dog& d, std::string new_photograph) {
	this->repo.updatePhoto(d, new_photograph);
}

Dog Controller::getDogByID(int id) {
	std::vector<Dog> dog_list = this->getList();
	if (id >= dog_list.size())
		throw std::runtime_error("Invalid ID");
	return dog_list[id];
}



