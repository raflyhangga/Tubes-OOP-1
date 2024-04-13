#include "tubesoop1/gui/game.h"
#include "tubesoop1/gui/command/help.h"
#include "tubesoop1/gui/command/next.h"
#include "tubesoop1/gui/command/cetakpenyimpanan.h"
#include "tubesoop1/gui/command/cetakladang.h"
#include "tubesoop1/gui/command/cetakpeternakan.h"
#include "tubesoop1/gui/command/pungutpajak.h"
#include "tubesoop1/gui/command/bangun.h"
#include "tubesoop1/gui/command/tambahpemain.h"
#include "tubesoop1/gui/command/tanam.h"

Game::Game(State &gameState, MainWindow &gameWindow) : state(gameState), window(gameWindow) {
    CetakPenyimpanan c2(state, window); execute(&c2);
    CetakPeternakan c3(state, window); execute(&c3);
    CetakLadang c4(state, window); execute(&c4);

    window.nextButton.connect(&window.nextButton, &QPushButton::clicked, [this](){
        Next c(state, window); execute(&c);
        CetakPenyimpanan c2(state, window); execute(&c2);
        CetakPeternakan c3(state, window); execute(&c3);
        CetakLadang c4(state, window); execute(&c4);
    });
    window.helpButton.connect(&window.helpButton, &QPushButton::clicked, [this](){
        Help c(state, window); execute(&c);
    });
    window.pungutPajakButton.connect(&window.pungutPajakButton, &QPushButton::clicked, [this](){
        PungutPajak c(state, window); execute(&c);
    });
    window.bangunButton.connect(&window.bangunButton, &QPushButton::clicked, [this](){
        Bangun c(state, window); execute(&c);
    });
    window.tambahPemainButton.connect(&window.tambahPemainButton, &QPushButton::clicked, [this](){
        TambahPemain c(state, window); execute(&c);
    });
    window.tanamButton.connect(&window.tanamButton, &QPushButton::clicked, [this](){
        Tanam c(state, window); execute(&c);
    });

}

void Game::execute(Command* command) {
    command->execute(state.getCurrentPlayer());
}