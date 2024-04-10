#include <tubesoop1/cli/command/beli.h>
#include <tubesoop1/cli/command/cetakpenyimpanan.h>
#include <tubesoop1/shop/Exception.h>

using namespace std;

Beli::Beli(State &state) : Command(state) {}

void Beli::execute(Player *p)
{
    // Print information
    cout << "Selamat datang di toko!!" << endl;
    cout << "Berikut merupakan hal yang dapat Anda Beli" << endl;
    Shop shop = state.getShop();
    shop.getProducts();

    cout << "Uang Anda : " << p->getMoney() << endl;
    cout << "Slot penyimpanan tersedia : " << p->getInventory().getCountNotFilled() << endl;

    // Input section
    string wantToBuy;
    cin >> wantToBuy;

    int idxItem;
    int quantity;
    cout << "Barang ingin dibeli : ";
    cin >> idxItem;
    cout << "Kuantitas : ";
    cin >> quantity;

    // Validation section
    // input quantity 0 or negative
    if (quantity <= 0)
    {
        cout << "Kuantitas tidak valid" << endl;
        return;
    }

    // input index item 0 or negative
    if (idxItem < 1 || idxItem > shop.getstock().size())
    {
        cout << "Barang tidak ditemukan" << endl;
        return;
    }

    // input quantity more than stock
    if (quantity > shop.getstock()[idxItem - 1].getQuantity())
    {
        cout << "Kuantitas tidak mencukupi" << endl;
        return;
    }

    // player money less than price
    if (p->getMoney() < shop.getstock()[idxItem - 1].getValue()->getPrice() * quantity)
    {
        cout << "Uang tidak mencukupi" << endl;
        return;
    }

    //  inventory not enough
    if (p->getInventory().getCountNotFilled() < quantity)
    {
        cout << "Slot penyimpanan tidak mencukupi" << endl;
        return;
    }

    //  item cannot be bought
    if (shop.getstock()[idxItem - 1].getQuantity() == -1)
    {
        cout << "Barang tidak bisa dibeli" << endl;
        return;
    }

    // Buying Process
    try
    {
        shop.buy(idxItem);

        // Decrement money
        p->setMoney(p->getMoney() - shop.getstock()[idxItem - 1].getValue()->getPrice() * quantity);

        // Success payment message
        cout << "Selamat Anda berhasil membeli " << quantity << " " << shop.getstock()[idxItem - 1].getValue()->getName();
        cout << ". Uang Anda tersisa " << p->getMoney() << " gulden." << endl;

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
            Resource *r = shop.getstock()[idxItem - 1].getValue();
            (*p).putInventoryAt(*r, l);
        }

        cout << shop.getstock()[idxItem - 1].getValue()->getName() << " berhasil disimpan dalam penyimpanan" << endl;
    }
    catch (ItemShopNotFoundException &e)
    {
        cout << e.what() << endl;
    }
    catch (ItemShopEmptyException &e)
    {
        cout << e.what() << endl;
    }
}
