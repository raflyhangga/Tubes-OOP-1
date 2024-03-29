#include <QApplication>
#include <QMainWindow>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QMainWindow window;
    window.setWindowTitle("Simple Window");
    window.setGeometry(100, 100, 400, 200); // (x, y, width, height)
    window.show();

    return app.exec();
}
