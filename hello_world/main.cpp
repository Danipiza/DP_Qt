#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QDebug>

/*
COMPILE:
    $ make clean
    $ make

EXECUTE:
    $ ./project
*/

int GUI(int argc, char *argv[])
{
    // -- init Qt -------------------------------------------------------------
    QApplication app(argc, argv);

    QWidget window;

    QPushButton *close_button, *hello_button;
    
    QVBoxLayout *layout;


    // -- main window ---------------------------------------------------------    
    window.setWindowTitle("Qt GUI Example");

    // -- buttons -------------------------------------------------------------
    
    close_button = new QPushButton("Close");
    // connect the close button to quit the application
    QObject::connect(close_button, &QPushButton::clicked, &app, &QApplication::quit);

    
    hello_button = new QPushButton("Say Hello");
    // connect the hello button to print "Hello there"
    QObject::connect(hello_button, &QPushButton::clicked, []() {
        qDebug() << "Hello there!";
    });


    // -- layout --------------------------------------------------------------
    layout = new QVBoxLayout;
    // add buttons    
    layout->addWidget(hello_button);
    layout->addWidget(close_button);

    // set the layout to the main window
    window.setLayout(layout);

    // show the main window
    window.resize(200, 100);
    window.show();

    return app.exec();
}

int main(int argc, char *argv[]) 
{    
    GUI(argc, argv);

    return 0;
}
