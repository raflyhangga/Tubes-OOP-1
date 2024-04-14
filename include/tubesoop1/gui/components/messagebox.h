#ifndef MESSAGE_BOX_H
#define MESSAGE_BOX_H

#include <string>
#include <QPushButton>
#include <QSizePolicy>
#include <QDialog>
#include <QFileDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QMainWindow>
#include <QWidget>
#include <QMessageBox>

using namespace std;

class MessageBox : public QMessageBox {
private:

public:
    MessageBox(QWidget* window, string title, string message);
    void setText(string message);
};


#endif