#ifndef CHOICE_DIALOG_H
#define CHOICE_DIALOG_H

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
#include <QCloseEvent>
#include <QPushButton>
#include <QtCore>
#include "tubesoop1/gui/components/nicebutton.h"
#include "tubesoop1/gui/components/mainwindow.h"
#include "tubesoop1/state/state.h"
#include "tubesoop1/resource/resourcefactory.h"

using namespace std;

class ChoiceDialog : public QDialog {
    Q_OBJECT
private:
    QVBoxLayout vLayout;

    QLabel header;
    QLabel footer;
    QVector<QPushButton*> choiceButtons;
    QVector<QString> choiceList;

public:
    ChoiceDialog(QWidget* parent, const QVector<QString>& choices, const QString& title, const QString& headerText, const QString& footerText);

signals:
    void choiceMade(int index);

private slots:
    void handleChoice();
};


#endif