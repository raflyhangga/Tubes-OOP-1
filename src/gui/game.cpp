#include "tubesoop1/gui/game.h"
#include "tubesoop1/gui/command/help.h"
#include "tubesoop1/gui/command/next.h"
#include "tubesoop1/gui/command/cetakpenyimpanan.h"
#include "tubesoop1/gui/command/cetakladang.h"
#include "tubesoop1/gui/command/cetakpeternakan.h"

Game::Game(State &gameState, MainWindow &gameWindow) : state(gameState), window(gameWindow) {
    CetakPenyimpanan c2(state, window); execute(&c2);
    CetakPeternakan c3(state, window); execute(&c3);
    CetakLadang c4(state, window); execute(&c4);

    window.nextButton.connect(&window.nextButton, &QPushButton::pressed, [this](){
        Next c(state, window); execute(&c);
        CetakPenyimpanan c2(state, window); execute(&c2);
        CetakPeternakan c3(state, window); execute(&c3);
        CetakLadang c4(state, window); execute(&c4);
    });
    window.helpButton.connect(&window.helpButton, &QPushButton::pressed, [this](){
        Help c(state, window); execute(&c);
    });
}

void Game::execute(Command* command) {
    command->execute(state.getCurrentPlayer());
}