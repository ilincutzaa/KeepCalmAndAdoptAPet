#include "UI.h"

UI::UI(Controller control, AdoptionList* adoption): control(control), adoption(adoption) {
}

UI::~UI() {
}

void UI::displayAllList() {
	std::cout << "-----DOGS-----\n";
	std::vector<Dog> dog_list = this->control.getList();
	for (int i = 0; i < dog_list.size(); i++)
		std::cout << i << ". " << dog_list[i].toString() << std::endl;
	std::cout << "----------\n";
}

void UI::displayMainMenu() {
	int input = 0;
	while (true) {
		while (true) {
			std::cout << "KEEP CALM AND ADOPT A PET\n";
			std::cout << "---MAIN MENU---\n";
			std::cout << "1.Administrator mode\n2.User mode\n0.Exit\n>";
			if (!(std::cin >> input)) {
				std::cout << "Invalid input! Please enter an integer.\n";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				continue;
			}
			break;
		}
		switch (input) {
			case 1: {
				this->displayAdminMenu();
				break;
			}
			case 2: {
				this->displayUserMenu();
				break;
			}
			case 0: {
				std::cout << "bye!";
				return;
			}
			default:
				std::cout << "Invalid option!\n";
				break;
		}
	}
}

void UI::displayAdminMenu() {
	int input = 0;
	while (true) {
		while (true) {
			std::cout << "\n---ADMIN MENU---\n";
			std::cout << "1.Display all dogs\n2.Add a dog\n3.Delete a dog\n4.Update info\n0.Return to Main Menu\n>";
			if (!(std::cin >> input)) {
				std::cout << "Invalid input! Please enter an integer.\n";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				continue;
			}
			break;
		}
		switch (input) {
			case 1: {
				this->displayAllList();
				break;
			}
			case 2: {
				std::string breed, name, photo, c;
				int age = -1;
				while (true) {
					std::cout << "Breed: ";
					std::getline(std::cin, c);
					std::getline(std::cin, breed);
					std::cout << "Name: ";
					std::getline(std::cin, name);
					while (true) {
						std::cout << "Age: ";
						if (!(std::cin >> age)) {
							std::cout << "Invalid input! Please enter an integer.\n";
							std::cin.clear();
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							continue;
						}
						break;
					}
					std::cout << "Photograph: ";
					std::getline(std::cin, c);
					std::getline(std::cin, photo);
					try {
						Dog d{ breed,name,age,photo };
						this->control.addDog(d);
						break;
					}
					catch (const DogException& e) {
						std::cerr << "There was an error: " << e.what() << std::endl;
						break;
					}
				}
				break;
			}
			case 3: {
				while (true) {
					std::cout << "ID: ";
					if (!(std::cin >> input)) {
						std::cout << "Invalid input! Please enter an integer.\n";
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						continue;
					}
					break;
				}
				try {
					Dog d = this->control.getDogByID(input);
					this->control.delDog(d);
				}
				catch (const DogException& e) {
					std::cerr << "There was an error: " << e.what() << std::endl;
				}
				break;
			}
			case 4: {
				try {
					this->displayUpdateMenu();
				}
				catch (const RepoException& e) {
					std::cerr << "There was an error: " << e.what() << std::endl;
				}
				catch (const DogException& e) {
					std::cerr << "There was an error: " << e.what() << std::endl;
				}
				break;
			}
			case 0: 
				return;
			default: {
				std::cout << "Invalid input!";
				break;
			}
		}
	}
}

void UI::start() {
	this->displayMainMenu();
}

