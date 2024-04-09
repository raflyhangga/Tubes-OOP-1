#include <tubesoop1/cli/command/next.h>
#include <tubesoop1/cli/command/cetakpenyimpanan.h>
#include <tubesoop1/cli/command/help.h>
#include <tubesoop1/cli/command/simpan.h>
#include <tubesoop1/cli/command/pungutpajak.h>

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

    if(promptYesNo("Apakah ingin memuat data state sebelumnya?")){
        state.load("config/state.txt", factory);
        cout << "Data state berhasil dimuat\n\n";
    } else {
        state.loadNew(factory);
        cout << "Membuat state baru...\n";
        cout << "Giliran " << state.getCurrentPlayer()->getUsername() << " yang bermain.\n\n";
    }
    
    initializeCommand();
}

void CLIGame::run() {
    string command;
    while (true) {
        cout << ">> ";
        cin >> command;
        try {
            transform(command.begin(), command.end(), command.begin(), ::toupper); // uppercase
            Command *c = commands.at(command);
            c->execute(state.getCurrentPlayer());
        } catch (out_of_range &e) {
            cout << "Perintah '" << command << "' tidak tersedia! Gunakan perintah 'HELP' untuk melihat daftar perintah." << endl;
        } catch (exception &e) {
            cout << e.what() << endl;
        }
    }
}


void CLIGame::initializeCommand() {
    commands["HELP"] = new Help(state);
    commands["NEXT"] = new Next(state);
    commands["CETAK_PENYIMPANAN"] = new CetakPenyimpanan(state);
    commands["PUNGUT_PAJAK"] = new PungutPajak(state);
    commands["SIMPAN"] = new Simpan(state);
}

bool CLIGame::promptYesNo(string message){
    cout << message << " (Y/n): ";
    string ans; cin >> ans;
    transform(ans.begin(), ans.end(), ans.begin(), ::tolower); // lowercase
    bool valid = false;
    while (!valid) {
        if (ans == "y" || ans == "n") valid = true;
        else {
            cout << "Masukkan tidak valid. Masukkan Y atau n: ";
            cin >> ans;
            transform(ans.begin(), ans.end(), ans.begin(), ::tolower); // lowercase
        }
    }
    return ans == "y";
}
