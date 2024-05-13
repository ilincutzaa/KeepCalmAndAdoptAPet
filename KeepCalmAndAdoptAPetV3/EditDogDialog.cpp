
#include "EditDogDialog.h"

EditDogDialog::EditDogDialog(Dog& dog, Controller& controller) : dog(dog), controller(controller) {
    this->buildEditDogDialogue();
    setWindowTitle("Edit Menu");

    setWindowIcon(QIcon("icon.png"));

}

void EditDogDialog::buildEditDogDialogue() {
    QVBoxLayout* layout = new QVBoxLayout(this);

    breedEdit = new QLineEdit(QString::fromStdString(dog.getBreed()));
    nameEdit = new QLineEdit(QString::fromStdString(dog.getName()));
    ageEdit = new QLineEdit(QString::number(dog.getAge()));
    photoEdit = new QLineEdit(QString::fromStdString(dog.getPhotograph()));

    updateBreedButton = new QPushButton("Update Breed");
    updateNameButton = new QPushButton("Update Name");
    updateAgeButton = new QPushButton("Update Age");
    updatePhotoButton = new QPushButton("Update Photo");
    backButton = new QPushButton("Back to Admin Menu");

    connect(updateBreedButton, &QPushButton::clicked, this, &EditDogDialog::updateBreed);
    connect(updateNameButton, &QPushButton::clicked, this, &EditDogDialog::updateName);
    connect(updateAgeButton, &QPushButton::clicked, this, &EditDogDialog::updateAge);
    connect(updatePhotoButton, &QPushButton::clicked, this, &EditDogDialog::updatePhoto);
    connect(backButton, &QPushButton::clicked, this, &EditDogDialog::goToAdminMenu);

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