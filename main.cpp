#include <cmath>
#include <iostream>
#include <vector>

#include "wallet.h"
using namespace std;

int main() {
    auto newWallet = wallet();
    string currencyName, currencyPlural, tinnyCurrency;
    cout << "To conjure your own currency, please provide the following incantations:\n";
    cout << "The mystical name of your currency:\n";
    cin >> currencyName;
    cout << "The plural form of your currency (for when it multiplies):\n";
    cin >> currencyPlural;
    cout << "The smallest unit (the fraction that is less than one).\n";
    cin >> tinnyCurrency;
    newWallet.setCurrency(currencyName, currencyPlural, tinnyCurrency);

    cout << "Insert a coin and enter the amount below.\n";
    cout << "If the value is less than 0 or equal, you will stop adding coins\n";
    float cashRegister = 0;

    while (true) {
        float mount, value;
        cout << "Value: "; cin >> value;
        if (value <= 0) break;
        cout << "Amount: "; cin >> mount;

        newWallet.insertCoin(value, mount);
        cashRegister += value * mount;
    }

    const map<float, float> balance = newWallet.getBalance();
    cout << "cash register opened width " << cashRegister << endl;
    float test;
    cout << "Insert the mount that you want to retire: "; cin >> test;
    map<float, float> appr = newWallet.apprValue(test);
    for (const auto& par : appr) {
        std::cout << "Clave: " << par.first << ", Valor: " << par.second << std::endl;
    }
    return 0;
}
