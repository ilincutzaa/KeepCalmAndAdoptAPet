#include "Controller.h"

Controller::Controller(Repository& repo, CommandManager& manager) : repo(repo), manager(manager) {
}

Controller::~Controller() {
}

std::vector<Dog> Controller::getList() {
	return this->repo.get_all();
}

void Controller::addDog(Dog& d) {
	auto addDogCmd = std::make_unique<AddDogCommand>(&repo, d);
	manager.executeCommand(std::move(addDogCmd));
}

void Controller::delDog(Dog& d) {
	std::string photo = d.getPhotograph();
	auto delDogCmd = std::make_unique<DeleteDogCommand>(&repo, d);
	manager.executeCommand(std::move(delDogCmd));
	emit dogDeleted(photo);
}

void Controller::updateDogName(Dog& d, std::string new_name) {
	auto updateNameCmd = std::make_unique<UpdateNameCommand>(&repo, d, new_name);
	manager.executeCommand(std::move(updateNameCmd));
}

void Controller::updateDogBreed(Dog& d, std::string new_breed) {
	auto updateBreedCmd = std::make_unique<UpdateBreedCommand>(&repo, d, new_breed);
	manager.executeCommand(std::move(updateBreedCmd));
}

void Controller::updateDogAge(Dog& d, int new_age) {
	auto updateAgeCmd = std::make_unique<UpdateAgeCommand>(&repo, d, new_age);
	manager.executeCommand(std::move(updateAgeCmd));
}

void Controller::updateDogPhotograph(Dog& d, std::string new_photograph) {
	auto updatePhotoCmd = std::make_unique<UpdatePhotoCommand>(&repo, d, new_photograph);
	manager.executeCommand(std::move(updatePhotoCmd));
}

Dog Controller::getDogByID(int id) {
	std::vector<Dog> dog_list = this->getList();
	if (id >= dog_list.size())
		throw std::runtime_error("Invalid ID");
	return dog_list[id];
}

bool Controller::isDogInList(Dog d) {
	return repo.isDogInList(d);
}



