#include "tubesoop1/gui/components/choicedialog.h"
#include <QMessageBox>

ChoiceDialog::ChoiceDialog(QWidget *parent, const QVector<pair<string, string>>& choices, const QString& title, const QString& headerText, const QString& footerText)
    : QDialog(parent)
{
    int m = 10;
    setContentsMargins(m,m,m,m);
    vLayout.setSpacing(10);

    setWindowTitle(title);

    vLayout.addWidget(&header);
    header.setText(headerText);

    for(int i = 0; i < choices.size(); ++i) {
        DescriptionButton* button = new DescriptionButton(to_string(i+1), choices[i].first, choices[i].second);
        button->setStyleNormalCheckable();
        choiceButtons.append(button);
        vLayout.addWidget(button);
        connect(button, &QPushButton::clicked, this, &ChoiceDialog::handleChoice);
    }

    vLayout.addWidget(&footer);
    footer.setText(footerText);

    setLayout(&vLayout);
}

void ChoiceDialog::handleChoice() {
    DescriptionButton* senderButton = qobject_cast<DescriptionButton*>(sender());
    if(!senderButton) return;

    int index = choiceButtons.indexOf(senderButton);
    if(index != -1)
        emit choiceMade(index);
}

ChoiceDialog::~ChoiceDialog() {
    for(auto button: choiceButtons) {
        delete button;
    }
}