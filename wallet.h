#ifndef WALLET_H
#define WALLET_H

#include <map>
#include <string>
#include <tuple>

using namespace std;


class wallet {
    tuple<string, string, string> currency;
    map<float, float> money;

public:
    void insertCoin(float value, float mount);
    void setCurrency(const string& name, const string& plural, const string& tinyUnit);
    string getCurrency(float value);
    map<float, float> getBalance();
    map<float, float> apprValue(float target);
};



#endif //WALLET_H
