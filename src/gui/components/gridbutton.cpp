#include "tubesoop1/gui/components/gridbutton.h"
#include "tubesoop1/icosihexastring/icosihexastring.h"

template <class T>
GridButton<T>::GridButton(Grid<T> &grid) : QWidget(), grid(grid) {
    int spacing = 5;

    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    vLayout = new QVBoxLayout();
    vLayout->setSpacing(spacing);
    vLayout->setContentsMargins(0, 0, 0, 0);
    setLayout(vLayout);

    // Top Label
    QHBoxLayout *hLayout = new QHBoxLayout(); hLayout->setSpacing(spacing); hLayout->setContentsMargins(0, 0, 0, 0);
    hLayoutList.push_back(hLayout);

    // Top left, just empty string
    string labelStr = "";
    LocationLabel *label = new LocationLabel(labelStr);
    labelList.push_back(label);
    hLayout->addWidget(label);
    
    for (int j = 0; j < grid.getCol(); j++) {
        string labelStr = IcosiHexaString(j).getString();
        LocationLabel *label = new LocationLabel(labelStr);
        labelList.push_back(label);
        hLayout->addWidget(label);
    }
    vLayout->addLayout(hLayout);

    for (int i = 0; i < grid.getRow(); i++) {
        
        // Left label
        QHBoxLayout *hLayout = new QHBoxLayout(); hLayout->setSpacing(spacing); hLayout->setContentsMargins(0, 0, 0, 0);
        string labelStr = to_string(i + 1);
        LocationLabel *label = new LocationLabel(labelStr);
        labelList.push_back(label);
        hLayout->addWidget(label);

        for (int j = 0; j < grid.getCol(); j++) {
            string labelStr = IcosiHexaString(j).getString() + to_string(i + 1);
            NiceButton *button = new NiceButton(labelStr);
            button->setEnabled(false);
            buttonList.push_back(button);
            hLayout->addWidget(button);
        }
        vLayout->addLayout(hLayout);
        hLayoutList.push_back(hLayout);
    }
}