#ifndef TERNAK_H
#define TERNAK_H
#include "tubesoop1/cli/command/command.h"
#include "tubesoop1/grid/location.h"
#include "tubesoop1/player/player.h"
#include "tubesoop1/cli/command/command_exception.h"
#include "tubesoop1/cli/command/cetakpenyimpanan.h"
#include "tubesoop1/cli/command/cetakpeternakan.h"
#include "tubesoop1/animal/animal.h"
using namespace std;

class Ternak : public Command {
    public:
        Ternak(State&);
        // visitor pattern
        void execute(Petani*);
        void execute(Peternak*);
        void execute(Walikota*);

};


#endif