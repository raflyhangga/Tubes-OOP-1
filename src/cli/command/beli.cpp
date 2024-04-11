#include <tubesoop1/cli/command/beli.h>
#include <tubesoop1/cli/command/cetakpenyimpanan.h>
#include <tubesoop1/shop/Exception.h>

using namespace std;

Beli::Beli(State &state) : Command(state), shop(state.getShop()) {
    
}

void Beli::printStocks(vector<pair<Quantifiable<Resource*>,bool>> stock){
    int idx = 1;
    for(pair<Quantifiable<Resource*>,bool> pr: stock){
        Quantifiable<Resource*> rsc = pr.first;
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

bool Beli::isBuyable(pair<Quantifiable<Resource*>,bool> pair){
    return pair.second;
}

void Beli::playerBuy(Player* p, int idxItem,int quantity){
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

pair<int,int> Beli::welcomeMessage(vector<pair<Quantifiable<Resource*>,bool>> stock, Player * p){
    cout << "Selamat datang di toko!!" << endl;
    cout << "Berikut merupakan hal yang dapat Anda Beli" << endl;
    printStocks(stock);
    cout << "Uang Anda : " << p->getMoney() << endl;
    cout << "Slot penyimpanan tersedia : " << p->getInventory().getCountNotFilled() << endl;

    // Input Section
    int idxItem;
    int quantity;
    cout << "Barang ingin dibeli : ";
    cin >> idxItem;
    cout << "Kuantitas : ";
    cin >> quantity;

    pair<int,int> temp(idxItem,quantity);
    return temp;
}

void Beli::validityChecking(vector<pair<Quantifiable<Resource*>,bool>> stock, Player* p,int idxItem,int quantity){
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
}

void Beli::execute(Petani *p){
    vector<pair<Quantifiable<Resource*>,bool>> stock = shop.getPetaniStock();

    pair<int,int> choice = welcomeMessage(stock,p);
    int idxItem = choice.first - 1;
    int quantity = choice.second;

    if(!isBuyable(stock[idxItem])){
        throw(PetaniException());
    }
    validityChecking(stock,p,idxItem,quantity);
    playerBuy(p,idxItem,quantity);
}

void Beli::execute(Peternak *p){
    vector<pair<Quantifiable<Resource*>,bool>> stock = shop.getPeternakStock();

    pair<int,int> choice = welcomeMessage(stock,p);
    int idxItem = choice.first - 1;
    int quantity = choice.second;

    if(!isBuyable(stock[idxItem])){
        throw(PeternakException());
    }
    validityChecking(stock,p,idxItem,quantity);
    playerBuy(p,idxItem,quantity);
}

void Beli::execute(Walikota *p){
    vector<pair<Quantifiable<Resource*>,bool>> stock = shop.getWalikotaStock();

    pair<int,int> choice = welcomeMessage(stock,p);
    int idxItem = choice.first - 1;
    int quantity = choice.second;

    if(!isBuyable(stock[idxItem])){
        throw(WalikotaException());
    }
    validityChecking(stock,p,idxItem,quantity);
    playerBuy(p,idxItem,quantity);
}