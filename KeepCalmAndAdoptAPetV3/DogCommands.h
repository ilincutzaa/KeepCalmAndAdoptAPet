#pragma once
#include "CommandManager.h"
#include "FileRepository.h"

class AddDogCommand :public Command {
private:
	Repository* repo;
	Dog dog;
public:
	AddDogCommand(Repository* repo, Dog& dog) : repo(repo), dog(dog) {};
	
	void execute() override {
		repo->addRepo(dog);
	}

	void undo() override {
		repo->delRepo(dog);
	}
};

class DeleteDogCommand : public Command {
private:
	Repository* repo;
	Dog dog;
public:
	DeleteDogCommand(Repository* repo, Dog& dog) : repo(repo), dog(dog) {};

	void execute() override {
		repo->delRepo(dog);
	}

	void undo() override {
		repo->addRepo(dog);
	}
};

class UpdateBreedCommand : public Command {
private:
	Repository* repo;
	Dog dog;
	std::string old_breed;
	std::string new_breed;
public:
	UpdateBreedCommand(Repository* repo, Dog& dog, std::string new_breed) : repo(repo), dog(dog), new_breed(new_breed), old_breed(dog.getBreed()) {};

	void execute() override {
		repo->updateBreed(dog, new_breed);
		dog.setBreed(new_breed);
	}

	void undo() override {
		repo->updateBreed(dog, old_breed);
		dog.setBreed(old_breed);
	}
};

class UpdateNameCommand : public Command {
private:
	Repository* repo;
	Dog dog;
	std::string old_name;
	std::string new_name;
public:
	UpdateNameCommand(Repository* repo, Dog& dog, std::string new_name) : repo(repo), dog(dog), new_name(new_name), old_name(dog.getName()) {};

	void execute() override {
		repo->updateName(dog, new_name);
		dog.setName(new_name);
	}

	void undo() override {
		repo->updateName(dog, old_name);
		dog.setName(old_name);
	}
};

class UpdateAgeCommand : public Command {
private:
	Repository* repo;
	Dog dog;
	int old_age;
	int new_age;

public:
	UpdateAgeCommand(Repository* repo, Dog& dog, int new_age) : repo(repo), dog(dog), new_age(new_age), old_age(dog.getAge()) {};

	void execute() override {
		repo->updateAge(dog, new_age);
		dog.setAge(new_age);
	}

	void undo() override {
		repo->updateAge(dog, old_age);
		dog.setAge(old_age);
	}
};

class UpdatePhotoCommand : public Command {
private:
	Repository* repo;
	Dog dog;
	std::string old_photo;
	std::string new_photo;
public:
	UpdatePhotoCommand(Repository* repo, Dog& dog, std::string new_photo) : repo(repo), dog(dog), new_photo(new_photo), old_photo(dog.getPhotograph()) {};

	void execute() override {
		repo->updatePhoto(dog, new_photo);
		dog.setPhotograph(new_photo);
	}

	void undo() override {
		repo->updatePhoto(dog, old_photo);
		dog.setPhotograph(old_photo);
	}
};