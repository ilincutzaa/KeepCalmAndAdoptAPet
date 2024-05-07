#include "Dog.h"

Dog::Dog(std::string breed, std::string name, int age, std::string photograph) {
	std::vector<std::string> errors = DogValidator::validate(breed, name, age, photograph);
	if (!errors.empty()) {
		std::string errorMessage = "Error creating Dog:";
		for (const std::string& error : errors) {
			errorMessage += " " + error + ";";
		}
		throw DogException(errorMessage);
	}

	this->breed = breed;
	this->name = name;
	this->age = age;
	this->photograph = photograph;
}

Dog::Dog(const Dog& d) {
	this->breed = d.breed;
	this->name = d.name;
	this->age = d.age;
	this->photograph = d.photograph;
}

Dog::~Dog() {
}

std::string Dog::toString(){
	std::stringstream txt;
	txt << "Breed: " << this->breed << " | Name: " << this->name << " | Age: " << this->age << " | Photograph: " << this->photograph;
	return txt.str();
}

bool Dog::operator==(const Dog& d) {
	return (this->name == d.name) && (this->breed == d.breed) && (this->age == d.age) && (this->photograph == d.photograph);
}

std::istream& operator>>(std::istream& is, Dog& d) {
	std::string line;
	if (!getline(is, line))
		return is;
	
	std::vector<std::string> tokens = tokenize(line, '|');
	d.breed = tokenize(tokens[0], ':')[1];
	d.name = tokenize(tokens[1], ':')[1];
	d.age = stoi(tokenize(tokens[2], ':')[1]);
	d.photograph = "";
	auto p = tokenize(tokens[3], ':');
	for (int i = 1; i < p.size() - 1; i++)
		d.photograph += p[i] + ':';
	d.photograph += p[p.size() - 1];

	return is;
}

std::ostream& operator<<(std::ostream& os, const Dog& d) {
	os << "Breed: " << d.breed << " | Name: " << d.name << " | Age: " << d.age << " | Photograph: " << d.photograph << "\n";
	return os;
}

