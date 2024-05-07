#include <QtWidgets/QApplication>
#include "FileRepository.h"
#include "Controller.h"
#include "AdminMenu.h"
#include "MainMenu.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    // Initialize repository and controller
    std::vector<Dog> v;
    FileRepository repo{ v , "Dogs.txt" };
    Controller control{ repo };

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

    QObject::connect(&mainMenu, &MainMenu::exitRequested, &app, &QApplication::quit);

    // Show main window and main menu
    mainWindow.setCentralWidget(&mainMenu);
    mainWindow.show();

    // Run the application event loop
    return app.exec();
}

