#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "GetCreative.h"
#include "FootwearItem.h"
using namespace std;

GetCreative::GetCreative(std::string choice) : FootwearItem("test"){
//    cout<<"May I?";
    if(choice=="Adidas"){
        this->brand="Adidas";
        this->price=35.00;
    }
    else if(choice=="Nike"){
        this->brand="Nike";
        this->price=30.00;
    }
    else if(choice=="Fila"){
        this->brand="Fila";
        this->price=30.0;
    }
    else if(choice=="Skechers"){
        this->brand="Skechers";
        this->price=25.00;
    }
//    cout<<"GOOD_CREATIVE";
}
double GetCreative::getPrice() {
//    return 23;
    for(auto iter:this->Accessory){
        this->price+=(iter.second*5);
    }
    return this->price;
}

string GetCreative::composeItem(){
    string comp;
    comp+="GetCreative Brand: "+ this->brand+"\n";
    comp+="Accessories:\n";
    for(auto iter:this->Accessory){
        comp+=iter.first+": "+to_string(iter.second)+" quantity\n";
    }
    stringstream stream;
    stream << fixed << setprecision(2) << this->price;
    comp+="Price: $"+stream.str()+"\n";
    return comp;
//    return "Who I am?";
}
void GetCreative::addAccessory(std::string accessory){
    auto iter = this->Accessory.find(accessory);
    if(iter != this->Accessory.end())
        this->Accessory[accessory]+=1;
    else
        this->Accessory[accessory]=1;
//    cout<<"Add";
}
GetCreative::~GetCreative() {

}

