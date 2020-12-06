#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "PreMadeDeal.h"
#include "FootwearItem.h"
using namespace std;

PreMadeDeal::PreMadeDeal(std::string name, std::string brand) : FootwearItem(brand){
    this->name=name;
}
double PreMadeDeal::getPrice() {
    return this->price;
}
string PreMadeDeal::composeItem(){
    string comp="";
    comp+="PremadeDeal Brand: ";
    comp+=this->brand + "\n";
    comp+="Name: "+this->name+"\n";
    stringstream stream;
    stream << fixed << setprecision(2) << this->price;
    comp+="Price: $"+stream.str()+"\n";
    return comp;
}
PreMadeDeal::~PreMadeDeal() {

}

