#include "../header/Grasses.h"

Grasses::Grasses(int seed) : _rand_(seed){
    for(int i=0; i<10; i++){
        std::pair<int, int> pos(_rand_.getRandomNum(0, 20-1), _rand_.getRandomNum(0, 35-1));
        while(grasses.count(pos)){
            pos = std::make_pair(_rand_.getRandomNum(0, 20-1), _rand_.getRandomNum(0, 35-1));
        }

        grasses[pos] = Grass();
    }
}

bool Grasses::isGrass(std::pair<int, int> pos){
    return grasses.count(pos);
}

bool Grasses::pregnant(std::pair<int, int> pos){
    return grasses[pos].canHaveBaby();
}

bool Grasses::older(std::pair<int, int> pos){
    grasses[pos].increaseAge();
    return !(grasses[pos].isGonnaDie());
}

void Grasses::produce(std::pair<int, int> pos){
    grasses[pos] = Grass();
}

void Grasses::die(std::pair<int, int> pos){
    grasses.erase(pos);
}