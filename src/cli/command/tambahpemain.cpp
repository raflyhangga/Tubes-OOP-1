#include <tubesoop1/cli/command/tambahpemain.h>
#include <tubesoop1/cli/command/command_exception.h>

TambahPemain::TambahPemain(State &state) : Command(state) {}

void TambahPemain::execute(Petani *petani) {
    throw CommandNotAllowedException("TAMBAH_PEMAIN");
}
void TambahPemain::execute(Peternak *peternak) {
    throw CommandNotAllowedException("TAMBAH_PEMAIN");
}
void TambahPemain::execute(Walikota *walikota) {
    if(walikota->getMoney() < 50){
        cout << "Uang tidak cukup!" << endl << endl;
        return;
    }
    cout << "Masukkan jenis pemain: ";
    string type; cin >> type;
    if(!state.isAddedTypeValid(type)){
        cout << "Jenis pemain tidak valid!" << endl << endl;
        return;
    }

    cout << "Masukkan nama pemain: ";
    string name; cin >> name;
    if(state.isPlayerExist(name)){
        cout << "Nama pemain sudah pernah ada!" << endl << endl;
        return;
    }

    state.addPlayer(type, name);
    if(name<walikota->getUsername()){
        state.nextTurn();
    }
    walikota->addMoney(-50);
    cout << "\nPemain baru ditambahkan!";
    cout << "Selamat datang “" << name << "” di kota ini!" << endl << endl;
}

