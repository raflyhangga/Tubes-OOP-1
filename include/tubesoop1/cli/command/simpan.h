#ifndef SIMPAN_H
#define SIMPAN_H

#include <tubesoop1/cli/command/command.h>
#include <tubesoop1/player/player.h>
#include <tubesoop1/resource/resourcefactory_exception.h>

class Simpan: public Command {
    public:
        Simpan(State&);

        // visitor pattern
        void execute(Player*);
};

#endif