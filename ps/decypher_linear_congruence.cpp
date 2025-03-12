#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm> // Added for max_element
#include <numeric>   // Added for gcd if needed
using namespace std;

const int MAX = 1000000;
vector<bool> prime(MAX + 1, true);
vector<int> primes;

void sieve() {
    prime[0] = prime[1] = false;
    for (int n = 2; n * n <= MAX; ++n) {
        if (prime[n]) {
            for (int i = n * n; i <= MAX; i += n) {
                prime[i] = false;
            }
        }
    }
    for (int n = 2; n <= MAX; ++n) {
        if (prime[n]) {
            primes.push_back(n);
        }
    }
}

long long mod_pow(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    sieve();

    int t;
    cin >> t;

    for (int case_num = 1; case_num <= t; ++case_num) {
        int d, k;
        cin >> d >> k;

        vector<int> s(k);
        for (int i = 0; i < k; ++i) {
            cin >> s[i];
        }

        string u = "I don't know.";
        string ans;

        if (k == 1 || (k == 2 && s[0] != s[1])) {
            ans = u;
        } else if (s[k - 1] == s[k - 2]) {
            ans = to_string(s[k - 1]);
        } else {
            set<int> c;
            for (int p : primes) {
                if (p <= *max_element(s.begin(), s.end())) continue;
                if (p > pow(10, d)) break;

                int x = s[0], y = s[1], z = s[2];
                long long a = ((z - y) * mod_pow(y - x, p - 2, p)) % p;
                if (a < 0) a += p;
                long long b = (y - a * x) % p;
                if (b < 0) b += p;

                int w = s[0];
                bool valid = true;
                for (int i = 1; i < k; ++i) {
                    if ((a * w + b) % p != s[i]) {
                        valid = false;
                        break;
                    }
                    w = s[i];
                }

                if (valid) {
                    c.insert((a * s[k - 1] + b) % p);
                }
            }

            if (c.size() == 1) {
                ans = to_string(*c.begin());
            } else {
                ans = u;
            }
        }

        cout << "Case #" << case_num << ": " << ans << endl;
    }

    return 0;
}
