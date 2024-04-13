#ifndef TERNAK_H
#define TERNAK_H


#include <tubesoop1/player/player.h>
#include <tubesoop1/player/petani.h>
#include <tubesoop1/player/peternak.h>
#include <tubesoop1/player/walikota.h>
#include <tubesoop1/state/state.h>
#include <tubesoop1/gui/command/command.h>
#include <tubesoop1/gui/components/mainwindow.h>

#include "tubesoop1/grid/location.h"
#include "tubesoop1/player/player.h"
#include "tubesoop1/gui/command/cetakpenyimpanan.h"
#include "tubesoop1/gui/command/cetakpeternakan.h"
#include "tubesoop1/animal/animal.h"
using namespace std;

class Ternak : public Command {
    public:
        Ternak(State&, MainWindow&);
        // visitor pattern
        void execute(Petani*);
        void execute(Peternak*);
        void execute(Walikota*);

};


#endif