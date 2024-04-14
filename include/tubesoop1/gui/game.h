#ifndef GAME_H
#define GAME_H

#include "tubesoop1/gui/components/mainwindow.h"
#include "tubesoop1/state/state.h"
#include "tubesoop1/gui/command/command.h"
#include "tubesoop1/gui/command/help.h"
#include "tubesoop1/gui/command/next.h"

class Game{
    public:
        Game(State &state, MainWindow &window);
        State &state;
        MainWindow &window;
        void execute(Command* command);
        void refreshAllStatus();
};

#endif