#include "MainMenu.h"
#include <QHBoxLayout>

MainMenu::MainMenu(QWidget *parent) : QWidget(parent) {
    adminButton = new QPushButton("Admin Menu");
    userButton = new QPushButton("User Menu");
    exitButton = new QPushButton("Exit");

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(adminButton);
    layout->addWidget(userButton);
    layout->addWidget(exitButton);

    setLayout(layout);

    connect(adminButton, &QPushButton::clicked, this, &MainMenu::onAdminButtonClicked);
    connect(userButton, &QPushButton::clicked, this, &MainMenu::onUserButtonClicked);
    connect(exitButton, &QPushButton::clicked, this, &MainMenu::onExitButtonClicked);
}

void MainMenu::onAdminButtonClicked() {
    emit adminMenuRequested();
}

void MainMenu::onUserButtonClicked() {
    emit userMenuRequested();
}

void MainMenu::onExitButtonClicked() {
    emit exitRequested();
}