#pragma once
#include "Dog.h"
#include "RepoException.h"

class Repository {
private:
	std::vector<Dog> dogs;
protected:
	/// <summary>
	/// Generates the starting 10 dogs and adds them to the repo.
	/// </summary>
	void generateDogs();
public:	
	/// <summary>
	/// Initializes a new instance of the <see cref="Repository"/> class.
	/// </summary>
	/// <param name="v">The dynamic vector.</param>
	Repository(std::vector<Dog>& v);
	/// <summary>
	/// Finalizes an instance of the <see cref="Repository"/> class.
	/// </summary>
	virtual ~Repository();	
	/// <summary>
	/// Adds a dog to the repo.
	/// </summary>
	/// <param name="repo">The repo.</param>
	/// <param name="d">The dog.</param>
	virtual void addRepo(Dog& d);
	/// <summary>
	/// Return a copy of the current repo.
	/// </summary>
	/// <returns></returns>
	std::vector<Dog> get_all() const;
	/// <summary>
	/// Gets the number of elements in the repo.
	/// </summary>
	/// <returns></returns>
	int getSizeRepo();
	/// <summary>
	/// Deletes a dog from the repo.
	/// </summary>
	/// <param name="d">The dog.</param>
	virtual void delRepo(Dog& d);
	/// <summary>
	/// Searches the dog.
	/// </summary>
	/// <param name="d">The dog.</param>
	bool isDogInList(Dog& d);

	virtual void updateBreed(Dog& d, std::string new_breed);
	virtual void updateName(Dog& d, std::string new_name);
	virtual void updateAge(Dog& d, int new_age);
	virtual void updatePhoto(Dog& d, std::string new_photo);
};
