#include <tubesoop1/cli/command/command_exception.h>

#include <tubesoop1/cli/command/next.h>
#include <tubesoop1/cli/command/cetakpenyimpanan.h>
#include <tubesoop1/cli/command/help.h>
#include <tubesoop1/cli/command/jual.h>
#include <tubesoop1/cli/command/simpan.h>
#include <tubesoop1/cli/command/tambahpemain.h>
#include <tubesoop1/cli/command/panen.h>
#include <tubesoop1/cli/command/pungutpajak.h>
#include <tubesoop1/cli/command/cetakladang.h>
#include <tubesoop1/cli/command/cetakpeternakan.h>
#include <tubesoop1/cli/command/ternak.h>
#include <tubesoop1/cli/command/makan.h>
#include <tubesoop1/cli/command/kasihmakan.h>

#include <tubesoop1/player/petani.h>
#include <tubesoop1/player/peternak.h>
#include <tubesoop1/player/walikota.h>
#include <tubesoop1/product/product.h>
#include <algorithm>
#include <vector>

#include <iostream>
#include <tubesoop1/cli/game.h>
using namespace std;

CLIGame::CLIGame() : factory("config") {

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
    
    if(promptYesNo("Apakah Anda ingin memuat state?")){
        bool loadSuccess = false;
        while(!loadSuccess){
            cout << "Masukkan lokasi berkas state : ";
            string path; cin >> path; 
            // path = "config/state.txt" // uncomment for quick testing
            try{
                state.load(path, factory);
                loadSuccess = true;
            } catch(FileNotFoundException &e){
                cout << "Berkas tidak ditemukan!" << endl;
            } catch(exception &e){
                cout << e.what() << endl;
            }
        }
        
        cout << "Data state berhasil dimuat\n\n";
    } else {
        state.loadNew(factory);
        cout << "Membuat state baru...\n";
    }
    
    initializeCommand();
    turnInfo();
}

void CLIGame::run() {

    string command;
    while (true) {
        cout << ">> ";
        cin >> command;
        try {
            transform(command.begin(), command.end(), command.begin(), ::toupper); // uppercase
            Command *c = choose(command);
            Player* player = state.getCurrentPlayer();
            c->execute(player);
            if(player->isWin()){
                win(player);
            }
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
    commands["CETAK_LADANG"] = new CetakLadang(state);
    commands["CETAK_PETERNAKAN"] = new CetakPeternakan(state);
    commands["SIMPAN"] = new Simpan(state);
    commands["JUAL"] = new Jual(state);
    commands["PANEN"] = new Panen(state);
    commands["TAMBAH_PEMAIN"] = new TambahPemain(state);
    commands["TERNAK"] = new Ternak(state);
    commands["MAKAN"] = new Makan(state);
    commands["KASIH_MAKAN"] = new KasihMakan(state);
}

Command* CLIGame::choose(string command) {
    try{
        return commands.at(command);
    }catch(out_of_range &e){
        throw CommandNotExistException(command);
    }
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

void CLIGame::turnInfo() {
    int numberOfPlayers = state.getTotalPlayer();
    for (int i = 0; i < numberOfPlayers; ++i) {
        Player *player = state.getPlayer(i);
        cout << i + 1 << ". " << player->getUsername();
        if (state.getTurn() == i) cout << " (giliranmu)";
        cout << endl;
    }
}

void CLIGame::win(Player* player){
    cout << "Selamat " << player->getUsername() << " kamu menang!" << endl;
    exit(0);
}