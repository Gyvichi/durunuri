#include <bits/stdc++.h>
using namespace std;

vector<__int128> process_greedy(const vector<__int128>& coins, __int128 change) {
    vector<__int128> ret(coins.size(), 0);
    for (int i = 0; i < (int)coins.size(); i++) {
        if (coins[i] <= change) {
            __int128 count = change / coins[i];
            ret[i] = count;
            change -= count * coins[i];
        }
    }
    return ret;
}

int main() {
    int n;
    cin >> n;
    vector<__int128> coins(n);
    for (int i = n - 1; i >= 0; i--) {
        coins[i] = read128();
    }

    __int128 sum_min = numeric_limits<long long>::max();
    vector<__int128> optimums(n, 0);
    bool flag = true;

    for (int i = 1; i < n; i++) {
        __int128 initChange = coins[i - 1] - 1;
        if (initChange < 0) initChange = 0;
        vector<__int128> base = process_greedy(coins, initChange);
        for (int j = i; j < n; j++) {
            vector<__int128> m = base;
            m[j] += 1;
            for (int k = j + 1; k < n; k++) {
                m[k] = 0;
            }
            __int128 sum = 0;
            for (int idx = 0; idx < n; idx++) {
                sum += coins[idx] * m[idx];
            }
            if (sum >= sum_min) {
                continue;
            }
            vector<__int128> g_result = process_greedy(coins, sum);
            __int128 g_sum = 0;
            for (auto &val : g_result) {
                g_sum += val;
            }
            __int128 m_sum = 0;
            for (auto &val : m) {
                m_sum += val;
            }
            if (g_sum > m_sum) {
                flag = false;
                sum_min = sum;
                optimums = m;
            }
        }
    }

    if (flag) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
        for (int idx = n - 1; idx >= 0; idx--) {
            print128(optimums[idx]);
            cout << (idx > 0 ? ' ' : '\n');
        }
    }

    return 0;
}
