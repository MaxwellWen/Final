#ifndef PREMADEDEAL_H
#define PREMADEDEAL_H
# include "FootwearItem.h"

class PreMadeDeal: public FootwearItem{
public:
//    PreMadeDeal(std::string name);
    PreMadeDeal(std::string name, std::string brand);
    std::string composeItem();
    double getPrice();
    virtual ~PreMadeDeal ();
protected:
    std::string name;
};



#endif
