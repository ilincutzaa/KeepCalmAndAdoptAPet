#include "AdminMenu.h"


AdminMenu::AdminMenu(Controller& controller, AdoptionList* adopt, CommandManager& manager) : controller( controller ), adopt(adopt), manager(manager) {
	this->buildAdminMenu();
	this->populateList();

	setWindowTitle("Admin Menu");
	setWindowIcon(QIcon("icon.png"));

	setMinimumSize(800, 400);

	QObject::connect(this->addButton, &QPushButton::clicked, this, &AdminMenu::addButtonHandler);
	QObject::connect(this->deleteButton, &QPushButton::clicked, this, &AdminMenu::deleteButtonHandler);
	QObject::connect(this->backButton, &QPushButton::clicked, this, &AdminMenu::backToMainMenu);
	QObject::connect(this->editButton, &QPushButton::clicked, this, &AdminMenu::editButtonHandler);
	QObject::connect(this->chartButton, &QPushButton::clicked, this, &AdminMenu::chartButtonHandler);
	QObject::connect(this->undoButton, &QPushButton::clicked, this, &AdminMenu::undoButtonHandler);
	QObject::connect(this->redoButton, &QPushButton::clicked, this, &AdminMenu::redoButtonHandler);

	QObject::connect(this->undoShortCut, &QShortcut::activated, this, &AdminMenu::undoButtonHandler);
	QObject::connect(this->redoShortCut, &QShortcut::activated, this, &AdminMenu::redoButtonHandler);

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
	this->undoButton = new QPushButton{ "Undo" };
	this->redoButton = new QPushButton{ "Redo" };


	rightLayout->addWidget(this->addButton, 4, 1);
	rightLayout->addWidget(this->deleteButton, 5, 1);
	rightLayout->addWidget(this->backButton, 5, 4);
	rightLayout->addWidget(this->editButton, 4, 4);
	rightLayout->addWidget(this->chartButton, 3, 3);
	rightLayout->addWidget(this->undoButton, 5, 3);
	rightLayout->addWidget(this->redoButton, 4, 3);


	mainLayout->addLayout(rightLayout);

	undoShortCut = new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_Z), this);
	redoShortCut = new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_Y), this);

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
	catch (const RepoException& e) {
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
				std::string photo = dogList[selectedIndex].getPhotograph();
				this->controller.delDog(dogList[selectedIndex]);
				adopt->delDog(photo);
				this->populateList();
			}
			else {
				QMessageBox::critical(this, "Error:", "Invalid index.");
			}
		}
		catch (const DogException& e) {
			QMessageBox::critical(this, "Error:", QString::fromStdString(e.what()));
		}
		catch (const RepoException& e) {
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
		catch (const RepoException& e) {
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

void AdminMenu::undoButtonHandler() {
	manager.undo();
	this->populateList();
}

void AdminMenu::redoButtonHandler() {
	manager.redo();
	this->populateList();
}
