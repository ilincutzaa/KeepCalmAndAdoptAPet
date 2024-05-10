#pragma once
#include <qwidget.h>
#include <qlistwidget.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include "AdoptionList.h"
#include "Controller.h"
#include <QMainWindow>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QDialog>
#include <qlayout.h>
#include <qlabel.h>
#include "ViewDogs.h"


class UserMenu : public QWidget {
	Q_OBJECT

public:
	UserMenu(AdoptionList* adopt, Controller& control);

private:
	AdoptionList* adopt;
	Controller& controller;

	QPushButton* seeAllButton;
	QPushButton* seeFilteredButton;
	QPushButton* seeAdoptionListButton;
	QPushButton* backButton;

	QLabel* filterAgeLabel;
	QLabel* filterBreedLabel;
	QLineEdit* filterAgeEdit;
	QLineEdit* filterBreedEdit;

	void buildUserMenu();

signals:
	void backToMain();

private slots:

	void seeAllButtonHandler();
	void seeFilteredButtonHandler();
	void seeAdoptionListButtonHandler();

	void backToMainMenu() {
		emit backToMain();
	}
};