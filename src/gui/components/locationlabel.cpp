#include "tubesoop1/gui/components/locationlabel.h"

LocationLabel::LocationLabel(string &label) : QLabel() {
    setText(QString::fromStdString(label));
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    setAlignment(Qt::AlignCenter);
}