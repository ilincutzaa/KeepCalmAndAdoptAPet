#include "AdoptionList.h"

bool AdoptionList::isDogAdopted(Dog d) {
	std::vector<Dog> adoption_list = this->getAdoptionList();
	std::vector<Dog>::iterator it = find(adoption_list.begin(), adoption_list.end(), d);
	return (it != adoption_list.end());
}

std::vector<Dog> AdoptionList::getAdoptionList() {
	return this->adoptionList;
}

std::vector<Dog> AdoptionList::filterBreed(std::vector<Dog>& dog_list, std::string breed) {
	if (breed.length() == 0)
		return dog_list;
	std::vector<Dog> filtered;
	for (int i = 0; i < dog_list.size(); i++)
		if (compareStrings(dog_list[i].getBreed(), breed))
			filtered.push_back(dog_list[i]);
	return filtered;
}

std::vector<Dog> AdoptionList::filterAge(std::vector<Dog>& dog_list, int age) {
	std::vector<Dog> filtered;
	for (int i = 0; i < dog_list.size(); i++)
		if (dog_list[i].getAge() < age)
			filtered.push_back(dog_list[i]);
	return filtered;
}

void AdoptionList::addAdoptionList(Dog& d) {
	this->adoptionList.push_back(d);
	this->repo.delRepo(d);
}