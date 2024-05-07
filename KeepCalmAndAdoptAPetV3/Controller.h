#pragma once
#include "Repository.h"

class Controller {
private:
	Repository& repo;
public:	
	/// <summary>
	/// Initializes a new instance of the <see cref="Controller"/> class.
	/// </summary>
	/// <param name="repo">The repo.</param>
	Controller(Repository& repo);	
	/// <summary>
	/// Finalizes an instance of the <see cref="Controller"/> class.
	/// </summary>
	~Controller();		
	/// <summary>
	/// Gets the list of all the dogs.
	/// </summary>
	/// <returns></returns>
	std::vector<Dog> getList();
	/// <summary>
	/// Adds the given dog to the list.
	/// </summary>
	/// <param name="d">The dog to be added.</param>
	void addDog(Dog& d);	
	/// <summary>
	/// Deletes the given dog.
	/// </summary>
	/// <param name="d">The dog to be deleted.</param>
	void delDog(Dog& d);	
	/// <summary>
	/// Updates the name of the dog.
	/// </summary>
	/// <param name="d">The dog.</param>
	/// <param name="new_name">The new name.</param>
	void updateDogName(Dog& d, std::string new_name);
	/// <summary>
	/// Updates the dog breed.
	/// </summary>
	/// <param name="d">The dog.</param>
	/// <param name="new_breed">The new breed.</param>
	void updateDogBreed(Dog& d, std::string new_breed);
	/// <summary>
	/// Updates the dog age.
	/// </summary>
	/// <param name="d">The dog.</param>
	/// <param name="new_age">The new age.</param>
	void updateDogAge(Dog& d, int new_age);	
	/// <summary>
	/// Updates the dog photograph.
	/// </summary>
	/// <param name="d">The dog.</param>
	/// <param name="new_photograph">The new photograph.</param>
	void updateDogPhotograph(Dog& d, std::string new_photograph);
	/// <summary>
	/// Gets the dog by identifier.	
	/// </summary>
	/// <param name="id">The identifier.</param>
	/// <returns></returns>
	Dog getDogByID(int id);	
};
