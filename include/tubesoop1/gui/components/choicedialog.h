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
#include "tubesoop1/gui/components/descriptionbutton.h"
#include "tubesoop1/state/state.h"
#include "tubesoop1/resource/resourcefactory.h"
#include <utility>

using namespace std;

/**
 * If the items bigger than 5, it will do pagination
*/
class ChoiceDialog : public QDialog {
    Q_OBJECT
private:
    QVBoxLayout vLayout;

    QLabel header;
    QLabel footer;
    QVector<DescriptionButton*> choiceButtons;


    // Will only be used if the items bigger than 5 (pagination)
    QWidget pageWidget;
    QHBoxLayout hPageLayout;
    int currentPage;
    static int maxItemsPerPage;
    NiceButton nextButton;
    NiceButton prevButton;
    QLabel pageLabel;
    void nextPage();
    void prevPage();
    int totalPage();
    void refreshPage();
    const QVector<pair<string, string>>& choices;
public:
    ChoiceDialog(QWidget* parent, const QVector<pair<string, string>>& choices, const QString& title, const QString& headerText, const QString& footerText);
    ~ChoiceDialog();

signals:
    void choiceMade(int index);

private slots:
    void handleChoice();
};


#endif