#include "ViewDogs.h"

ViewDogs::ViewDogs(const std::vector<Dog>& dogs, Controller& controller, QWidget* parent)
    : QDialog(parent), dogs(dogs), currentIndex(0), controller(controller) {
    // Set the window title
    setWindowTitle("Dogs");

    // Set the window icon
    setWindowIcon(QIcon("icon.png"));
    
    buildViewDogs();
    displayCurrentDog();

}

void ViewDogs::buildViewDogs() {
    QVBoxLayout* layout = new QVBoxLayout(this);

    if(dogs.size()>0)    {
        breedLabel = new QLabel(this);
        nameLabel = new QLabel(this);
        ageLabel = new QLabel(this);
        photoLabel = new QLabel(this);

        layout->addWidget(breedLabel);
        layout->addWidget(nameLabel);
        layout->addWidget(ageLabel);
        layout->addWidget(photoLabel);
        QPushButton* nextButton = new QPushButton("Next", this);
        layout->addWidget(nextButton);
        connect(nextButton, &QPushButton::clicked, this, &ViewDogs::nextButtonClicked);
    }
    else {
        QLabel* emptyLabel = new QLabel{ "Nothing to display" };
        layout->addWidget(emptyLabel);
    }

    QPushButton* exitButton = new QPushButton("Back to User Menu", this);
    layout->addWidget(exitButton);
    connect(exitButton, &QPushButton::clicked, this, &ViewDogs::close);
}

void ViewDogs::displayCurrentDog() {
    if (currentIndex >= 0 && currentIndex < static_cast<int>(dogs.size())) {
        const Dog& currentDog = dogs[currentIndex];
        breedLabel->setText("Breed: " + QString::fromStdString(currentDog.getBreed()));
        nameLabel->setText("Name: " + QString::fromStdString(currentDog.getName()));
        ageLabel->setText("Age: " + QString::number(currentDog.getAge()));

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

        // Specify the URL of the image to download
        QUrl url(QString::fromStdString(currentDog.getPhotograph()));
        QNetworkRequest request(url);
        manager->get(request);
    }
}

void ViewDogs::nextButtonClicked() {
    currentIndex = (currentIndex + 1) % dogs.size();
    displayCurrentDog();
}
