#include "tubesoop1/resource/resourcetranslator.h"
#include "tubesoop1/resource/resourcetranslator_error.h"

ResourceTranslator::ResourceTranslator(string configPath){
    string plantPath = configPath + "/plant.txt";
    string animalPath = configPath + "/animal.txt";
    string productPath = configPath + "/product.txt";
    string recipePath = configPath + "/recipe.txt";
    string miscPath = configPath + "/misc.txt";
    
    void* _;
    ifstream file;

    // ============= plant =============
    // 1 TEK TEAK_TREE MATERIAL_PLANT 15 5
    file.open(plantPath); if(!file.is_open()) throw FileNotFoundError(plantPath);
    
    // file >> _ >> TeakTree::kode >> TeakTree::name >> _ >> TeakTree::ageToHarvest >> TeakTree::price;
    // insert({TeakTree::name, [](){return TeakTree();}});
    
    // file >> _ >> SandalWoodTree::kode >> SandalWoodTree::name >> _ >> SandalWoodTree::ageToHarvest >> SandalWoodTree::price;
    // insert({SandalWoodTree::name, [](){return SandalWoodTree();}});

    // file >> _ >> AloeTree::kode >> AloeTree::name >> _ >> AloeTree::ageToHarvest >> AloeTree::price;
    // insert({AloeTree::name, [](){return AloeTree();}});

    // file >> _ >> IronWood::kode >> IronWood::name >> _ >> IronWood::ageToHarvest >> IronWood::price;
    // insert({IronWood::name, [](){return IronWood();}});

    // file >> _ >> AppleTree::kode >> AppleTree::name >> _ >> AppleTree::ageToHarvest >> AppleTree::price;
    // insert({AppleTree::name, [](){return AppleTree();}});

    // file >> _ >> OrangeTree::kode >> OrangeTree::name >> _ >> OrangeTree::ageToHarvest >> OrangeTree::price;
    // insert({OrangeTree::name, [](){return OrangeTree();}});

    // file >> _ >> BananaTree::kode >> BananaTree::name >> _ >> BananaTree::ageToHarvest >> BananaTree::price;
    // insert({BananaTree::name, [](){return BananaTree();}});

    // file >> _ >> GuavaTree::kode >> GuavaTree::name >> _ >> GuavaTree::ageToHarvest >> GuavaTree::price;
    // insert({GuavaTree::name, [](){return GuavaTree();}});

    file.close();

    // ============= animal =============
    // 1 COW COW HERBIVORE 20 6
    file.open(animalPath); if(!file.is_open()) throw FileNotFoundError(animalPath);
    
    // file >> _ >> Cow::kode >> Cow::name >> _ >> Cow::weightToHarvest >> Cow::price;
    // insert({Cow::name, [](){return Cow();}});
    
    // file >> _ >> Sheep::kode >> Sheep::name >> _ >> Sheep::weightToHarvest >> Sheep::price;
    // insert({Sheep::name, [](){return Sheep();}});
    
    // file >> _ >> Horse::kode >> Horse::name >> _ >> Horse::weightToHarvest >> Horse::price;
    // insert({Horse::name, [](){return Horse();}});
    
    // file >> _ >> Rabbit::kode >> Rabbit::name >> _ >> Rabbit::weightToHarvest >> Rabbit::price;
    // insert({Rabbit::name, [](){return Rabbit();}});
    
    // file >> _ >> Snake::kode >> Snake::name >> _ >> Snake::weightToHarvest >> Snake::price;
    // insert({Snake::name, [](){return Snake();}});
    
    // file >> _ >> Chicken::kode >> Chicken::name >> _ >> Chicken::weightToHarvest >> Chicken::price;
    // insert({Chicken::name, [](){return Chicken();}});
    
    // file >> _ >> Duck::kode >> Duck::name >> _ >> Duck::weightToHarvest >> Duck::price;
    // insert({Duck::name, [](){return Duck();}});

    file.close();

    // ============= recipe =============
    // 1 SMH SMALL_HOUSE 50 TEAK_WOOD 1 SANDAL_WOOD 1
    // <ID> <KODE_HURUF> <NAME> <PRICE> <MATERIAL_1> <MATERIAL_1_QUANTITY> <MATERIAL_2> <MATERIAL_2_QUANTITY> ... 
    file.open(recipePath); if(!file.is_open()) throw FileNotFoundError(recipePath);
    
    // file >> _ >> SmallHouse::kode >> SmallHouse::name >> SmallHouse::price >> SmallHouse::teakWoodRequirement >> SmallHouse::sandalWoodRequirement;
    // insert({SmallHouse::name, [](){return SmallHouse();}});
    
    // file >> _ >> MediumHouse::kode >> MediumHouse::name >> MediumHouse::price >> _ >> MediumHouse::aloeWoodRequirement >> _ >> MediumHouse::ironWoodRequirement;
    // insert({MediumHouse::name, [](){return MediumHouse();}});
    
    // file >> _ >> LargeHouse::kode >> LargeHouse::name >> LargeHouse::price >> _ >> LargeHouse::teakWoodRequirement >> _ >> LargeHouse::aloeWoodRequirement >> _ >> LargeHouse::ironWoodRequirement;
    // insert({LargeHouse::name, [](){return LargeHouse();}});
    
    // file >> _ >> Hotel::kode >> Hotel::name >> Hotel::price >> _ >> Hotel::teakWoodRequirement >> _ >> Hotel::aloeWoodRequirement >> _ >> Hotel::ironWoodRequirement >> _ >> Hotel::sandalWoodRequirement;
    // insert({Hotel::name, [](){return Hotel();}});
    
    file.close();
    
    // ============= product =============
    // 1 TAW TEAK_WOOD PRODUCT_MATERIAL_PLANT TEAK_TREE 0 9
    // <ID> <KODE_HURUF> <NAME> <TYPE> <ORIGIN> <ADDED_WEIGHT> <PRICE>
    file.open(productPath); if(!file.is_open()) throw FileNotFoundError(productPath);
    
    // file >> _ >> TeakWood::kode >> TeakWood::name >> _ >> _ >> TeakWood::addedWeight >> TeakWood::price;
    // insert({TeakWood::name, [](){return TeakWood();}});

    // file >> _ >> SandalWoodWood::kode >> SandalWoodWood::name >> _ >> _ >> SandalWoodWood::addedWeight >> SandalWoodWood::price;
    // insert({SandalWoodWood::name, [](){return SandalWoodWood();}});

    // file >> _ >> AloeWood::kode >> AloeWood::name >> _ >> _ >> AloeWood::addedWeight >> AloeWood::price;
    // insert({AloeWood::name, [](){return AloeWood();}});

    // file >> _ >> IronWoodWood::kode >> IronWoodWood::name >> _ >> _ >> IronWoodWood::addedWeight >> IronWoodWood::price;
    // insert({IronWoodWood::name, [](){return IronWoodWood();}});

    // file >> _ >> Apple::kode >> Apple::name >> _ >> _ >> Apple::addedWeight >> Apple::price;
    // insert({Apple::name, [](){return Apple();}});

    // file >> _ >> Orange::kode >> Orange::name >> _ >> _ >> Orange::addedWeight >> Orange::price;
    // insert({Orange::name, [](){return Orange();}});

    // file >> _ >> Banana::kode >> Banana::name >> _ >> _ >> Banana::addedWeight >> Banana::price;
    // insert({Banana::name, [](){return Banana();}});

    // file >> _ >> Guava::kode >> Guava::name >> _ >> _ >> Guava::addedWeight >> Guava::price;
    // insert({Guava::name, [](){return Guava();}});

    // file >> _ >> CowMeat::kode >> CowMeat::name >> _ >> _ >> CowMeat::addedWeight >> CowMeat::price;
    // insert({CowMeat::name, [](){return CowMeat();}});

    // file >> _ >> SheepMeat::kode >> SheepMeat::name >> _ >> _ >> SheepMeat::addedWeight >> SheepMeat::price;
    // insert({SheepMeat::name, [](){return SheepMeat();}});

    // file >> _ >> HorseMeat::kode >> HorseMeat::name >> _ >> _ >> HorseMeat::addedWeight >> HorseMeat::price;
    // insert({HorseMeat::name, [](){return HorseMeat();}});

    // file >> _ >> RabbitMeat::kode >> RabbitMeat::name >> _ >> _ >> RabbitMeat::addedWeight >> RabbitMeat::price;
    // insert({RabbitMeat::name, [](){return RabbitMeat();}});

    // file >> _ >> SnakeMeat::kode >> SnakeMeat::name >> _ >> _ >> SnakeMeat::addedWeight >> SnakeMeat::price;
    // insert({SnakeMeat::name, [](){return SnakeMeat();}});

    // file >> _ >> ChickenMeat::kode >> ChickenMeat::name >> _ >> _ >> ChickenMeat::addedWeight >> ChickenMeat::price;
    // insert({ChickenMeat::name, [](){return ChickenMeat();}});

    // file >> _ >> DuckMeat::kode >> DuckMeat::name >> _ >> _ >> DuckMeat::addedWeight >> DuckMeat::price;
    // insert({DuckMeat::name, [](){return DuckMeat();}});

    // file >> _ >> ChickenMeat::kode >> ChickenMeat::name >> _ >> _ >> ChickenMeat::addedWeight >> ChickenMeat::price;
    // insert({ChickenMeat::name, [](){return ChickenMeat();}});

    // file >> _ >> DuckMeat::kode >> DuckMeat::name >> _ >> _ >> DuckMeat::addedWeight >> DuckMeat::price;
    // insert({DuckMeat::name, [](){return DuckMeat();}});

    file.close();

    
    // ============= misc =============
    // 1000 // Jumlah uang pemain untuk menang
    // 80 // Jumlah berat badan pemain untuk menang
    // 10 10 // Besaran penyimpanan
    // 5 7 // Besaran lahan
    // 8 9 // Besaran peternakan
    file.open(miscPath); if(!file.is_open()) throw FileNotFoundError(miscPath);
    
    // file >> Player::moneyToWin >> Player::weightToWin;
    // file >> Inventory::width >> Inventory::height;
    // file >> Ladang::width >> Ladang::height;
    // file >> Peternakan::width >> Peternakan::height;

    file.close();
    
}

Resource& ResourceTranslator::translate(string key){
    Resource r = this->at(key)();
    return r;
}

