#ifndef CLI_GAME_H
#define CLI_GAME_H
#include <tubesoop1/state/state.h>
#include <tubesoop1/cli/command/command.h>

class CLIGame {
    private: 
        void initializeCommand();
        State state;
        ResourceFactory factory;
        map<string, Command*> commands;
    public:
        CLIGame();
        void run();
        void init();
        bool promptYesNo(string message);
        void turnInfo();
        void win(Player* player);
        Command* choose(string command);
};

#endif