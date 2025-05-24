#include <QApplication>
#include "app/AppController.h"

int main(int argc, char *argv[])
{
    // Create the QApplication object
    QApplication app(argc, argv);

    // Create the controller object for the application
    AppController controller(&app);

    // Initialize the application
    controller.initialize();

    // Execute the application
    return app.exec();
}
