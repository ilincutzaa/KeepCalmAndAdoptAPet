#pragma once
#include "EditDogDialog.h"
#include "DogChart.h"
#include "AdoptionList.h"

class AdminMenu : public QWidget {
	Q_OBJECT
private:
	Controller& controller;
	AdoptionList* adopt;

	QListWidget* dogListWidget;
	QLineEdit* breedEdit;
	QLineEdit* nameEdit;
	QLineEdit* ageEdit;
	QLineEdit* photoEdit;

	QPushButton* addButton;
	QPushButton* deleteButton;
	QPushButton* backButton;
	QPushButton* editButton;
	QPushButton* chartButton;

public:
    AdminMenu(Controller& controller, AdoptionList* adopt);

private:
	void buildAdminMenu();
	void populateList();


signals:
	void backToMain();

private slots:

	void addButtonHandler();
	void deleteButtonHandler();
	void editButtonHandler();
	void chartButtonHandler();

    void backToMainMenu() {
		emit backToMain();
    }
};

