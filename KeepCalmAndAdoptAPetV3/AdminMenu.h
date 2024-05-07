#pragma once
#include <qwidget.h>
#include <qlistwidget.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include "Controller.h"
#include <QMainWindow>
#include <QVBoxLayout>
#include <QMessageBox>

class AdminMenu : public QWidget {
	Q_OBJECT
private:
	Controller& controller;

	QListWidget* dogListWidget;
	QLineEdit* breedEdit;
	QLineEdit* nameEdit;
	QLineEdit* ageEdit;
	QLineEdit* photoEdit;

	QPushButton* addButton;
	QPushButton* deleteButton;
	QPushButton* backButton;

public:
    AdminMenu(Controller& controller);

private:
	void buildAdminMenu();
	void populateList();

	void addButtonHandler();
	void deleteButtonHandler();

signals:
	void backToMain();

private slots:
    void backToMainMenu() {
		emit backToMain();
    }

};

