#include "wallet.h"

#include <limits>

void wallet::setCurrency(const string& name, const string& plural, const string& tinyUnit) {
    wallet::currency = make_tuple(name, plural, tinyUnit);
}

void wallet::insertCoin(const float value, float mount) {
    wallet::money.insert_or_assign(value, mount);
}

map<float, float> wallet::getBalance() {
    return wallet::money;
}

string wallet::getCurrency(float value) {
    if (value == 1) return get<0>(wallet::currency);
    if (value < 1) return get<2>(wallet::currency);
    return get<1>(wallet::currency);
}

map<float, float> wallet::apprValue(float target) {
    map<float, float> bestSubset;
    float bestDiff = numeric_limits<float>::max(); // Initialize with maximum difference

    for (const auto& [key, value] : money) {
        float currentDiff = std::abs(target - (key + value));
        if (currentDiff < bestDiff) {
            bestDiff = currentDiff;
            bestSubset = {{key, value}}; // Update with single element if closer
        }
    }

    // Iterate through subsets using bit manipulation for efficiency
    for (int i = 1; i < (1 << money.size()); ++i) {
        float subsetSum = 0.0;
        map<float, float> subset;
        for (int j = 0; j < money.size(); ++j) {
            if (i & (1 << j)) {
                subsetSum += money.at(next(money.begin(), j)->first); // Access element efficiently
                subset[next(money.begin(), j)->first] = money.at(next(money.begin(), j)->first);
            }
        }

        float currentDiff = abs(target - subsetSum);
        if (currentDiff > bestDiff) continue;
        bestDiff = currentDiff; bestSubset = subset;
    }

    return bestSubset;
}