#include "AdminMenu.h"


AdminMenu::AdminMenu(Controller& controller) : controller{ controller } {
	this->buildAdminMenu();
	this->populateList();

	setWindowTitle("Admin Menu");
	setWindowIcon(QIcon("icon.png"));

	QObject::connect(this->addButton, &QPushButton::clicked, this, &AdminMenu::addButtonHandler);
	QObject::connect(this->deleteButton, &QPushButton::clicked, this, &AdminMenu::deleteButtonHandler);
	QObject::connect(this->backButton, &QPushButton::clicked, this, &AdminMenu::backToMainMenu);
	QObject::connect(this->editButton, &QPushButton::clicked, this, &AdminMenu::editButtonHandler);
	QObject::connect(this->chartButton, &QPushButton::clicked, this, &AdminMenu::chartButtonHandler);
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
	this->editButton = new QPushButton{ "Edit Menu" };
	this->chartButton = new QPushButton{ "View Chart" };

	rightLayout->addWidget(this->addButton, 4, 1);
	rightLayout->addWidget(this->deleteButton, 5, 1);
	rightLayout->addWidget(this->backButton, 5, 3);
	rightLayout->addWidget(this->editButton, 4, 3);
	rightLayout->addWidget(this->chartButton, 4, 2);

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
	int age = this->ageEdit->text().toInt();
	QString photo = this->photoEdit->text();
	try {
		Dog d{ breed.toStdString(), name.toStdString(), age, photo.toStdString() };
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

void AdminMenu::editButtonHandler() {
	int selectedIndex = this->dogListWidget->currentRow();

	if (selectedIndex >= 0) {
		try {
			std::vector<Dog> dogList = this->controller.getList();
			if (selectedIndex < static_cast<int>(dogList.size())) {
				Dog& selectedDog = dogList[selectedIndex];
				EditDogDialog editDialog(selectedDog, this->controller);
				editDialog.exec();
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

void AdminMenu::chartButtonHandler() {
	DogChart* chart = new DogChart{ this->controller.getList() };
	chart->show();
}
