#ifndef HELP_H
#define HELP_H

#include <tubesoop1/cli/command/command.h>
#include <tubesoop1/player/player.h>

class Help: public Command {
    private:
        ostream& dashedCout(string message);

    public:
        Help(State&);

        // visitor pattern
        void execute(Petani*);
        void execute(Peternak*);
        void execute(Walikota*);
};

#endif