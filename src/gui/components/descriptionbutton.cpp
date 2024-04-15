#include "tubesoop1/gui/components/descriptionbutton.h"
#include <QSize>

DescriptionButton::DescriptionButton() : NiceButton() {
}
DescriptionButton::DescriptionButton(string number, string title, string description) : NiceButton() {
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    numberLabel.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    titleLabel.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    descriptionLabel.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    setMinimumSize(QSize(520, 65));

    numberLabel.setText(QString::fromStdString(number));
    titleLabel.setText(QString::fromStdString(title));
    descriptionLabel.setText(QString::fromStdString(description));


    titleLabel.setStyleSheet("QLabel{color: white;}");
    titleLabel.setAlignment(Qt::AlignLeft);
    descriptionLabel.setStyleSheet("QLabel{color: white;}");
    descriptionLabel.setAlignment(Qt::AlignLeft);
    
    setLayout(&gridLayout);
    int m = 10;
    gridLayout.setContentsMargins(m,m,m,m);
    gridLayout.addWidget(&numberLabel, 0, 0, 2, 1);
    gridLayout.addWidget(&titleLabel, 0, 1, Qt::AlignLeft);
    gridLayout.addWidget(&descriptionLabel, 1, 1, Qt::AlignLeft);

    gridLayout.setSpacing(m);
    gridLayout.setColumnStretch(1, 1);
    gridLayout.setRowStretch(0, 1);


    numberLabel.setStyleSheet(R"(
        QLabel{
            color: white;
            background-color: rgba( 255, 255, 255, 0% );
            margin-right: 5px;
            margin-left: 5px;
        }
    )");
    descriptionLabel.setStyleSheet(R"(
        QLabel{
            color: white;
            background-color: rgba( 255, 255, 255, 0% );
            font-size: 13px;
            margin-right: 5px;
            margin-left: 0px;
        }
    )");
    titleLabel.setStyleSheet(R"(
        QLabel{
            color: white;
            background-color: rgba( 255, 255, 255, 0% );
            margin-right: 5px;
        }
    )");
}

