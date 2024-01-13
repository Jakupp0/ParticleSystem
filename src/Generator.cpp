#include "Generator.hpp"
#include <random>
Generator::Generator(double quantity) : quantity(quantity)
{}
Generator::Generator(const Generator& generator2){
    quantity = generator2.quantity;
}

Generator Generator::operator=(const Generator & generator2){
    this->quantity = generator2.quantity;
    return *this;
}
int Generator::generate() {
    if(generating)
    {
        int random_value = (std::rand()%20)*quantity;
        return random_value;
    }
    else
        return 0;
}
void Generator::startGenerating(){
    generating = true;
}
void Generator::stopGenerating(){
    generating = false;
}
void Generator::changequantity(double num){
    quantity = num;
}
