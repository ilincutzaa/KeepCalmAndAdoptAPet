#pragma once
#include <QtWidgets>
#include "qcustomplot.h"
#include "Dog.h"

class DogChart : public QWidget {
private:
	std::vector<Dog> dogs;
	std::vector<Dog> filterBreed(std::vector<Dog>& dog_list, std::string breed);
public:
	DogChart(std::vector<Dog> dogs);
};