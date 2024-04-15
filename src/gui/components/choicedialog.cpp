#include "tubesoop1/gui/components/choicedialog.h"
#include <QMessageBox>

ChoiceDialog::ChoiceDialog(QWidget *parent, const QVector<pair<string, string>>& choices, const QString& title, const QString& headerText, const QString& footerText)
    : QDialog(parent), choices(choices)
{
    int m = 10;
    setContentsMargins(m,m,m,m);
    vLayout.setSpacing(10);

    setWindowTitle(title);

    vLayout.addWidget(&header);
    header.setText(headerText);

    currentPage = 0;
    int choiceSize = choices.size(); 
    if(choiceSize > ChoiceDialog::maxItemsPerPage) {
        choiceSize = ChoiceDialog::maxItemsPerPage;
    }
    for(int i = 0; i < choiceSize; ++i) {
        DescriptionButton* button = new DescriptionButton(to_string(i+1), choices[i].first, choices[i].second);
        button->setStyleNormalCheckable();
        choiceButtons.append(button);
        vLayout.addWidget(button);
        connect(button, &QPushButton::clicked, this, &ChoiceDialog::handleChoice);
    }

    int buttonWidth = 100; hPageLayout.setContentsMargins(0,0,0,0);
    if(choices.size() > ChoiceDialog::maxItemsPerPage) {
        vLayout.addWidget(&pageWidget);
        pageWidget.setLayout(&hPageLayout);

        hPageLayout.addWidget(&prevButton);
        prevButton.setText("Prev"); prevButton.setFixedWidth(buttonWidth);
        connect(&prevButton, &QPushButton::clicked, this, &ChoiceDialog::prevPage);

        hPageLayout.addStretch();
        hPageLayout.addWidget(&pageLabel);
        pageLabel.setText("1/" + QString::number(totalPage()));
        hPageLayout.addStretch();

        hPageLayout.addWidget(&nextButton);
        nextButton.setText("Next"); nextButton.setFixedWidth(buttonWidth);
        connect(&nextButton, &QPushButton::clicked, this, &ChoiceDialog::nextPage);
    }

    vLayout.addWidget(&footer);
    footer.setText(footerText);

    setLayout(&vLayout);
}
int ChoiceDialog::maxItemsPerPage = 5;

void ChoiceDialog::handleChoice() {
    DescriptionButton* senderButton = qobject_cast<DescriptionButton*>(sender());
    if(!senderButton) return;

    int index = choiceButtons.indexOf(senderButton);
    if(index != -1)
        emit choiceMade(index + currentPage * ChoiceDialog::maxItemsPerPage);
}

ChoiceDialog::~ChoiceDialog() {
    for(auto button: choiceButtons) {
        delete button;
    }
}

void ChoiceDialog::nextPage(){
    cout << choices.size() << endl; 
    currentPage = (currentPage + 1) % totalPage();
    refreshPage();
}

void ChoiceDialog::prevPage(){
    currentPage--; if(currentPage < 0) currentPage = totalPage() - 1;
    refreshPage();
}

int ChoiceDialog::totalPage(){
    return choices.size() / ChoiceDialog::maxItemsPerPage;
}

void ChoiceDialog::refreshPage(){
    pageLabel.setText(QString::number(currentPage + 1) + "/" + QString::number(totalPage()));
    for(int i = 0; i < ChoiceDialog::maxItemsPerPage; i++){
        int idx = i + currentPage * ChoiceDialog::maxItemsPerPage;
        if(idx >= choices.size()) {
            choiceButtons[i]->setVisible(false);
            continue;
        }
        choiceButtons[i]->setVisible(true);
        choiceButtons[i]->setText(
            to_string(idx + 1),
            choices[idx].first,
            choices[idx].second
        );
    }
}