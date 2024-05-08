#pragma once
#include <qwidget.h>
#include <qlistwidget.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include "Controller.h"
#include <QMainWindow>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QDialog>
#include <qlayout.h>
#include <qlabel.h>

class EditDogDialog : public QDialog {
    Q_OBJECT
public:
    EditDogDialog(Dog& dog, Controller& controller);

private slots:
    void updateBreed();
    void updateName();
    void updateAge();
    void updatePhoto();
    void goToAdminMenu(); // New slot for going back to admin menu

private:
    Controller& controller;

    QLineEdit* breedEdit;
    QLineEdit* nameEdit;
    QLineEdit* ageEdit;
    QLineEdit* photoEdit;
    QPushButton* updateBreedButton;
    QPushButton* updateNameButton;
    QPushButton* updateAgeButton;
    QPushButton* updatePhotoButton;
    QPushButton* backButton; // New button for going back to admin menu
    Dog& dog;

private:
    void buildEditDogDialogue();
};