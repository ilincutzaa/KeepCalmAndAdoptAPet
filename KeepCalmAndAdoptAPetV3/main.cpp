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

    // Initialize repository and controller
    std::vector<Dog> v;
    FileRepository repo{ v , "Dogs.txt" };
    Controller control{ repo };

    AdoptionList* adoptionList = nullptr;

    // Create userMenu
    UserMenu* userMenu = nullptr;

    // Ask the user to select the file type
    QStringList items;
    items << "CSV" << "HTML";
    bool ok;
    QString selectedItem = QInputDialog::getItem(nullptr, "Select File Type",
        "Choose the file type to save the adoption list:",
        items, 0, false, &ok);
    if (!ok) // User canceled
        return 0;

    if (selectedItem == "CSV") {
        std::ofstream ofs;
        ofs.open("adoptedDogs.csv", std::ofstream::out | std::ofstream::trunc);
        ofs.close();
        CSVFileAdoption* adoptionList = new CSVFileAdoption(repo, "adoptedDogs.csv");
    }
    else {
        std::ofstream ofs;
        ofs.open("adoptedDogs.html", std::ofstream::out | std::ofstream::trunc);
        ofs.close();
        HTMLFileAdoption* adoptionList = new HTMLFileAdoption(repo, "adoptedDogs.html");
    }

    // Create main window and main menu
    QMainWindow mainWindow;
    MainMenu mainMenu;

    // Create admin menu
    AdminMenu* adminMenu = nullptr;

    // Connect signals from main menu to slots
    QObject::connect(&mainMenu, &MainMenu::adminMenuRequested, [&mainWindow, &control, &mainMenu, &adminMenu]() {
        if (adminMenu == nullptr) {
            adminMenu = new AdminMenu(control);
            // Connect backToMain signal to lambda slot
            QObject::connect(adminMenu, &AdminMenu::backToMain, [&mainWindow, &mainMenu, &adminMenu]() {
                adminMenu->hide(); // Hide admin menu
                delete adminMenu;
                adminMenu = nullptr;
                mainMenu.show(); // Show main menu
                mainWindow.show(); // Show main window
                });
        }
        mainMenu.hide(); // Hide main menu
        mainWindow.hide(); // Hide main window
        adminMenu->show(); // Show admin menu
        });



    // Connect signals from main menu to slots
    QObject::connect(&mainMenu, &MainMenu::userMenuRequested, [&mainWindow, &control, &mainMenu, &userMenu, &adoptionList]() {
        if (userMenu == nullptr) {
            userMenu = new UserMenu(adoptionList);
            // Connect backToMain signal to lambda slot
            QObject::connect(userMenu, &UserMenu::backToMain, [&mainWindow, &mainMenu, &userMenu]() {
                userMenu->hide(); // Hide admin menu
                delete userMenu;
                userMenu = nullptr;
                mainMenu.show(); // Show main menu
                mainWindow.show(); // Show main window
                });
        }
        mainMenu.hide(); // Hide main menu
        mainWindow.hide(); // Hide main window
        userMenu->show(); // Show admin menu
        });

    QObject::connect(&mainMenu, &MainMenu::exitRequested, &app, &QApplication::quit);

    // Show main window and main menu
    mainWindow.setCentralWidget(&mainMenu);
    mainWindow.show();

    // Run the application event loop
    return app.exec();
}

