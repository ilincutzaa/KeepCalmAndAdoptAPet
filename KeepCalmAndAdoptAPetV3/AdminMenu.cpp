#include "AdminMenu.h"
#include <qlayout.h>
#include <qlabel.h>

AdminMenu::AdminMenu(Controller& controller) : controller{ controller } {
	this->buildAdminMenu();
	this->populateList();

	QObject::connect(this->addButton, &QPushButton::clicked, this, &AdminMenu::addButtonHandler);
	QObject::connect(this->deleteButton, &QPushButton::clicked, this, &AdminMenu::deleteButtonHandler);
	QObject::connect(this->backButton, &QPushButton::clicked, this, &AdminMenu::backToMainMenu);
}

void AdminMenu::buildAdminMenu() {
	QHBoxLayout* mainLayout = new QHBoxLayout{ this };
	this->dogListWidget = new QListWidget{};
	mainLayout->addWidget(dogListWidget);

	QGridLayout* rightLayout = new QGridLayout{};

	QLabel* breedLabel = new QLabel{ "Breed" };
	this->breedEdit = new QLineEdit{};
	QLabel* nameLabel = new QLabel{ "Name" };
	this->nameEdit = new QLineEdit{};
	QLabel* ageLabel = new QLabel{ "Age" };
	this->ageEdit = new QLineEdit{};
	QLabel* photoLabel = new QLabel{ "Photograph" };
	this->photoEdit = new QLineEdit{};

	this->photoEdit->setText("https://keepcalmandadoptapet.com/photo.jpg");


	rightLayout->addWidget(breedLabel, 0, 0);
	rightLayout->addWidget(this->breedEdit, 0, 1);
	rightLayout->addWidget(nameLabel, 1, 0);
	rightLayout->addWidget(this->nameEdit, 1, 1);
	rightLayout->addWidget(ageLabel, 2, 0);
	rightLayout->addWidget(this->ageEdit, 2, 1);
	rightLayout->addWidget(photoLabel, 3, 0);
	rightLayout->addWidget(this->photoEdit, 3, 1);

	this->addButton = new QPushButton{ "Add" };
	this->backButton = new QPushButton{ "Back to Main Menu" };
	this->deleteButton = new QPushButton{ "Delete" };

	rightLayout->addWidget(this->addButton, 4, 1);
	rightLayout->addWidget(this->deleteButton, 5, 1);
	rightLayout->addWidget(this->backButton, 5, 3);

	mainLayout->addLayout(rightLayout);
}

void AdminMenu::populateList() {
	this->dogListWidget->clear();

	for (auto d : this->controller.getList()) {

		QListWidgetItem* item = new QListWidgetItem{ QString::fromStdString(d.toString())};
		this->dogListWidget->addItem(item);
	}
}

void AdminMenu::addButtonHandler()
{
	QString breed = this->breedEdit->text();
	QString name = this->nameEdit->text();
	QString age = this->ageEdit->text();
	QString photo = this->photoEdit->text();
	try {
		Dog d{ breed.toStdString(), name.toStdString(), age.toInt(), photo.toStdString() };
		this->controller.addDog(d);
	}
	catch (const DogException& e) {
		QMessageBox::critical(this, "Error:", QString::fromStdString(e.what()));
	}
	this->populateList();
}

void AdminMenu::deleteButtonHandler() {
	int selectedIndex = this->dogListWidget->currentRow();

	if (selectedIndex >= 0) {
		try {
			std::vector<Dog> dogList = this->controller.getList();
			if (selectedIndex < static_cast<int>(dogList.size())) {
				this->controller.delDog(dogList[selectedIndex]);
				this->populateList();
			}
			else {
				QMessageBox::critical(this, "Error:", "Invalid index.");
			}
		}
		catch (const DogException& e) {
			QMessageBox::critical(this, "Error:", QString::fromStdString(e.what()));
		}
	}
	else {
		QMessageBox::critical(this, "Error:", "No item selected.");
	}
}
