#include "building.h"
#include "bangunan_exception.h"

Building::Building(string name, ResepBangunan &resep, int quantity) : name(name), resep(resep), quantity(quantity) {}

void Building::printBuildingInfo()
{
  cout << name << " ";
  resep.printMaterialInfo();
  cout << endl;
}

// void Building::bangun(int uang) {
//     if (uang < resep.getPrice()) {
//         throw NotEnoughMoneyException();
//     }

//     if (quantity >= MAX_BUILDINGS) {
//         throw SlotNotAvailableException();
//     }

//     // Implementasi logika pembangunan bangunan sesuai dengan resep

//     cout << "Membangun bangunan " << name << "..." << endl;
//     // Jika pembangunan berhasil, kurangi uang dan tambahkan jumlah bangunan
//     uang -= resep.getPrice();
//     quantity++;
// }

void Building::tambahBangunan(int jumlah)
{
  quantity += jumlah;
  cout << "Jumlah bangunan " << name << " ditambahkan menjadi " << quantity << endl;
}

void Building::kurangiBangunan(int jumlah)
{
  if (quantity >= jumlah)
  {
    quantity -= jumlah;
    cout << "Jumlah bangunan " << name << " dikurangi menjadi " << quantity << endl;
  }
  else
  {
    cout << "Jumlah bangunan " << name << " tidak mencukupi untuk dikurangi." << endl;
  }
}
