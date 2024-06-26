#ifndef HELP_H
#define HELP_H

#include <tubesoop1/gui/command/command.h>
#include <tubesoop1/player/player.h>
#include <QLabel>
#include <tubesoop1/gui/components/messagebox.h>

class Help: public Command {
    private:
        void dashedCout(string message);
        MessageBox messageBox;
        string message;
    public:
        Help(State&, MainWindow&);

        // visitor pattern
        void execute(Petani*);
        void execute(Peternak*);
        void execute(Walikota*);
};

#endif