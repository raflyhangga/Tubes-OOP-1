#include <tubesoop1/cli/globals.hpp>
#include <tubesoop1/cli/command/next.hpp>
#include <tubesoop1/cli/command/cetakpenyimpanan.hpp>
#include <tubesoop1/player/petani.h>
#include <tubesoop1/player/peternak.h>
#include <tubesoop1/player/walikota.h>
#include <algorithm>

#include <iostream>
#include <tubesoop1/cli/game.hpp>
using namespace std;

void CLIGame::init() {
        cout <<
"                                     .a@@@@@a.     ,a@@@@@@@@a,     .a@@@@@a. \n"
"                              .@@@@@@@@@@@a,a@@@@@@@@@@@@@@a,a@@@@@@@@@@@. \n"
"                              @@@@@@@@@@@@a@@@@@@@@@@@@@@@@@@a@@@@@@@@@@@@ \n"
"                               @@@@'    `@a@@@@@@@@@@@@@@@@@@@@a@'   `@@@@ \n"
"                               `@'        @@@@@@@@@@@@@@@@@@@@@@       `@' \n"
"              .########################## @@@@@@@@@@\"@@@\"@@@@@@@@ \n"
"           .##############################`@@@@@@@@a@@@a@@@@@@@' \n"
"         .#####################;;#########,@@@@@@@@@@@@@@@@@@@@, \n"
"       ,;;;;;######;;;;#####;;;;;;;##;;;,@@@@@@@@@@@@@@@@@@@@@@@@, \n"
"     ,;;;;;;;;;;;;;;;;;;###;;;;;;;;;;;;;@@@@@( )@@@@@@@@@@( )@@@@@ \n"
"    ;;';;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;`@@@@@@@@@@@@@@@@@@@@@@@@' \n"
"   ;;';;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;`@@@@@@@@@@@@@@@@@@@@', \n"
"  ;;' ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; \"\"\"\"\"\"\"\"\"\"\"\"\",;;  ', \n"
" ;;'  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;    ', \n"
";;;;  ###;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;####;;;;;;;;;;;;;;      ; \n"
"`;;'  ####;;;##;;;;;;;;;;;;;;;;;;;;;;;;;;###########;;;;;;;;;;;    ,' \n"
"  `   ##########;;;;;;;'''''''''''''''''''''''''''###;;;;;;;;;;    ; \n"
"      #############;;'                            #;;;;;;;;;;;;     `, \n"
"      #############                               ;;;;;;;;;;;;;     () \n"
"      #############                               ;;;;;;;;;;;;; \n"
"      #oOOOOOOOOOo#                               ;oOOOOOOOOOo; \n"
"    oOOOOOOOOOOOOOOOo                           oOOOOOOOOOOOOOOOo \n"
"   OOOOOOOOOOOOOOOOOOO                         OOOOOOOOOOOOOOOOOOO \n"
"   OOOOOOO () OOOOOOOO                         OOOOOOOO () OOOOOOO \n"
"   `OOOOOOOooOOOOOOOO'                         `OOOOOOOOooOOOOOOO' \n"
"     `OOOOOOOOOOOOO'                             `OOOOOOOOOOOOO' \n"
"        \"\"\"\"\"\"\"\"\"\"                                   \"\"\"\"\"\"\"\"\"\" \n";

    cout << "[Welcome to TUBES-OOP-1]" << endl;
    
    cout << "Apakah ingin memuat data state sebelumnya? (Y/n) ";
    string ans; cin >> ans;
    if (ans == "Y") {
        cout << "Data state berhasil dimuat\n";
    } else {
        cout << "Membuat state baru...\n";
        initializeGame();
    }

    initializeCommand();
}

void CLIGame::run() {
    string command;
    while (true) {
        cout << "> ";
        cin >> command;
        try {
            Globals::commands[command]->execute(Globals::players[Globals::turn]);
        } catch (exception &e) {
            cout << e.what() << endl;
        }
    }
}


void CLIGame::initializeCommand() {
    Globals::commands["NEXT"] = new Next();
    Globals::commands["CETAK_PENYIMPANAN"] = new CetakPenyimpanan();
}

void CLIGame::initializeGame() {
    string name1 = "Petani1";
    Petani *petani1 = new Petani(name1);

    string name2 = "Peternak1";
    Peternak *peternak1 = new Peternak(name2);

    string name3 = "Walikota";
    Walikota *walikota = new Walikota(name3);

    Globals::players.push_back(walikota);
    Globals::players.push_back(petani1);
    Globals::players.push_back(peternak1);

    sort(Globals::players.begin(), Globals::players.end(), [](Player* a, Player* b) {
        return a->getUsername() < b->getUsername();
    });

    cout << "Giliran " << Globals::players[Globals::turn]->getUsername() << " yang bermain." << endl;
}
