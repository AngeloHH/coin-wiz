#ifndef WALLET_H
#define WALLET_H

#include <map>
#include <vector>

using namespace std;


class wallet {
    char currency = '$';
    vector<float> money;

public:
    void insertCoin(float value, float mount);
    void setCurrency(char symbol);
    char getCurrency() const;
    map<float, float> getBalance();
    vector<float> apprValue(float target);
};



#endif //WALLET_H
