#pragma once
#include "EditDogDialog.h"
#include "qshortcut.h"
#include "AdoptionList.h"

class AdminMenu : public QWidget {
	Q_OBJECT
private:
	Controller& controller;
	AdoptionList* adopt;
	CommandManager& manager;

	QListWidget* dogListWidget;
	QLineEdit* breedEdit;
	QLineEdit* nameEdit;
	QLineEdit* ageEdit;
	QLineEdit* photoEdit;

	QPushButton* addButton;
	QPushButton* deleteButton;
	QPushButton* backButton;
	QPushButton* editButton;

	QPushButton* undoButton;
	QPushButton* redoButton;

	QShortcut* undoShortCut;
	QShortcut* redoShortCut;

public:
    AdminMenu(Controller& controller, AdoptionList* adopt, CommandManager& manager);

private:
	void buildAdminMenu();
	void populateList();


signals:
	void backToMain();

private slots:

	void addButtonHandler();
	void deleteButtonHandler();
	void editButtonHandler();
	void undoButtonHandler();
	void redoButtonHandler();

    void backToMainMenu() {
		emit backToMain();
    }
};

