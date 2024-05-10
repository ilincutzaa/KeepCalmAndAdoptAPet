#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <vector>
#include "Dog.h"
#include "FileAdoption.h"
#include <QtNetwork>

class ViewDogs : public QDialog {
    Q_OBJECT
public:
    ViewDogs(const std::vector<Dog>& dogs, AdoptionList* adopt, QWidget* parent = nullptr);

private:
    AdoptionList* adopt;
    std::vector<Dog> dogs;
    int currentIndex;
    QLabel* breedLabel;
    QLabel* nameLabel;
    QLabel* ageLabel;
    QLabel* photoLabel;
    QLabel* adoptedLabel = nullptr;

    QPushButton* adoptButton;
    QPushButton* nextButton;
    QPushButton* exitButton;

    void buildViewDogs();
    void displayCurrentDog();

private slots:
    void nextButtonClicked();
    void adoptButtonClicked();
};