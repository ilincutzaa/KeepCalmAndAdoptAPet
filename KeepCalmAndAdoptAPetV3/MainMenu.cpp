#include "MainMenu.h"
#include <QHBoxLayout>

MainMenu::MainMenu(QWidget *parent) : QWidget(parent) {
    adminButton = new QPushButton("Admin Menu");
    exitButton = new QPushButton("Exit");

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(adminButton);
    layout->addWidget(exitButton);

    setLayout(layout);

    connect(adminButton, &QPushButton::clicked, this, &MainMenu::onAdminButtonClicked);
    connect(exitButton, &QPushButton::clicked, this, &MainMenu::onExitButtonClicked);
}

void MainMenu::onAdminButtonClicked() {
    emit adminMenuRequested();
}

void MainMenu::onExitButtonClicked() {
    emit exitRequested();
}