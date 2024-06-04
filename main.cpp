#include "wallet.h"

#include <iostream>
#include <vector>
using namespace std;

int main() {
    auto newWallet = wallet();
    char currencySymbol;
    cout << "To conjure your own currency, please provide the following incantations:\n";
    cout << "The symbol of your currency (e.g., $):\n";
    cin >> currencySymbol;
    newWallet.setCurrency(currencySymbol);

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
    float target;
    cout << "cash register opened width " << cashRegister << endl;
    cout << "Insert the mount that you want to retire: "; cin >> target;
    vector<float> approach = newWallet.apprValue(target);
    for (float number : approach) cout << number << ", ";
    cout << endl;
    return 0;
}
