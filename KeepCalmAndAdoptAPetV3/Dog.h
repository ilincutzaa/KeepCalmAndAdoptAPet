#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include "DogValidator.h"
#include "DogException.h"

class Dog {
private:
	std::string breed;
	std::string name;
	int age;
	std::string photograph;
public:
	
	// <summary>
	/// Initializes a new instance of the <see cref="Dog"/> class.
	/// </summary>
	/// <param name="breed">The breed.</param>
	/// <param name="name">The name.</param>
	/// <param name="age">The age. Bigger than 0</param>
	/// <param name="photograph">The photograph. A link to a website</param>
	Dog(std::string breed = "", std::string name = "", int age = -1, std::string photograph = "");
	/// <summary>
	/// Initializes a new copy of a <see cref="Dog"/> object.
	/// </summary>
	/// <param name="d">The d.</param>
	Dog(const Dog& d);
	/// <summary>
	/// Finalizes an instance of the <see cref="Dog"/> class.
	/// </summary>
	~Dog();

	std::string getBreed() const {
		return this->breed;
	}
		
	std::string getName() const {
		return this->name;
	}

	int getAge() const {
		return this->age;
	}

	std::string getPhotograph() const {
		return this->photograph;
	}

	void setBreed(std::string breed) {
		this->breed = breed;
	}

	void setName(std::string name) {
		this->name = name;
	}
	
	void setAge(int age) {
		if (age < 0)
			throw DogException("Age cannot be negative number!");
		this->age = age;
	}

	void setPhotograph(std::string photograph) {
		this->photograph = photograph;
	}

	/// <summary>
	/// Returns the data of the Dog in a string format.
	/// </summary>
	/// <returns></returns>
	std::string toString();

	bool operator==(const Dog& d);

	friend std::istream& operator>>(std::istream& is, Dog& d);
	friend std::ostream& operator<<(std::ostream& is, const Dog& d);

};

