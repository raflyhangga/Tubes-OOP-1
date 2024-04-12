#include "tubesoop1/gui/components/gridview.h"
#include "tubesoop1/icosihexastring/icosihexastring.h"
#include "tubesoop1/grid/location.h"
#include "tubesoop1/animal/animal.h"
#include "tubesoop1/plant/plant.h"
#include <sstream>
#include <QPushButton>

template <class T>
inline GridView<T>::GridView() : QWidget() {
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    vLayout.setSpacing(5);
    vLayout.setContentsMargins(0, 0, 0, 0);
    setLayout(&vLayout);

}

template <class T>
inline GridView<T>::~GridView(){
}

template <class T>
inline void GridView<T>::setGrid(Grid<T>* grid){
    this->grid = grid;
    refresh();
}

template <class T>
inline void GridView<T>::clear(){
    // remove errorLabel
    errorLabel.hide();
    if (errorLabel.parent() != nullptr) {
        vLayout.removeWidget(&errorLabel);
    }

    for (auto hLayout : hLayoutList) {
        qDeleteAll(hLayout->children()); // Delete children widgets
        delete hLayout; // Delete the layout itself
    }
    hLayoutList.clear();

    qDeleteAll(labelList); // Delete label widgets
    labelList.clear();

    qDeleteAll(buttonList); // Delete button widgets
    buttonList.clear();
}

template <class T>
inline void GridView<T>::refresh(){
    clear();

    int spacing = 5;
    // Top Label
    QHBoxLayout *hLayout = new QHBoxLayout(); hLayout->setSpacing(spacing); hLayout->setContentsMargins(0, 0, 0, 0);
    hLayoutList.push_back(hLayout);

    // Top left, just empty string
    string labelStr = "";
    LocationLabel *label = new LocationLabel(labelStr);
    labelList.push_back(label);
    hLayout->addWidget(label);
    // Top coordinates
    for (int j = 0; j < grid->getCol(); j++) {
        string labelStr = IcosiHexaString(j).getString();
        LocationLabel *label = new LocationLabel(labelStr);
        labelList.push_back(label);
        hLayout->addWidget(label);
    }
    vLayout.addLayout(hLayout);

    // Main grid
    for (int i = 0; i < grid->getRow(); i++) {
        
        // Left label
        QHBoxLayout *hLayout = new QHBoxLayout(); hLayout->setSpacing(spacing); hLayout->setContentsMargins(0, 0, 0, 0);
        string labelStr = to_string(i + 1);
        if(i + 1 < 10) labelStr = "0" + labelStr;
        LocationLabel *label = new LocationLabel(labelStr);
        labelList.push_back(label);
        hLayout->addWidget(label);

        // Actual grid
        for (int j = 0; j < grid->getCol(); j++) {
            QWidget *widget = getWidget(Location(i, j));
            buttonList.push_back(widget);
            hLayout->addWidget(widget);
        }
        vLayout.addLayout(hLayout);
        hLayoutList.push_back(hLayout);
    }
}


template <class T>
inline QWidget* GridView<T>::getWidget(Location location){
    string labelStr;
    try{
        T data = grid->getElement(location);
        ostringstream os;
        os << *data;
        labelStr = os.str();
    } catch (const exception& e) {
        labelStr = "";
    }
    NiceButton *button = new NiceButton(labelStr);
    button->setEnabled(false);
    return button;
}

template <>
inline QWidget* GridView<Animal*>::getWidget(Location location){
    string labelStr;
    NiceButton *button;
    try{
        Animal* data = grid->getElement(location);
        labelStr = data->getCode();
        button = new NiceButton(labelStr);
        button->setEnabled(false);
        if(data->isHarvestable()) {
            button->setStyleSuccess();
        }
        else {
            button->setStyleFailed();
        }
    } catch (const exception& e) {
        button = new NiceButton("");
        button->setEnabled(false);
    }
    return button;
}
template <>
inline QWidget* GridView<Plant*>::getWidget(Location location){
    string labelStr;
    NiceButton *button;
    try{
        Plant* data = grid->getElement(location);
        labelStr = data->getCode();
        button = new NiceButton(labelStr);
        button->setEnabled(false);
        if(data->isHarvestable()) {
            button->setStyleSuccess();
        }
        else {
            button->setStyleFailed();
        }
    } catch (const exception& e) {
        button = new NiceButton("");
        button->setEnabled(false);
    }
    return button;
}

template <class T>
void GridView<T>::showError(string message){
    clear();
    errorLabel.setText(QString::fromStdString(message));
    vLayout.addWidget(&errorLabel);
    errorLabel.show();
}

template <class T>
void GridView<T>::setEnabled(bool enabled){
    for (auto button : buttonList) {
        button->setEnabled(enabled);
    }
}

template <class T>
void GridView<T>::setCheckable(bool checkable){
    for (auto button : buttonList) {
        ((QPushButton*)button)->setCheckable(checkable);
    }
}
