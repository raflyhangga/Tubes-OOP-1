#include "tubesoop1/resource/resourcefactory.h"
#include "tubesoop1/resource/resourcefactory_exception.h"

ResourceFactory::ResourceFactory(string configPath){
    string plantPath = configPath + "/plant.txt";
    string animalPath = configPath + "/animal.txt";
    string productPath = configPath + "/product.txt";
    string recipePath = configPath + "/recipe.txt";
    string miscPath = configPath + "/misc.txt";
    
    void* _;
    ifstream file;
    // map<string, vector<Product*>> dropsMap;
         
    // ============= product =============
    // 1 TAW TEAK_WOOD PRODUCT_MATERIAL_PLANT TEAK_TREE 0 9
    // <ID> <KODE_HURUF> <NAME> <TYPE> <ORIGIN> <ADDED_WEIGHT> <PRICE>
    file.open(productPath); if(!file.is_open()) throw FileNotFoundException(productPath);
    for(int i = 0; i < 4; i++) {
        string kode, name, origin;
        int addedWeight, price;
        file >> _ >> kode >> name >> _ >> origin >> addedWeight >> price;
        // insert({name, [](){return ProductMaterial(kode, name, addedWeight, price);}});
        // dropsMap[origin].push_back(new ProductMaterial(kode, name, addedWeight, price));
    }
    for(int i = 0; i < 4; i++) {
        string kode, name;
        int addedWeight, price;
        file >> _ >> kode >> name >> _ >> _ >> addedWeight >> price;
        // insert({name, [](){return ProductFood(kode, name, addedWeight, price);}});
        // dropsMap[origin].push_back(new ProductFood(kode, name, addedWeight, price));
    }
    for(int i = 0; i < 4; i++) {
        string kode, name;
        int addedWeight, price;
        file >> _ >> kode >> name >> _ >> _ >> addedWeight >> price;
        // insert({name, [](){return ProductAnimal(kode, name, addedWeight, price);}});
        // dropsMap[origin].push_back(new ProductAnimal(kode, name, addedWeight, price));
    }
    file.close();

    // ============= plant =============
    // 1 TEK TEAK_TREE MATERIAL_PLANT 15 5
    file.open(plantPath); if(!file.is_open()) throw FileNotFoundException(plantPath);
    for(int i = 0; i < 4; i++) {
        string kode, name;
        int ageToHarvest, price;
        file >> _ >> kode >> name >> _ >> ageToHarvest >> price;
        // insert({name, [](){return MaterialPlant(kode, name, ageToHarvest, price, dropsMap[name]);}});
    }
    for(int i = 0; i < 4; i++) {
        string kode, name;
        int ageToHarvest, price;
        file >> _ >> kode >> name >> _ >> ageToHarvest >> price;
        // insert({name, [](){return FruitPlant(kode, name, ageToHarvest, price, dropsMap[name]);}});
    }
    file.close();

    // ============= animal =============
    // 1 COW COW HERBIVORE 20 6
    file.open(animalPath); if(!file.is_open()) throw FileNotFoundException(animalPath);
    for(int i = 0; i < 3; i++) {
        string kode, name;
        int weightToHarvest, price;
        file >> _ >> kode >> name >> _ >> weightToHarvest >> price;
        // insert({name, [](){return Herbivore(kode, name, ageToHarvest, price, dropsMap[name]);}});
    }
    for(int i = 0; i < 1; i++) {
        string kode, name;
        int weightToHarvest, price;
        file >> _ >> kode >> name >> _ >> weightToHarvest >> price;
        // insert({name, [](){return Carnivore(kode, name, ageToHarvest, price, dropsMap[name]);}});
    }
    for(int i = 0; i < 2; i++) {
        string kode, name;
        int weightToHarvest, price;
        file >> _ >> kode >> name >> _ >> weightToHarvest >> price;
        // insert({name, [](){return Omnivore(kode, name, ageToHarvest, price);}});
    }
    file.close();

    // ============= recipe =============
    // 1 SMH SMALL_HOUSE 50 TEAK_WOOD 1 SANDAL_WOOD 1
    // <ID> <KODE_HURUF> <NAME> <PRICE> <MATERIAL_1> <MATERIAL_1_QUANTITY> <MATERIAL_2> <MATERIAL_2_QUANTITY> ... 
    file.open(recipePath); if(!file.is_open()) throw FileNotFoundException(recipePath);
    for(int i = 0; i < 4; i++) {
        string kode, name;
        int price;
        vector<Quantifiable<Product>> recipe;
        file >> _ >> kode >> name >> price; 

        string line;
        while(getline(file, line)){
            if(line == "") break;
            istringstream iss(line);
            string material;
            int quantity;

            iss >> material >> quantity;
            Quantifiable<Product> qp = Quantifiable<Product>(dynamic_cast<Product&>(translate(material)), quantity);
            recipe.push_back(qp);
        }

        // insert({name, [](){return Building(kode, name, price, recipe);}});
    }
    file.close();

    
    // ============= misc =============
    // 1000 // Jumlah uang pemain untuk menang
    // 80 // Jumlah berat badan pemain untuk menang
    // 10 10 // Besaran penyimpanan
    // 5 7 // Besaran lahan
    // 8 9 // Besaran peternakan
    file.open(miscPath); if(!file.is_open()) throw FileNotFoundException(miscPath);
    file >> Player::moneyToWin >> Player::weightToWin;
    file >> Grid<Resource*>::defaultWidth >> Grid<Resource*>::defaultHeight;
    file >> Grid<Plant*>::defaultWidth >> Grid<Plant*>::defaultHeight;
    file >> Grid<Animal*>::defaultWidth >> Grid<Animal*>::defaultHeight;
    file.close();
    
}

Resource& ResourceFactory::translate(string key){
    Resource r = this->at(key)();
    return r;
}

