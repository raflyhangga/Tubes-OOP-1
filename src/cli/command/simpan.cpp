#include <tubesoop1/cli/command/simpan.h>

Simpan::Simpan(State &state) : Command(state) {}

void Simpan::execute(Player *player) {
    cout << "Masukkan Masukkan lokasi berkas state : ";
    string ans; cin >> ans;

    try{
        state.save(ans);
        cout << "State berhasil disimpan" << endl;
    }  catch(FolderNotFoundException &e) {
        cout << "Lokasi berkas tidak valid" << endl;
    }
}


