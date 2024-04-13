#include "tubesoop1/gui/components/application.h"
#include "tubesoop1/gui/components/messagebox.h"
#include <exception>

Application::Application(int& argc, char** argv) : QApplication(argc, argv) {}
bool Application::notify(QObject *receiver, QEvent *e) {
    try {
        return QApplication::notify(receiver, e);
    } catch (exception &e) {
        MessageBox(window, "Kesalahan", e.what()).exec();
    }
    return false;
}
void Application::setMainWindow(QMainWindow* window) {
    this->window = window;
}