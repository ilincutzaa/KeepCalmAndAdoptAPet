#pragma once
#include <qwidget.h>
#include <qlistwidget.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include "AdoptionList.h"
#include <QMainWindow>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QDialog>
#include <qlayout.h>
#include <qlabel.h>

class UserMenu : public QWidget {
	Q_OBJECT

public:
	UserMenu(AdoptionList* adopt);

private:
	AdoptionList* adopt;

	QPushButton* seeAllButton;
	QPushButton* seeFilteredButton;
	QPushButton* seeAdoptionListButton;
	QPushButton* backButton;

	void buildUserMenu();

	//void seeAllButtonHandler();
	//void seeFilteredButtonHandler();
	void seeAdoptionListButtonHandler();


signals:
	void backToMain();

private slots:
	void backToMainMenu() {
		emit backToMain();
	}
};