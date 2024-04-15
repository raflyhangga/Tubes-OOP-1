#include <tubesoop1/cli/command/beli.h>
#include <limits>

using namespace std;

Beli::Beli(State &state) : Command(state), shop(state.getShop()) {
    
}

int Beli::pageSize(vector<pair<Quantifiable<Resource*>,bool>> stock, int currentPos){
    return (stock.size() - currentPos * 5) >= 5? 5 : stock.size() - currentPos * 5;
}

void Beli::printStocks(vector<pair<Quantifiable<Resource*>,bool>> stock){
    if(stock.size() == 0){
        cout<<"============= SHOP =============\n";
        cout<<"\n!!!! STOCK KOSONG !!!!\n\n";
        throw(ItemShopEmptyException());
    } 
    else {
        int pages = (stock.size() + 4) / 5;
        int currentPos = 0;
        string choice;
        while (true){
            cout<<"============= SHOP =============\n";
            cout << "Selamat datang di toko!!" << endl;
            cout << "Berikut merupakan "<<stock.size()<<" item yang dapat Anda Beli" << endl;
            cout<<"-> Pages "<<currentPos+1<<" out of "<<pages<<"\n";
            for(int i=0; i<pageSize(stock,currentPos);i++){
                int dispIdx = i + (currentPos*5) + 1;
                Quantifiable<Resource*> rsc = stock[dispIdx - 1].first;
                string productName = rsc.getValue()->getName();
                int productPrice = rsc.getValue()->getPrice();
                int quantity = rsc.getQuantity();
                cout<<dispIdx<<". ";
                cout<<productName;
                cout<<" - ";
                cout<< productPrice;

                // Check if quantity is unlimited or not
                if(!Quantifiable<Resource*>::isInfinite(rsc)){
                    cout<< " ("<<quantity<<")\n";
                }
                else {
                    cout<<endl;
                }
            }

            cout<<"Beli apa hari ini? (PREV/BUY/NEXT)\n";
            cout<<"> ";
            while(!(cin >> choice)){
                cout << "Invalid input type, try again\n";
                cout<<"> ";
            }

            transform(choice.begin(),choice.end(),choice.begin(),::toupper);

            if(choice == "BUY"){
                break;
            }
            else if(choice == "NEXT"){
                currentPos = (currentPos + 1) % pages;
                cout<<endl;
                
            }
            else if(choice == "PREV"){
                currentPos = ((currentPos - 1) + pages) % pages;
                cout<<endl;
            }
            else{
                cout<< "Input tidak valid, silahkan ulangi!";
            }
        }
    }
}

void Beli::paymentProcessor(int idxItem, int quantity, Player* p){
    // Success payment message
    cout << "\nSelamat Anda berhasil membeli " 
    << quantity 
    << " " 
    << shop.getstock()[idxItem].getValue()->getName();
    cout << ". Uang Anda tersisa " 
    << p->getMoney() 
    << " gulden." 
    << endl;

    // Allocation item to inventory
    cout << "Pilih slot untuk menyimpan barang yang Anda beli!\n" << endl;
    CetakPenyimpanan(state).print(p->getInventory());
    cout << "Petak : ";

    // Input section for allocation
    string line;
    cin.ignore();
    getline(cin, line);
    try{
        vector<Location> ansLoc = inputListLocation(line);
        // Validation not balance with quantity
        // Pengurangan uang
        if(p->getMoney() - shop.getstock()[idxItem].getValue()->getPrice() * quantity < 0) {
            throw(UangTidakCukupShopException());
        } 
        else {
            p->setMoney(p->getMoney() - shop.getstock()[idxItem].getValue()->getPrice() * quantity);
        }
        if (ansLoc.size() != quantity)
        {
            throw logic_error("Jumlah petak tidak sesuai dengan kuantitas barang yang dibeli");
        }

        Resource *r = shop.getstock()[idxItem].getValue();
        string name = r->getName();
        for (Location l : ansLoc)
        {
            Resource *copy = state.translate(name);
            (*p).putInventoryAt(*copy, l);
        }

        cout << shop.getstock()[idxItem].getValue()->getName() << " berhasil disimpan dalam penyimpanan" << endl;

    } catch(exception& err){
        cout<<err.what()<<endl;
        state.cancelBuyShopItem(idxItem,quantity);
        p->setMoney(p->getMoney() + shop.getstock()[idxItem].getValue()->getPrice() * quantity);
        cout<<"Money has been returned succesfully!\n";
        throw(BuyingFromShopNotSuccesfullException());
    }

}

pair<int,int> Beli::welcomeMessage(vector<pair<Quantifiable<Resource*>,bool>> stock, Player * p){
    
    printStocks(stock);
    cout << "++++++++++++++++++++++++++++++++++\n";
    cout << "Uang Anda : " << p->getMoney() << endl;
    cout << "Slot penyimpanan tersedia : " << p->getInventory().getCountNotFilled() << endl;
    cout << "++++++++++++++++++++++++++++++++++\n";

    // Input Section
    int idxItem;
    int quantity;
    cout << "Barang ingin dibeli : ";
    while(!(cin >> idxItem)){
        cout<< "Error: enter a number\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Barang ingin dibeli : ";
    }
    cout << "Kuantitas : ";
    while(!(cin >> quantity)){
        cout<< "Error: enter a number";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Kuantitas : ";
    }

    pair<int,int> temp(idxItem,quantity);
    return temp;
}

void Beli::execute(Petani *p){
    vector<pair<Quantifiable<Resource*>,bool>> stock = shop.getStock(p);

    pair<int,int> choice = welcomeMessage(stock,p);
    int idxItem = choice.first - 1;
    int quantity = choice.second;

    shop.buy(p,idxItem,quantity);
    paymentProcessor(idxItem,quantity,p);
}

void Beli::execute(Peternak *p){
    vector<pair<Quantifiable<Resource*>,bool>> stock = shop.getStock(p);

    pair<int,int> choice = welcomeMessage(stock,p);
    int idxItem = choice.first - 1;
    int quantity = choice.second;

    shop.buy(p,idxItem,quantity);    
    paymentProcessor(idxItem,quantity,p);
}

void Beli::execute(Walikota *p){
    vector<pair<Quantifiable<Resource*>,bool>> stock = shop.getStock(p);

    pair<int,int> choice = welcomeMessage(stock,p);
    int idxItem = choice.first - 1;
    int quantity = choice.second;

    shop.buy(p,idxItem,quantity);
    paymentProcessor(idxItem,quantity,p);
    }