void UI::displayUpdateMenu() {
	int input = 0, id = 0;
	while (true) {
		std::cout << "\n---UPDATE MENU---\n";
		std::cout << "ID: ";
		if (!(std::cin >> id)) {
			std::cout << "Invalid input! Please enter an integer.\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		break;
	}
	std::string inp, c;
	while (true) {
		Dog d = this->control.getDogByID(id);
		while (true) {
			std::cout << "\n---DOG " << id << " INFO---\n\n";
			std::cout << d.toString() << std::endl;
			std::cout << "1.Update breed\n2.Update name\n3.Update age\n4.Update photograph\n0.Return to Admin Menu\n>";
			if (!(std::cin >> input)) {
				std::cout << "Invalid input! Please enter an integer.\n";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				continue;
			}
			break;
		}
		switch (input) {
			case 1: {
				std::cout << "New breed: ";
				std::getline(std::cin, c);
				std::getline(std::cin, inp);
				try {
					this->control.updateDogBreed(d, inp);
					break;
				}
				catch (const DogException& e) {
					std::cerr << "There was an error: " << e.what() << std::endl;
				}
				break;
			}
			case 2: {
				std::cout << "New name: ";
				std::getline(std::cin, c);
				std::getline(std::cin, inp);
				try {
					this->control.updateDogName(d, inp);
					break;
				}
				catch (const DogException& e) {
					std::cerr << "There was an error: " << e.what() << std::endl;
				}				break;
			}
			case 3: {
				while (true) {
					while (true) {
						std::cout << "New age: ";
						if (!(std::cin >> input)) {
							std::cout << "Invalid input! Please enter an integer.\n";
							std::cin.clear();
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							continue;
						}
						break;
					}
					try {
						this->control.updateDogAge(d, input);
						break;
					}
					catch (const DogException& e) {
						std::cerr << "There was an error: " << e.what() << std::endl;
					}
				}
				break;
			}
			case 4: {
				std::cout << "New photograph: ";
				std::getline(std::cin, c);
				std::getline(std::cin, inp);
				try {
					this->control.updateDogPhotograph(d, inp);
					break;
				}
				catch (const DogException& e) {
					std::cerr << "There was an error: " << e.what() << std::endl;
				}
				break;
			}
			case 0:
				return;
			default: {
				std::cout << "Invalid input!";
				break;
			}
		}
	}
}

void UI::displayUserMenu() {
	int input = 0, age = -1;
	std::string c, breed, inp;
	while (true) {
		while (true) {
			std::cout << "\n---USER MENU---\n";
			std::cout << "1.See dogs\n2.See dogs (filtered)\n3.See adoption list\n0.Return to Main Menu\n>";
			if (!(std::cin >> input)) {
				std::cout << "Invalid input! Please enter an integer.\n";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				continue;
			}
			break;
		}
		switch (input) {
			case 1: {
				std::vector<Dog> dog_list = this->control.getList();
				this->displayDogs4User(dog_list);
				break;
			}
			case 2: {
				std::cout << "All dogs of breed(leave empty to consider all dogs): ";
				std::getline(std::cin, c);
				std::getline(std::cin, breed);
				std::cout << "Less than age: ";
				std::cin >> age;
				std::vector<Dog> dog_list = this->control.getList();
				std::vector<Dog> filtered1 = this->adoption->filterBreed(dog_list, breed);
				std::vector<Dog> filtered2 = this->adoption->filterAge(filtered1, age);
				this->displayDogs4User(filtered2);
				break;
			}
			case 3: {
				this->adoption->display();
				break;
			}
			case 0:
				return;
			default: {
				std::cout << "Invalid input!";
				break;
			}
		}
	}
}

void UI::displayDogs4User(std::vector<Dog> dog_list) {
	if (dog_list.size() == 0) {
		std::cout << "\nNothing to display\n";
	}
	else {
		int input = 0;
		while (true) {
			for (int i = 0; i < dog_list.size(); i++) {
				std::cout << std::endl;
				std::cout << dog_list[i].toString() << std::endl << std::endl;
				if (this->adoption->isDogAdopted(dog_list[i])) {
					while (true) {
						std::cout << "ADOPTED" << "\n2.Next\n0.Return to User Menu\n>";
						if (!(std::cin >> input)) {
							std::cout << "Invalid input! Please enter an integer.\n";
							std::cin.clear();
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							continue;
						}
						break;
					}
					switch (input) {
						case 2: {
							break;
						}
						case 0:
							return;
						default:
							std::cout << "Invalid input!\n";
					}
				}
				else {
					std::cout << "1.Adopt " << dog_list[i].getName() << "\n2.Next\n0.Return to User Menu\n>";
					std::cin >> input;
					switch (input) {
						case 1: {
							this->adoption->addAdoptionList(dog_list[i]);
							break;
						}
						case 2: {
							break;
						}
						case 0:
							return;
						default:
							std::cout << "Invalid input!\n";
					}
				}
			}
		}
	}
}

void UI::displayAdoptionList() {
	std::cout << "-----ADOPTION LIST-----\n";
	std::vector<Dog> adopt_list = this->adoption->getAdoptionList();
	for (int i = 0; i < adopt_list.size(); i++)
		std::cout << adopt_list[i].toString() << std::endl;
	std::cout << "-----------------------\n";
}
