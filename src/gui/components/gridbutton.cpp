#include "tubesoop1/gui/components/gridbutton.h"

template <class T>
GridButton<T>::GridButton(Grid<T> &grid) : QWidget() {
    this->grid = grid;

    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    vLayout = QVBoxLayout()
    v_layout.setSpacing(spacing)
    v_layout.setContentsMargins(0, 0, 0, 0)
    setLayout(v_layout)

    // set_width(self.matrix_width)
}