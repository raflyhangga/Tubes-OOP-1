#ifndef STATUS_BAR_H
#define STATUS_BAR_H

#include <string>
#include <QPushButton>
#include <QSizePolicy>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include "tubesoop1/gui/components/nicebutton.h"
#include "tubesoop1/player/player.h"
using namespace std;

class StatusBar : public QWidget {
private:
    Player* player;

    QVBoxLayout vLayout;
    QHBoxLayout hLayout1;
    QHBoxLayout hLayout2;

    QWidget widget1;
    QWidget widget2;

    QLabel usernameLabel;
    QLabel typeLabel;
    QLabel moneyLabel;
    QLabel weightLabel;
    const char* getClassName(Player &player);
public:
    StatusBar();
    /**
     * Change the player that this status bar is displaying
    */
    void setPlayer(Player*);

    /**
     * Refresh the status bar to display the latest player information
    */
    void refresh();
};


#endif