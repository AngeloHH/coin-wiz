#include "wallet.h"

#include <algorithm>
#include <iomanip>
using namespace std;

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
    vector<std::vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

    for (int i = 1; i <= n; i++) {
        dp[i][0] = true;
        for (int j = 1; j <= target; j++) {
            if (money[i - 1] > j) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = dp[i - 1][j] || dp[i - 1][j - money[i - 1]];
        }
    }

    vector<float> solution; int i = n, j = target;
    while (j > 0) {
        if (!dp[i][j]) continue;
        if (dp[i - 1][j]) i -= 1;
        else {
            solution.push_back(money[i - 1]);
            j -= money[i - 1]; i -= 1;
        }
    }

    return solution;
}