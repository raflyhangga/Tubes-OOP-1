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
#include "tubesoop1/gui/command/ternak.h"
#include "tubesoop1/gui/command/makan.h"
#include "tubesoop1/gui/command/kasihmakan.h"
#include "tubesoop1/gui/command/panen.h"
#include "tubesoop1/gui/command/simpan.h"
#include "tubesoop1/gui/command/beli.h"

Game::Game(State &gameState, MainWindow &gameWindow) : state(gameState), window(gameWindow) {
    refreshAllStatus();
    
    window.nextButton.connect(&window.nextButton, &QPushButton::clicked, [this](){
        Next c(state, window); execute(&c); refreshAllStatus();
    });
    window.helpButton.connect(&window.helpButton, &QPushButton::clicked, [this](){
        Help c(state, window); execute(&c); refreshAllStatus();
    });
    window.pungutPajakButton.connect(&window.pungutPajakButton, &QPushButton::clicked, [this](){
        PungutPajak c(state, window); execute(&c); refreshAllStatus();
    });
    window.bangunButton.connect(&window.bangunButton, &QPushButton::clicked, [this](){
        Bangun c(state, window); execute(&c); refreshAllStatus();
    });
    window.tambahPemainButton.connect(&window.tambahPemainButton, &QPushButton::clicked, [this](){
        TambahPemain c(state, window); execute(&c); refreshAllStatus();
    });
    window.tanamButton.connect(&window.tanamButton, &QPushButton::clicked, [this](){
        Tanam c(state, window); execute(&c); refreshAllStatus();
    });
    window.ternakButton.connect(&window.ternakButton, &QPushButton::clicked, [this](){
        Ternak c(state, window); execute(&c); refreshAllStatus();
    });
    window.makanButton.connect(&window.makanButton, &QPushButton::clicked, [this](){
        Makan c(state, window); execute(&c); refreshAllStatus();
    });
    window.kasihMakanButton.connect(&window.kasihMakanButton, &QPushButton::clicked, [this](){
        KasihMakan c(state, window); execute(&c); refreshAllStatus();
    });
    window.panenButton.connect(&window.panenButton, &QPushButton::clicked, [this](){
        Panen c(state, window); execute(&c); refreshAllStatus();
    });
    window.simpanButton.connect(&window.simpanButton, &QPushButton::clicked, [this](){
        Simpan c(state, window); execute(&c); refreshAllStatus();
    });
    window.beliButton.connect(&window.beliButton, &QPushButton::clicked, [this](){
        Beli c(state, window); execute(&c); refreshAllStatus();
    });

}

void Game::execute(Command* command) {
    command->execute(state.getCurrentPlayer());
}

void Game::refreshAllStatus() {
    window.getStatusBar().refresh();
    CetakPenyimpanan c2(state, window); execute(&c2);
    CetakPeternakan c3(state, window); execute(&c3);
    CetakLadang c4(state, window); execute(&c4);
}