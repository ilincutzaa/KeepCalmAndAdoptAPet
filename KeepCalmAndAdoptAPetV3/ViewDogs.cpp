#include "ViewDogs.h"
#include <QPixmap>

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

    QPushButton* exitButton = new QPushButton("Exit", this);
    layout->addWidget(exitButton);
    connect(exitButton, &QPushButton::clicked, this, &ViewDogs::close);
}

void ViewDogs::displayCurrentDog() {
    if (currentIndex >= 0 && currentIndex < static_cast<int>(dogs.size())) {
        const Dog& currentDog = dogs[currentIndex];
        breedLabel->setText("Breed: " + QString::fromStdString(currentDog.getBreed()));
        nameLabel->setText("Name: " + QString::fromStdString(currentDog.getName()));
        ageLabel->setText("Age: " + QString::number(currentDog.getAge()));

        QNetworkAccessManager manager;
        QUrl url("https://dogtime.com/wp-content/uploads/sites/12/2024/03/GettyImages-1285465107-e1710251441662.jpg?w=1024");
        QNetworkReply* reply = manager.get(QNetworkRequest(QUrl(url)));
        QObject::connect(reply, &QNetworkReply::finished, [this, reply]() {
            if (reply->error() == QNetworkReply::NoError) {
                QPixmap pixmap;
                pixmap.loadFromData(reply->readAll());
                photoLabel->setPixmap(pixmap.scaled(200, 200, Qt::KeepAspectRatio));
            }
            reply->deleteLater();
            });
    }
}

void ViewDogs::nextButtonClicked() {
    currentIndex = (currentIndex + 1) % dogs.size();
    displayCurrentDog();
}
