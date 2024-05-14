#pragma once

#include <QWidget>
#include <QPushButton>

class MainMenu : public QWidget {
    Q_OBJECT
public:
    MainMenu(QWidget *parent = nullptr);

signals:
    void adminMenuRequested();
    void userMenuRequested();
    void exitRequested();

private:
    QPushButton* adminButton;
    QPushButton* userButton;
    QPushButton* exitButton;

private slots:
    void onAdminButtonClicked();
    void onUserButtonClicked();
    void onExitButtonClicked();
};