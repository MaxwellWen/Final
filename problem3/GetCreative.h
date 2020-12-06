#ifndef GETCREATIVE_H
#define GETCREATIVE_H
# include "FootwearItem.h"
#include <map>

class GetCreative: public FootwearItem{
public:
    GetCreative(std::string choice);
    std::string composeItem();
    double getPrice();
    void addAccessory(std::string accessory);
    virtual ~GetCreative ();
protected:
//    std::string name;
    std::map<std::string,int> Accessory;
};


#endif
