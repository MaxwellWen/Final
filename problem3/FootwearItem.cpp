#include <string>
#include <iostream>

#include "FootwearItem.h"

using namespace std;

FootwearItem::FootwearItem(std::string brand){
    if(brand=="Adidas"){
        this->brand=brand;
        this->price=45.00;
    }
    else if(brand=="Nike"){
        this->brand="Nike";
        this->price=40.00;
    }
    else if(brand=="Fila"){
        this->brand="Fila";
        this->price=40.0;
    }
    else if(brand=="Skechers"){
        this->brand="Skechers";
        this->price=35.00;
    }
}
