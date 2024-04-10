#include "tubesoop1/resource/resourcefactory.h"
#include "tubesoop1/resource/resourcefactory_exception.h"

ResourceFactory::ResourceFactory(string configPath){

    string plantPath = configPath + "/plant.txt";
    string animalPath = configPath + "/animal.txt";
    string productPath = configPath + "/product.txt";
    string recipePath = configPath + "/recipe.txt";
    string miscPath = configPath + "/misc.txt";

    string _;
    ifstream file;
    map<string, vector<Product*>> dropsMap;

         
    // ============= product =============
    // 1 TAW TEAK_WOOD PRODUCT_MATERIAL_PLANT TEAK_TREE 0 9
    // <ID> <KODE_HURUF> <NAME> <TYPE> <ORIGIN> <ADDED_WEIGHT> <PRICE>
    file.open(productPath); if(!file.is_open()) throw FileNotFoundException(productPath);
    for(int i = 0; i < 4; i++) {
        string kode, name, origin;
        int addedWeight, price;
        file >> _ >> kode >> name >> _ >> origin >> addedWeight >> price;
        insert({name, [=](){return new ProductMaterial(kode, name, addedWeight, price);}});
        dropsMap[origin].push_back(new ProductMaterial(kode, name, addedWeight, price));
    }
    for(int i = 0; i < 4; i++) {
        string kode, name, origin;
        int addedWeight, price;
        file >> _ >> kode >> name >> _ >> origin >> addedWeight >> price;
        insert({name, [=](){return new ProductFruit(kode, name, addedWeight, price);}});
        dropsMap[origin].push_back(new ProductFruit(kode, name, addedWeight, price));
    }
    for(int i = 0; i < 9; i++) {
        string kode, name, origin;
        int addedWeight, price;
        file >> _ >> kode >> name >> _ >> origin >> addedWeight >> price;
        insert({name, [=](){return new ProductAnimal(kode, name, addedWeight, price);}});
        dropsMap[origin].push_back(new ProductAnimal(kode, name, addedWeight, price));
    }
    file.close();

    // ============= plant =============
    // 1 TEK TEAK_TREE MATERIAL_PLANT 15 5
    file.open(plantPath); if(!file.is_open()) throw FileNotFoundException(plantPath);
    for(int i = 0; i < 4; i++) {
        string kode, name;
        int ageToHarvest, price;
        file >> _ >> kode >> name >> _ >> ageToHarvest >> price;
        vector<Product*> dropsMapValue = dropsMap[name];
        insert({name, [=](){return new Plant(kode, name, ageToHarvest, price, dropsMapValue);}});
    }
    for(int i = 0; i < 4; i++) {
        string kode, name;
        int ageToHarvest, price;
        file >> _ >> kode >> name >> _ >> ageToHarvest >> price;
        vector<Product*> dropsMapValue = dropsMap[name];
        insert({name, [=](){return new Plant(kode, name, ageToHarvest, price, dropsMapValue);}});
    }
    file.close();

    // ============= animal =============
    // 1 COW COW HERBIVORE 20 6
    file.open(animalPath); if(!file.is_open()) throw FileNotFoundException(animalPath);
    for(int i = 0; i < 4; i++) {
        string kode, name;
        int weightToHarvest, price;
        file >> _ >> kode >> name >> _ >> weightToHarvest >> price;
        vector<Product*> dropsMapValue = dropsMap[name];
        insert({name, [=](){return new Herbivore(kode, name, weightToHarvest, price, dropsMapValue);}});
    }
    for(int i = 0; i < 1; i++) {
        string kode, name;
        int weightToHarvest, price;
        file >> _ >> kode >> name >> _ >> weightToHarvest >> price;
        vector<Product*> dropsMapValue = dropsMap[name];
        insert({name, [=](){return new Carnivore(kode, name, weightToHarvest, price, dropsMapValue);}});
    }
    for(int i = 0; i < 2; i++) {
        string kode, name;
        int weightToHarvest, price;
        file >> _ >> kode >> name >> _ >> weightToHarvest >> price;
        vector<Product*> dropsMapValue = dropsMap[name];
        insert({name, [=](){return new Omnivore(kode, name, weightToHarvest, price, dropsMapValue);}});
    }
    file.close();

    // ============= recipe =============
    // 1 SMH SMALL_HOUSE 50 TEAK_WOOD 1 SANDAL_WOOD 1
    // <ID> <KODE_HURUF> <NAME> <PRICE> <MATERIAL_1> <MATERIAL_1_QUANTITY> <MATERIAL_2> <MATERIAL_2_QUANTITY> ... 
    file.open(recipePath); if(!file.is_open()) throw FileNotFoundException(recipePath);
    for(int i = 0; i < 4; i++) {
        string kode, name;
        int price;
        vector<Quantifiable<ProductMaterial*>> recipe;
        file >> _ >> kode >> name >> price; 

        string line;
        getline(file, line);
        istringstream iss(line);
        string material;
        int quantity;
        while(iss >> material >> quantity){
            ProductMaterial* p = (ProductMaterial*)(translate(material));
            Quantifiable<ProductMaterial*> qp = Quantifiable<ProductMaterial*>(p, quantity);
            recipe.push_back(qp);
        }
        insert({name, [=](){return new Building(kode, name, price, recipe);}});
        recipeMap[name] = new Building(kode, name, price, recipe);
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
    file >> Grid<Resource*>::defaultHeight >> Grid<Resource*>::defaultWidth;
    file >> Grid<Plant*>::defaultHeight >> Grid<Plant*>::defaultWidth;
    file >> Grid<Animal*>::defaultHeight >> Grid<Animal*>::defaultWidth;
    file.close();


}

Resource* ResourceFactory::translate(string key){
    Resource *r = this->at(key)();
    return r;
}


ostream& operator<<(ostream& os, const ResourceFactory& factory){
    int i = 0;
    for(auto it = factory.begin(); it != factory.end(); it++){
        string key = it->first;
        auto value = it->second();
        os << i++ << ". " << key << ": " << value->getCode() << endl;
    }
    return os;
}

ResourceFactory::~ResourceFactory() {
    for (auto& pair : *this) {
        // delete &pair.second;
    }
    for(auto& pair : dropsMap){
        for(auto& product : pair.second){
            delete product;
        }
    }
    for(auto& pair : recipeMap){
        delete pair.second;
    }
}

map<string, Building*>& ResourceFactory::getRecipeMap(){
    return recipeMap;
}