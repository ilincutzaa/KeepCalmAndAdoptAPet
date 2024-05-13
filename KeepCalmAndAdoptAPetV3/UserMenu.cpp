#include "UserMenu.h"

UserMenu::UserMenu(AdoptionList* adopt, Controller& controller): adopt(adopt), controller(controller) {
	this->buildUserMenu();
	setWindowTitle("User Menu");

	setWindowIcon(QIcon("icon.png"));

}

void UserMenu::buildUserMenu() {
	QVBoxLayout* mainLayout = new QVBoxLayout{ this };

	seeAllButton = new QPushButton("See all dogs");
	seeFilteredButton = new QPushButton("See dogs (filtered)");
	seeAdoptionListButton = new QPushButton("See adoption list");
	backButton = new QPushButton("Back to Main Menu");

	mainLayout->addWidget(seeAllButton);

	QHBoxLayout* filterLayout = new QHBoxLayout;

	filterAgeLabel = new QLabel{ "Filter: Less than age" };
	filterBreedLabel = new QLabel{ "Filter: Breed" };

	filterAgeEdit = new QLineEdit{};
	filterBreedEdit = new QLineEdit{};

	filterLayout->addWidget(filterAgeLabel);
	filterLayout->addWidget(filterAgeEdit);
	filterLayout->addWidget(filterBreedLabel);
	filterLayout->addWidget(filterBreedEdit);

	mainLayout->addLayout(filterLayout);


	mainLayout->addWidget(seeFilteredButton);
	mainLayout->addWidget(seeAdoptionListButton);
	mainLayout->addWidget(backButton);

	setLayout(mainLayout);

	QObject::connect(this->backButton, &QPushButton::clicked, this, &UserMenu::backToMainMenu);
	QObject::connect(this->seeAdoptionListButton, &QPushButton::clicked, this, &UserMenu::seeAdoptionListButtonHandler);
	QObject::connect(this->seeAllButton, &QPushButton::clicked, this, &UserMenu::seeAllButtonHandler);
	QObject::connect(this->seeFilteredButton, &QPushButton::clicked, this, &UserMenu::seeFilteredButtonHandler);
}

void UserMenu::seeAllButtonHandler() {
	ViewDogs viewDogs(this->controller.getList(), this->adopt);
	viewDogs.exec();
}

void UserMenu::seeFilteredButtonHandler() {
	QString ageText = filterAgeEdit->text();
	QString breedText = filterBreedEdit->text();
	std::vector<Dog> allDogs = this->controller.getList();
	std::vector<Dog> breedfiltered = this->adopt->filterBreed(allDogs, breedText.toStdString());
	std::vector<Dog> filtered = this->adopt->filterAge(breedfiltered, ageText.toInt());
	ViewDogs viewDogs(filtered, this->adopt);
	viewDogs.exec();
}

void UserMenu::seeAdoptionListButtonHandler() {
	adopt->display();
}

