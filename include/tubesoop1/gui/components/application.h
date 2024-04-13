#ifndef APPLICATION_H
#define APPLICATION_H

#include <QApplication>
#include <QMainWindow>

class Application : public QApplication {
private:
    QMainWindow* window;
public:
    Application(int& argc, char** argv);
    void setMainWindow(QMainWindow* window);
    virtual bool notify(QObject *receiver, QEvent *e);
};

#endif