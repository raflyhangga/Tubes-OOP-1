#include <tubesoop1/cli/command/help.h>

using namespace std;
Help::Help(State &state) : Command(state) {}

void Help::execute(Petani *petani) {
    cout << endl;
    cout << "Daftar Perintah Petani:" << endl;
    cout << "1.  NEXT" << endl;
    cout << "2.  CETAK_PENYIMPANAN" << endl;
 dashedCout("3.  PUNGUT_PAJAK") << endl;
    cout << "4.  CETAK_LADANG" << endl;
    cout << "5.  CETAK_PETERNAKAN" << endl;
    cout << "6.  TANAM" << endl;
 dashedCout("7.  TERNAK") << endl;
 dashedCout("8.  BANGUN") << endl;
    cout << "9.  MAKAN" << endl;
 dashedCout("10. KASIH_MAKAN") << endl;
    cout << "11. BELI" << endl;
    cout << "12. JUAL" << endl;
 dashedCout("13. PANEN") << endl;
   //  cout << "14. MUAT" << endl;
    cout << "14. SIMPAN" << endl;
 dashedCout("15. TAMBAH_PEMAIN") << endl;
    // di luar spek
    cout << "16. STATUS" << endl;
    cout << "17. HELP" << endl;
    cout << "18. KELUAR" << endl;
    cout << "Text yang diberi garis artinya tidak dapat dilakukan oleh role ini." << endl;
}
void Help::execute(Peternak *peternak) {
    cout << endl;
    cout << "Daftar Perintah Peternak:" << endl;
    cout << "1.  NEXT" << endl;
    cout << "2.  CETAK_PENYIMPANAN" << endl;
 dashedCout("3.  PUNGUT_PAJAK") << endl;
    cout << "4.  CETAK_LADANG" << endl;
    cout << "5.  CETAK_PETERNAKAN" << endl;
 dashedCout("6.  TANAM") << endl;
    cout << "7.  TERNAK" << endl;
 dashedCout("8.  BANGUN") << endl;
    cout << "9.  MAKAN" << endl;
    cout << "10. KASIH_MAKAN" << endl;
    cout << "11. BELI" << endl;
    cout << "12. JUAL" << endl;
 dashedCout("13. PANEN") << endl;
   //  cout << "14. MUAT" << endl;
    cout << "14. SIMPAN" << endl;
 dashedCout("15. TAMBAH_PEMAIN") << endl;
    // di luar spek
    cout << "16. STATUS" << endl;
    cout << "17. HELP" << endl;
    cout << "18. KELUAR" << endl;
    cout << "Text yang diberi garis artinya tidak dapat dilakukan oleh role ini." << endl;
}
void Help::execute(Walikota *walikota) {
    cout << endl;
    cout << "Daftar Perintah Walikota:" << endl;
    cout << "1.  NEXT" << endl;
    cout << "2.  CETAK_PENYIMPANAN" << endl;
    cout << "3.  PUNGUT_PAJAK" << endl;
 dashedCout("4.  CETAK_LADANG") << endl;
 dashedCout("5.  CETAK_PETERNAKAN") << endl;
 dashedCout("6.  TANAM") << endl;
 dashedCout("7.  TERNAK") << endl;
    cout << "8.  BANGUN" << endl;
    cout << "9.  MAKAN" << endl;
 dashedCout("10. KASIH_MAKAN") << endl;
    cout << "11. BELI" << endl;
    cout << "12. JUAL" << endl;
    cout << "13. PANEN" << endl;
   //  cout << "14. MUAT" << endl;
    cout << "14. SIMPAN" << endl;
    cout << "15. TAMBAH_PEMAIN" << endl;
    // di luar spek
    cout << "16. STATUS" << endl;
    cout << "17. HELP" << endl;
    cout << "18. KELUAR" << endl;
    cout << "Text yang diberi garis artinya tidak dapat dilakukan oleh role ini." << endl;
}


ostream& Help::dashedCout(string message){
    cout << "\033[9m" << message << "\033[0m";
    return cout;
}