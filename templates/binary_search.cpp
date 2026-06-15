// Finds maximum x such that check(x) == true
// Pattern: true true true true false false false

long long l = 0;        // valid
long long r = INF;      // invalid

while (l + 1 < r) {
    long long mid = (l + r) / 2;

    if (check(mid)) {
        l = mid;        // mid is valid, try bigger
    } else {
        r = mid;        // mid is invalid, go smaller
    }
}

// answer = l
cout << l << '\n';