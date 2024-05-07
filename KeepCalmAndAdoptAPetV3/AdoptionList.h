#pragma once
#include <vector>
#include "Repository.h"

class AdoptionList{
private:
	Repository& repo;
	std::vector<Dog> adoptionList;
public:
	AdoptionList(Repository& r): repo(r) {};
	~AdoptionList() {};
	/// <summary>
	/// Adds the dog to the adoption list.
	/// </summary>
	/// <param name="d">The dog.</param>
	virtual void addAdoptionList(Dog& d);
	/// <summary>
	/// Determines whether the dog is adopted.
	/// </summary>
	/// <param name="d">The dog.</param>
	/// <returns>
	///   <c>true</c> if dog is adopted; otherwise, <c>false</c>.
	/// </returns>
	bool isDogAdopted(Dog d);
	/// <summary>
	/// Returns the adoption list.
	/// </summary>
	/// <returns></returns>
	std::vector<Dog> getAdoptionList();
	/// <summary>
	/// Filters the list of dogs to be a certain given breed
	/// </summary>
	/// <param name="dog_list">The dog list.</param>
	std::vector<Dog> filterBreed(std::vector<Dog>& dog_list, std::string breed);
	/// <summary>
	/// Filters the list of dogs to be less than a given age
	/// </summary>
	/// <param name="dog_list">The dog list.</param>
	std::vector<Dog> filterAge(std::vector<Dog>& dog_list, int age);
	virtual void display() = 0;
};
