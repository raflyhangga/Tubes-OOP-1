#include <tubesoop1/cli/command/beli.h>
#include <tubesoop1/cli/command/cetakpenyimpanan.h>
#include <tubesoop1/shop/Exception.h>

using namespace std;

Beli::Beli(State &state) : Command(state) {
    shop = state.getShop();
}

void Beli::checkValidity(Player* pl,int idx){
}

void Beli::checkValidity(Petani* pl,int idx){
    Resource* itemBought = this->shop[idx].getValue();
    if(pl->isCanBuy(itemBought)){
        throw(PetaniException());
    }
}

void Beli::checkValidity(Peternak* pl,int idx){
    Resource* itemBought = this->shop[idx].getValue();
    if(pl->isCanBuy(itemBought)){
        throw(PeternakException());
    }
}
void Beli::checkValidity(Walikota* pl,int idx){
    Resource* itemBought = this->shop[idx].getValue();
    if(pl->isCanBuy(itemBought)){
        throw(WalikotaException());
    }
}

void Beli::printStocks(vector<Quantifiable<Resource*>> stock){
    int idx = 1;
    for(Quantifiable<Resource*> rsc: stock){
        string productName = rsc.getValue()->getName();
        int productPrice = rsc.getValue()->getPrice();
        int quantity = rsc.getQuantity();
        cout<<idx<<". ";
        cout<<productName;
        cout<<" - ";
        cout<< productPrice;
        // Check if quantity is unlimited or not
        if(quantity != -1){
            cout<< "("<<quantity<<")\n";
        }
        else {
            cout<<endl;
        }
        idx++;
    }
}

void Beli::execute(Player *p){
    // Print Information
    cout << "Selamat datang di toko!!" << endl;
    cout << "Berikut merupakan hal yang dapat Anda Beli" << endl;
    printStocks(shop.getstock());
    cout << "Uang Anda : " << p->getMoney() << endl;
    cout << "Slot penyimpanan tersedia : " << p->getInventory().getCountNotFilled() << endl;

    // Input Section
    int idxItem;
    int quantity;
    cout << "Barang ingin dibeli : ";
    cin >> idxItem;
    cout << "Kuantitas : ";
    cin >> quantity;

    idxItem--;
    // input index item 0 or negative
    if (idxItem < 1 || idxItem > shop.getstock().size())
    {
        throw (BeliOutOfRange());
    }
    // input quantity more than stock
    if (quantity > shop.getstock()[idxItem].getQuantity())
    {
        throw(BarangTidakCukup());
    }
        // player money less than price
    if (p->getMoney() < shop.getstock()[idxItem].getValue()->getPrice() * quantity)
    {
        throw(UangTidakCukup());
    }

    checkValidity(p,idxItem);

    shop.buy(idxItem);

    // Decrement money
    p->setMoney(p->getMoney() - shop.getstock()[idxItem].getValue()->getPrice() * quantity);

    // Success payment message
    cout << "Selamat Anda berhasil membeli " 
    << quantity 
    << " " 
    << shop.getstock()[idxItem].getValue()->getName();
    cout << ". Uang Anda tersisa " 
    << p->getMoney() 
    << " gulden." 
    << endl;

    // Allocation item to inventory
    cout << "Pilih slot untuk menyimpan barang yang Anda beli!" << endl;
    CetakPenyimpanan(state).print(p->getInventory());
    cout << "Petak : ";

    // Input section for allocation
    string line;
    cin.ignore();
    getline(cin, line);
    vector<Location> ansLoc = inputListLocation(line);

    // Validation not balance with quantity
    if (ansLoc.size() != quantity)
    {
        cout << "Jumlah petak tidak sesuai dengan kuantitas barang yang dibeli" << endl;
        return;
    }

    // Try to access inventory location
    for (Location l : ansLoc)
    {
        try
        {
            p->getInventory()[l];
        }
        catch (logic_error &e)
        {
            stringstream ss;
            ss << l;
            string message = "Petak " + ss.str() + " kosong, tidak bisa dijual.";
            throw logic_error(message);
        }
    }

    for (Location l : ansLoc)
    {
        Resource *r = shop.getstock()[idxItem].getValue();
        (*p).putInventoryAt(*r, l);
    }

    cout << shop.getstock()[idxItem].getValue()->getName() << " berhasil disimpan dalam penyimpanan" << endl;
}