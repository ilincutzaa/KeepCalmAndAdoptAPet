#pragma once
#include <string>
#include <vector>
#include <sstream>
#include "Utils.h"
#include <iostream>

class DogValidator {
public:
	static std::vector<std::string> validate(std::string breed, std::string name, int age, std::string photograph) {
		std::vector<std::string> errors;

		if (!validateBreed(breed)) {
			errors.push_back("Invalid breed");
		}
		if (!validateName(name)) {
			errors.push_back("Invalid name");
		}
		if (!validateAge(age)) {
			errors.push_back("Invalid age");
		}
		if (!validatePhotograph(photograph)) {
			errors.push_back("Invalid photograph");
		}

		return errors;
	}

	static bool validateBreed(std::string breed) {
		return !breed.empty();
	}
	static bool validateName(std::string name) {
		return !name.empty();
	}
	static bool validateAge(int age) {
		return age >= 0;
	}
	static bool validatePhotograph(std::string photo) {
		if (photo.empty())
			return 0;
		std::vector<std::string> tokens1 = tokenize(photo, '/');
		std::vector<std::string> tokens2 = tokenize(tokens1[3], '.');
		std::string website = tokens1[0] + "//" + tokens1[2] + "/";
		std::string extension = tokens2[1];
		return website == "https://keepcalmandadoptapet.com/" && extension == "jpg";
	}
};
