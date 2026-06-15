#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int N = 1000000;

    vector<bool> isPrime(N + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= N; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= N; j += i) {
                isPrime[j] = false;
            }
        }
    }

    int n;
    cin >> n;

    while (n--) {
        int x;
        cin >> x;

        int root = sqrt(x);

        if (root * root == x && isPrime[root]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}