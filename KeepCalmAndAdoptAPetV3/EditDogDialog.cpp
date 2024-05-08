
#include "EditDogDialog.h"

EditDogDialog::EditDogDialog(Dog& dog, Controller& controller) : dog(dog), controller(controller) {
    this->buildEditDogDialogue();
}

void EditDogDialog::buildEditDogDialogue() {
    QVBoxLayout* layout = new QVBoxLayout(this);

    // Create QLineEdit widgets for breed, name, age, and photo
    breedEdit = new QLineEdit(QString::fromStdString(dog.getBreed()));
    nameEdit = new QLineEdit(QString::fromStdString(dog.getName()));
    ageEdit = new QLineEdit(QString::number(dog.getAge()));
    photoEdit = new QLineEdit(QString::fromStdString(dog.getPhotograph()));

    // Create buttons for updating each attribute
    updateBreedButton = new QPushButton("Update Breed");
    updateNameButton = new QPushButton("Update Name");
    updateAgeButton = new QPushButton("Update Age");
    updatePhotoButton = new QPushButton("Update Photo");
    backButton = new QPushButton("Back to Admin Menu");

    // Connect each button to its corresponding slot
    connect(updateBreedButton, &QPushButton::clicked, this, &EditDogDialog::updateBreed);
    connect(updateNameButton, &QPushButton::clicked, this, &EditDogDialog::updateName);
    connect(updateAgeButton, &QPushButton::clicked, this, &EditDogDialog::updateAge);
    connect(updatePhotoButton, &QPushButton::clicked, this, &EditDogDialog::updatePhoto);
    connect(backButton, &QPushButton::clicked, this, &EditDogDialog::goToAdminMenu);

    // Add widgets to the layout
    layout->addWidget(new QLabel("Breed:"));
    layout->addWidget(breedEdit);
    layout->addWidget(updateBreedButton);
    layout->addWidget(new QLabel("Name:"));
    layout->addWidget(nameEdit);
    layout->addWidget(updateNameButton);
    layout->addWidget(new QLabel("Age:"));
    layout->addWidget(ageEdit);
    layout->addWidget(updateAgeButton);
    layout->addWidget(new QLabel("Photo:"));
    layout->addWidget(photoEdit);
    layout->addWidget(updatePhotoButton);
    layout->addWidget(updatePhotoButton);
    layout->addWidget(backButton);

    // Set the layout for the dialog
    setLayout(layout);
}

void EditDogDialog::updateBreed() {
    QString newBreed = breedEdit->text();
    controller.updateDogBreed(dog, newBreed.toStdString());
    accept();
}

void EditDogDialog::updateName() {
    QString newName = nameEdit->text();
    controller.updateDogName(dog, newName.toStdString());
    accept();
}

void EditDogDialog::updateAge() {
    int newAge = ageEdit->text().toInt();
    controller.updateDogAge(dog, newAge);
    accept();
}

void EditDogDialog::updatePhoto() {
    QString newPhoto = photoEdit->text();
    controller.updateDogPhotograph(dog, newPhoto.toStdString());
    accept();
}

void EditDogDialog::goToAdminMenu() {
    accept();
}