#include "tubesoop1/gui/components/choicedialog.h"
#include <QMessageBox>

ChoiceDialog::ChoiceDialog(QWidget *parent, const QVector<QString>& choices, const QString& title, const QString& headerText, const QString& footerText)
    : QDialog(parent)
{
    int m = 10;
    setContentsMargins(m,m,m,m);
    vLayout.setSpacing(10);

    setWindowTitle(title);

    vLayout.addWidget(&header);
    header.setText(headerText);

    for(int i = 0; i < choices.size(); ++i) {
        NiceButton* button = new NiceButton(choices[i].toStdString());
        button->setStyleNormalCheckable();
        button->setStyleSheet(button->styleSheet() + "QPushButton {text-align: left;}");
        choiceButtons.append(button);
        vLayout.addWidget(button);
        connect(button, &QPushButton::clicked, this, &ChoiceDialog::handleChoice);
    }

    vLayout.addWidget(&footer);
    footer.setText(footerText);

    setLayout(&vLayout);
}

void ChoiceDialog::handleChoice() {
    QPushButton* senderButton = qobject_cast<QPushButton*>(sender());
    if(!senderButton) return;

    int index = choiceButtons.indexOf(senderButton);
    if(index != -1)
        emit choiceMade(index);
}

