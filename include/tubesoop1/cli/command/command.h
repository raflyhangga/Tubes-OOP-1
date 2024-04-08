#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <tubesoop1/player/player.h>
#include <tubesoop1/player/petani.h>
#include <tubesoop1/player/peternak.h>
#include <tubesoop1/player/walikota.h>
#include <tubesoop1/player/playervisitorpattern.h>
#include <tubesoop1/state/state.h>
using namespace std;

class Command : public CommanderVisitor { // visitor pattern
    protected:
        State& state;
    public:
        Command(State&);

        // visitor pattern
        virtual void execute(Player*);
        virtual void execute(Petani*);
        virtual void execute(Peternak*);
        virtual void execute(Walikota*);

};



#endif