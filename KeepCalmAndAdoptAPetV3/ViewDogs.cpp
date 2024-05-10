#include "ViewDogs.h"

ViewDogs::ViewDogs(const std::vector<Dog>& dogs, AdoptionList* adopt, QWidget* parent)
    : QDialog(parent), dogs(dogs), currentIndex(0), adopt(adopt) {
    setWindowTitle("Dogs");
    setWindowIcon(QIcon("icon.png"));
    
    buildViewDogs();
    displayCurrentDog();

}

void ViewDogs::buildViewDogs() {
    QVBoxLayout* layout = new QVBoxLayout(this);

    if(dogs.size() > 0) {
        breedLabel = new QLabel(this);
        nameLabel = new QLabel(this);
        ageLabel = new QLabel(this);
        photoLabel = new QLabel(this);

        layout->addWidget(breedLabel);
        layout->addWidget(nameLabel);
        layout->addWidget(ageLabel);
        layout->addWidget(photoLabel);

        adoptButton = new QPushButton("Adopt", this);
        layout->addWidget(adoptButton);
        connect(adoptButton, &QPushButton::clicked, this, &ViewDogs::adoptButtonClicked);

        nextButton = new QPushButton("Next", this);
        layout->addWidget(nextButton);
        connect(nextButton, &QPushButton::clicked, this, &ViewDogs::nextButtonClicked);
    }
    else {
        QLabel* emptyLabel = new QLabel{ "Nothing to display" };
        layout->addWidget(emptyLabel);
    }

    exitButton = new QPushButton("Back to User Menu", this);
    layout->addWidget(exitButton);
    connect(exitButton, &QPushButton::clicked, this, &ViewDogs::close);
}

void ViewDogs::displayCurrentDog() {
    if (currentIndex >= 0 && currentIndex < static_cast<int>(dogs.size())) {
        const Dog& currentDog = dogs[currentIndex];
        breedLabel->setText("Breed: " + QString::fromStdString(currentDog.getBreed()));
        nameLabel->setText("Name: " + QString::fromStdString(currentDog.getName()));
        ageLabel->setText("Age: " + QString::number(currentDog.getAge()));

        // Check if the current dog is adopted
        if (this->adopt->isDogAdopted(currentDog)) {
            // If adopted, hide the adopt button and display "ADOPTED" label
            if (adoptButton) {
                adoptButton->hide();
            }
            // Remove any previously added "ADOPTED" label
            if (adoptedLabel) {
                adoptedLabel->deleteLater();
                adoptedLabel = nullptr;
            }
            adoptedLabel = new QLabel("ADOPTED", this);
            layout()->addWidget(adoptedLabel);
        }
        else {
            // If not adopted, show the adopt button and remove any "ADOPTED" label
            if (adoptButton) {
                adoptButton->show();
            }
            // Remove any previously added "ADOPTED" label
            if (adoptedLabel) {
                adoptedLabel->deleteLater();
                adoptedLabel = nullptr;
            }
        }

        QNetworkAccessManager* manager = new QNetworkAccessManager(this);
        connect(manager, &QNetworkAccessManager::finished, this, [=](QNetworkReply* reply) {
            if (reply->error() == QNetworkReply::NoError) {
                QByteArray imageData = reply->readAll();
                QPixmap pixmap;
                pixmap.loadFromData(imageData);
                photoLabel->setPixmap(pixmap.scaled(QSize(400, 400), Qt::KeepAspectRatio));
            }
            reply->deleteLater();
            });

        QUrl url(QString::fromStdString(currentDog.getPhotograph()));
        QNetworkRequest request(url);
        manager->get(request);
    }
}

void ViewDogs::adoptButtonClicked() {
    Dog currentDog = dogs[currentIndex];
    this->adopt->addAdoptionList(currentDog);
    this->nextButtonClicked();
}

void ViewDogs::nextButtonClicked() {
    currentIndex = (currentIndex + 1) % dogs.size();
    displayCurrentDog();
}
