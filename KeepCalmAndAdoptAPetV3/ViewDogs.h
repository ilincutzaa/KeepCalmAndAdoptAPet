#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <vector>
#include "Dog.h"
#include "Controller.h"
#include <QtNetwork>

class ViewDogs : public QDialog {
    Q_OBJECT
public:
    ViewDogs(const std::vector<Dog>& dogs, Controller& controller, QWidget* parent = nullptr);

private:
    Controller& controller;
    std::vector<Dog> dogs;
    int currentIndex;
    QLabel* breedLabel;
    QLabel* nameLabel;
    QLabel* ageLabel;
    QLabel* photoLabel;

    void buildViewDogs();
    void displayCurrentDog();

private slots:
    void nextButtonClicked();
};