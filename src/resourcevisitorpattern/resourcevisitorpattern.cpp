#include "tubesoop1/resource/resource.h"
#include "tubesoop1/product/product.h"
#include "tubesoop1/animal/animal.h"
#include "tubesoop1/plant/plant.h"
#include "tubesoop1/building/building.h"
#include "tubesoop1/resourcevisitorpattern/resourcevisitorpattern.h"
#include "tubesoop1/resourcevisitorpattern/resourcevisitorpattern_exception.h"

void TakerVisitor::take(Animal* p) {
    throw NotTakableException(*p);    
}
void TakerVisitor::take(Product* p) {
    throw NotTakableException(*p);    
}
void TakerVisitor::take(ProductMaterial* p) {
    throw NotTakableException(*p);    
}
void TakerVisitor::take(ProductFruit* p) {
    throw NotTakableException(*p);    
}
void TakerVisitor::take(ProductAnimal* p) {
    throw NotTakableException(*p);    
}
void TakerVisitor::take(Plant* p) {
    throw NotTakableException(*p);    
}
void TakerVisitor::take(Building* b) {
    throw NotTakableException(*b);    
}