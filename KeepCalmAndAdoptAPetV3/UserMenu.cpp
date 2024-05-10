#include "UserMenu.h"

UserMenu::UserMenu(AdoptionList* adopt, Controller& controller): adopt(adopt), controller(controller) {
	this->buildUserMenu();
	// Set the window title
	setWindowTitle("User Menu");

	// Set the window icon
	setWindowIcon(QIcon("icon.png"));

}

void UserMenu::buildUserMenu() {
	QVBoxLayout* layout = new QVBoxLayout{ this };

	seeAllButton = new QPushButton("See all dogs");
	seeFilteredButton = new QPushButton("See dogs(filtered)");
	seeAdoptionListButton = new QPushButton("See adoption list");
	backButton = new QPushButton("Back to Main Menu");

	layout->addWidget(seeAllButton);
	layout->addWidget(seeFilteredButton);
	layout->addWidget(seeAdoptionListButton);
	layout->addWidget(backButton);

	setLayout(layout);

	QObject::connect(this->backButton, &QPushButton::clicked, this, &UserMenu::backToMainMenu);
	QObject::connect(this->seeAdoptionListButton, &QPushButton::clicked, this, &UserMenu::seeAdoptionListButtonHandler);
	QObject::connect(this->seeAllButton, &QPushButton::clicked, this, &UserMenu::seeAllButtonHandler);
}

void UserMenu::seeAllButtonHandler() {
	ViewDogs viewDogs(this->controller.getList(), this->controller);
	viewDogs.exec();
}

void UserMenu::seeAdoptionListButtonHandler() {
	adopt->display();
}

