#pragma once
#include "Controller.h"
#include "AdoptionList.h"

class UI {
private:
	Controller control;
	AdoptionList* adoption;
public:	
	/// <summary>
	/// Initializes a new instance of the <see cref="UI"/> class.
	/// </summary>
	/// <param name="control">The controller.</param>
	UI(Controller control, AdoptionList* adoption);	
	/// <summary>
	/// Finalizes an instance of the <see cref="UI"/> class.
	/// </summary>
	~UI();	
	/// <summary>
	/// Displays the list of all dogs.
	/// </summary>
	void displayAllList();	
	/// <summary>
	/// Displays the menu.
	/// </summary>
	void displayMainMenu();	
	/// <summary>
	/// Displays the menu for admin.
	/// </summary>
	void displayAdminMenu();
	/// <summary>
	/// Starts the UI
	/// </summary>
	void start();	
	/// <summary>
	/// Displays the update menu.
	/// </summary>
	void displayUpdateMenu();
	/// <summary>
	/// Displays the menu for user.
	/// </summary>
	void displayUserMenu();	
	/// <summary>
	/// Displays the dogs for the user.
	/// </summary>
	/// <param name="dog_list">The dog list.</param>
	void displayDogs4User(std::vector<Dog> dog_list);
	/// <summary>
	/// Displays the adoption list.
	/// </summary>
	void displayAdoptionList();
};
