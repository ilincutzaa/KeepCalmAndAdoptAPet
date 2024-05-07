#pragma once

#include <QWidget>
#include <QPushButton>

class MainMenu : public QWidget {
    Q_OBJECT
public:
    explicit MainMenu(QWidget *parent = nullptr);

signals:
    void adminMenuRequested();
    void exitRequested();

private:
    QPushButton *adminButton;
    QPushButton *exitButton;

private slots:
    void onAdminButtonClicked();
    void onExitButtonClicked();
};