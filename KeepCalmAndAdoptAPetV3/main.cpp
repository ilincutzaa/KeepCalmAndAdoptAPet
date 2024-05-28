#include <QtWidgets/QApplication>
#include <QMessageBox>
#include <QInputDialog>
#include <QStringList>
#include <qmainwindow.h>
#include "FileRepository.h"
#include "Controller.h"
#include "AdminMenu.h"
#include "MainMenu.h"
#include "FileAdoption.h"
#include "UserMenu.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    QIcon appIcon("icon.png");

    std::vector<Dog> v;
    FileRepository repo{ v , "Dogs.txt" };
    Controller control{ repo };

    AdoptionList* adoptionList = nullptr;

    UserMenu* userMenu = nullptr;

    QInputDialog inputDialog;

    inputDialog.setWindowIcon(appIcon);

    QStringList items;
    items << "CSV" << "HTML";
    bool ok;
    QString selectedItem = inputDialog.getItem(nullptr, "Select File Type",
        "Choose the file type to save the adoption list:",
        items, 0, false, &ok);

    if (!ok)
        return 0;


    if (selectedItem == "CSV") {
        std::ofstream ofs;
        ofs.open("adoptedDogs.csv", std::ofstream::out | std::ofstream::trunc);
        ofs.close();
        adoptionList = new CSVFileAdoption(repo, "adoptedDogs.csv");
    }
    else {
        std::ofstream ofs;
        ofs.open("adoptedDogs.html", std::ofstream::out | std::ofstream::trunc);
        ofs.close();
        adoptionList = new HTMLFileAdoption(repo, "adoptedDogs.html");
    }

    QMainWindow mainWindow;
    MainMenu mainMenu;

    mainWindow.setWindowIcon(appIcon);

    AdminMenu* adminMenu = nullptr;

    QObject::connect(&mainMenu, &MainMenu::adminMenuRequested, [&mainWindow, &control, &mainMenu, &adminMenu, &adoptionList]() {
        if (adminMenu == nullptr) {
            adminMenu = new AdminMenu(control, adoptionList);
            QObject::connect(adminMenu, &AdminMenu::backToMain, [&mainWindow, &mainMenu, &adminMenu]() {
                adminMenu->hide();
                delete adminMenu;
                adminMenu = nullptr;
                mainMenu.show();
                mainWindow.show();
                });
        }
        mainMenu.hide();
        mainWindow.hide();
        adminMenu->show();
        });



    QObject::connect(&mainMenu, &MainMenu::userMenuRequested, [&mainWindow, &control, &mainMenu, &userMenu, &adoptionList]() {
        if (userMenu == nullptr) {
            userMenu = new UserMenu(adoptionList, control);
            QObject::connect(userMenu, &UserMenu::backToMain, [&mainWindow, &mainMenu, &userMenu]() {
                userMenu->hide();
                delete userMenu;
                userMenu = nullptr;
                mainMenu.show();
                mainWindow.show();
                });
        }
        mainMenu.hide();
        mainWindow.hide(); 
        userMenu->show();
        });

    QObject::connect(&mainMenu, &MainMenu::exitRequested, &app, &QApplication::quit);

    mainWindow.setCentralWidget(&mainMenu);
    mainWindow.show();

    return app.exec();
}

