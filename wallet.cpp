#include "wallet.h"

#include <algorithm>
#include <iomanip>

void wallet::setCurrency(char currencySymbol) {
    wallet::currency = currencySymbol;
}

void wallet::insertCoin(const float value, float mount) {
    for (int x = 0; x < mount; ++x) money.push_back(value);
}

map<float, float> wallet::getBalance() {
    map<float, float> result;
    for (float i : money) result[i]++;
    return result;
}

char wallet::getCurrency() const {
    return wallet::currency;
}

vector<float> wallet::apprValue(float target) {
    size_t n = money.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(static_cast<int>(target) + 1, false));
    dp[0][0] = true;

    for (size_t i = 1; i <= n; ++i) {
        for (int j = 0; j <= target; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j >= money[i - 1] && dp[i - 1][j - static_cast<int>(money[i - 1])]) dp[i][j] = true;
        }
    }

    vector<float> solution; int j = static_cast<int>(target);
    for (size_t i = n; i > 0 && j > 0; --i) {
        if (dp[i][j] && !dp[i - 1][j]) {
            solution.push_back(money[i - 1]); j -= static_cast<int>(money[i - 1]);
        }
    }
    return solution;
}