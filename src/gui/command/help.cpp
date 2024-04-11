#include <tubesoop1/gui/command/help.h>

using namespace std;
Help::Help(State& State, MainWindow &window) : Command(state, window), messageBox(&window, "Help", "") {}

void Help::execute(Petani *petani) {
    message += "<html>";
    message +=  "Daftar Perintah Petani:<br>";
    message +=  "1.  NEXT<br>";
    message +=  "2.  CETAK_PENYIMPANAN<br>";
 dashedCout("3.  PUNGUT_PAJAK"); message += "<br>";
    message +=  "4.  CETAK_LADANG<br>";
    message +=  "5.  CETAK_PETERNAKAN<br>";
    message +=  "6.  TANAM<br>";
 dashedCout("7.  TERNAK"); message += "<br>";
 dashedCout("8.  BANGUN"); message += "<br>";
    message +=  "9.  MAKAN<br>";
 dashedCout("10. KASIH_MAKAN"); message += "<br>";
    message +=  "11. BELI<br>";
    message +=  "12. JUAL<br>";
 dashedCout("13. PANEN"); message += "<br>";
   //  message +=  "14. MUAT<br>";
    message +=  "14. SIMPAN<br>";
 dashedCout("15. TAMBAH_PEMAIN"); message += "<br>";
    // di luar spek
    message +=  "16. STATUS<br>";
    message +=  "17. HELP<br>";
    message +=  "18. KELUAR<br>";
    message +=  "Text yang diberi garis artinya tidak dapat dilakukan oleh role ini.<br>";
    message += "</html>";


    messageBox.setText(message);
    messageBox.exec();
}
void Help::execute(Peternak *peternak) {
    message += "<html>";
    message +=  "Daftar Perintah Peternak:<br>";
    message +=  "1.  NEXT<br>";
    message +=  "2.  CETAK_PENYIMPANAN<br>";
 dashedCout("3.  PUNGUT_PAJAK"); message += "<br>";
    message +=  "4.  CETAK_LADANG<br>";
    message +=  "5.  CETAK_PETERNAKAN<br>";
 dashedCout("6.  TANAM"); message += "<br>";
    message +=  "7.  TERNAK<br>";
 dashedCout("8.  BANGUN"); message += "<br>";
    message +=  "9.  MAKAN<br>";
    message +=  "10. KASIH_MAKAN<br>";
    message +=  "11. BELI<br>";
    message +=  "12. JUAL<br>";
 dashedCout("13. PANEN"); message += "<br>";
   //  message +=  "14. MUAT<br>";
    message +=  "14. SIMPAN<br>";
 dashedCout("15. TAMBAH_PEMAIN"); message += "<br>";
    // di luar spek
    message +=  "16. STATUS<br>";
    message +=  "17. HELP<br>";
    message +=  "18. KELUAR<br>";
    message +=  "Text yang diberi garis artinya tidak dapat dilakukan oleh role ini.<br>";

    message += "</html>";
    messageBox.setText(message);
    messageBox.exec();
}
void Help::execute(Walikota *walikota) {
    message += "<html>";
    message +=  "Daftar Perintah Walikota:<br>";
    message +=  "1.  NEXT<br>";
    message +=  "2.  CETAK_PENYIMPANAN<br>";
    message +=  "3.  PUNGUT_PAJAK<br>";
 dashedCout("4.  CETAK_LADANG"); message += "<br>";
 dashedCout("5.  CETAK_PETERNAKAN"); message += "<br>";
 dashedCout("6.  TANAM"); message += "<br>";
 dashedCout("7.  TERNAK"); message += "<br>";
    message +=  "8.  BANGUN<br>";
    message +=  "9.  MAKAN<br>";
 dashedCout("10. KASIH_MAKAN"); message += "<br>";
    message +=  "11. BELI<br>";
    message +=  "12. JUAL<br>";
    message +=  "13. PANEN<br>";
   //  message +=  "14. MUAT<br>";
    message +=  "14. SIMPAN<br>";
    message +=  "15. TAMBAH_PEMAIN<br>";
    // di luar spek
    message +=  "16. STATUS<br>";
    message +=  "17. HELP<br>";
    message +=  "18. KELUAR<br>";
    message +=  "Text yang diberi garis artinya tidak dapat dilakukan oleh role ini.<br>";
    message += "</html>";
    
    messageBox.setText(message);
    messageBox.exec();
}


void Help::dashedCout(string message){
    this->message +=  "<s>" + message + "</s>";
}