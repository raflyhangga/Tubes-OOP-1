#include <tubesoop1/cli/command/next.h>
#include <tubesoop1/cli/command/cetakpenyimpanan.h>
#include <tubesoop1/player/petani.h>
#include <tubesoop1/player/peternak.h>
#include <tubesoop1/player/walikota.h>
#include <algorithm>

#include <iostream>
#include <tubesoop1/cli/game.h>
using namespace std;

CLIGame::CLIGame(){

}

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
    
    factory = ResourceFactory("config");
    
    cout << "Apakah ingin memuat data state sebelumnya? (Y/n) ";
    string ans; cin >> ans;
    transform(ans.begin(), ans.end(), ans.begin(), ::tolower); // lowercase
    if (ans == "y") {
        state.load("config/state.txt", factory);
        cout << "Data state berhasil dimuat\n";
    } else {
        state.loadNew(factory);
        cout << "Membuat state baru...\n";
        cout << "Giliran " << state.getCurrentPlayer()->getUsername() << " yang bermain." << endl;
    }

    initializeCommand();
}

void CLIGame::run() {
    string command;
    while (true) {
        cout << "> ";
        cin >> command;
        try {
            commands[command]->execute(state.getCurrentPlayer());
        } catch (exception &e) {
            cout << e.what() << endl;
        }
    }
}


void CLIGame::initializeCommand() {
    commands["NEXT"] = new Next(state);
    commands["CETAK_PENYIMPANAN"] = new CetakPenyimpanan(state);
}