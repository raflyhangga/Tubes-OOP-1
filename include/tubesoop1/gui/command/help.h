#ifndef HELP_H
#define HELP_H

#include <tubesoop1/gui/command/command.h>
#include <tubesoop1/player/player.h>
#include <QLabel>
#include <QMessageBox>

class Help: public Command {
    private:
        void dashedCout(string message);
        QMessageBox messageBox;
        string message;
    public:
        Help(MainWindow&);

        // visitor pattern
        void execute(Petani*);
        void execute(Peternak*);
        void execute(Walikota*);
};

#endif