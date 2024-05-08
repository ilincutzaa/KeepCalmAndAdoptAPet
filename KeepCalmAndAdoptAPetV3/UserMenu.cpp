#include "UserMenu.h"

UserMenu::UserMenu(AdoptionList* adopt): adopt(adopt) {
	this->buildUserMenu();
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

}

//void seeAllButtonHandler() {
//}
//
//void seeFilteredButtonHandler() {
//}
//
//void seeAdoptionListButtonHandler() {
//}
