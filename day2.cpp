#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/* ================== PROBLEM 1: Word ================== */
void solve_word() {
    string s; cin >> s;
    int up = 0, low = 0;
    for (char c : s) {
        if (isupper(c)) up++;
        else low++;
    }
    if (up > low) {
        for (char &c : s) c = toupper(c);
    } else {
        for (char &c : s) c = tolower(c);
    }
    cout << s << '\n';
}

/* ================== PROBLEM 2: Magnets ================== */
void solve_magnets() {
    int n; cin >> n;
    string s, prev;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (i == 0 || s != prev) ans++;
        prev = s;
    }
    cout << ans << '\n';
}

/* ================== PROBLEM 3: Police Recruits ================== */
void solve_police() {
    int n; cin >> n;
    int police = 0, ans = 0;
    while (n--) {
        int x; cin >> x;
        if (x == -1) {
            if (police > 0) police--;
            else ans++;
        } else police += x;
    }
    cout << ans << '\n';
}

/* ================== PROBLEM 4: Night at Museum ================== */
void solve_museum() {
    string s; cin >> s;
    char cur = 'a';
    int ans = 0;
    for (char c : s) {
        int d = abs(c - cur);
        ans += min(d, 26 - d);
        cur = c;
    }
    cout << ans << '\n';
}

/* ================== PROBLEM 5: Buy a Shovel ================== */
void solve_shovel() {
    int k, r; cin >> k >> r;
    for (int i = 1;; i++) {
        int x = i * k;
        if (x % 10 == 0 || x % 10 == r) {
            cout << i << '\n';
            return;
        }
    }
}

/* ================== PROBLEM 6: Little Elephant (GCD game) ================== */
void solve_alice_bob() {
    int n; cin >> n;
    ll g = 0, mx = 0;
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        g = __gcd(g, x);
        mx = max(mx, x);
    }
    ll moves = mx / g - n;
    cout << (moves % 2 ? "Alice\n" : "Bob\n");
}

/* ================== MAIN ================== */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Uncomment ONE function at a time depending on problem

    // solve_word();
    // solve_magnets();
    // solve_police();
    // solve_museum();
    // solve_shovel();
    // solve_alice_bob();

    return 0;
}