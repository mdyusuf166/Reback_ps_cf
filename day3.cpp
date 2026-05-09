#include<bits/stdc++.h>
using namespace std;

// 1. A. Boy or Girl
void solveBoyOrGirl() {
    string s; cin >> s;
    set<char> st(s.begin(), s.end());
    cout << (st.size() % 2 == 0 ? "CHAT WITH HER!" : "IGNORE HIM!");
}

// 2. A. Word
void solveWord() {
    string s; cin >> s;
    int upper = 0, lower = 0;
    for(char c : s) {
        if(isupper(c)) upper++;
        else lower++;
    }
    for(char &c : s) {
        if(upper > lower) c = toupper(c);
        else c = tolower(c);
    }
    cout << s;
}

// 3. A. Magnets
void solveMagnets() {
    int n; cin >> n;
    string prev, cur;
    cin >> prev;
    int groups = 1;
    for(int i = 1; i < n; i++) {
        cin >> cur;
        if(cur != prev) groups++;
        prev = cur;
    }
    cout << groups;
}

// 4. A. Stones on the Table
void solveStonesOnTheTable() {
    int n; string s;
    cin >> n >> s;
    int ans = 0;
    for(int i = 1; i < n; i++) {
        if(s[i] == s[i - 1]) ans++;
    }
    cout << ans;
}

// 5. A. Police Recruits
void solvePoliceRecruits() {
    int n; cin >> n;
    int police = 0, untreated = 0;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        if(x == -1) {
            if(police > 0) police--;
            else untreated++;
        } else {
            police += x;
        }
    }
    cout << untreated;
}

// 6. A. Black Square
void solveBlackSquare() {
    int a[5];
    for(int i = 1; i <= 4; i++) cin >> a[i];
    string s; cin >> s;
    int sum = 0;
    for(char c : s) sum += a[c - '0'];
    cout << sum;
}

// 7. A. Night at the Museum
void solveNightAtTheMuseum() {
    string s; cin >> s;
    char cur = 'a';
    int ans = 0;
    for(char c : s) {
        int d = abs(c - cur);
        ans += min(d, 26 - d);
        cur = c;
    }
    cout << ans;
}

// 8. A. Free Ice Cream
void solveFreeIceCream() {
    int n; long long x;
    cin >> n >> x;
    int distressed = 0;
    while(n--) {
        char ch; long long d;
        cin >> ch >> d;
        if(ch == '+') x += d;
        else {
            if(x >= d) x -= d;
            else distressed++;
        }
    }
    cout << x << " " << distressed;
}

// 9. A. Helpful Maths
void solveHelpfulMaths() {
    string s; cin >> s;
    vector<char> v;
    for(char c : s) if(c != '+') v.push_back(c);
    sort(v.begin(), v.end());
    for(int i = 0; i < (int)v.size(); i++) {
        if(i) cout << "+";
        cout << v[i];
    }
}

// 10. A. Team Olympiad
void solveTeamOlympiad() {
    int n; cin >> n;
    vector<int> p, m, pe;
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        if(x == 1) p.push_back(i);
        else if(x == 2) m.push_back(i);
        else pe.push_back(i);
    }
    int teams = min({p.size(), m.size(), pe.size()});
    cout << teams << '\n';
    for(int i = 0; i < teams; i++) {
        cout << p[i] << " " << m[i] << " " << pe[i] << '\n';
    }
}

// 11. A. New Password
void solveNewPassword() {
    int n, k; cin >> n >> k;
    for(int i = 0; i < n; i++) cout << char('a' + i % k);
}

// 12. A. Presents
void solvePresents() {
    int n; cin >> n;
    vector<int> ans(n + 1);
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        ans[x] = i;
    }
    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
}

// 13. A. Lineland Mail
void solveLinelandMail() {
    int n; cin >> n;
    vector<long long> x(n);
    for(int i = 0; i < n; i++) cin >> x[i];
    for(int i = 0; i < n; i++) {
        long long mn, mx;
        if(i == 0) mn = x[1] - x[0];
        else if(i == n - 1) mn = x[n - 1] - x[n - 2];
        else mn = min(x[i] - x[i - 1], x[i + 1] - x[i]);
        mx = max(abs(x[i] - x[0]), abs(x[i] - x[n - 1]));
        cout << mn << " " << mx << '\n';
    }
}

// 14. A. Mahmoud and Longest Uncommon Subsequence
void solveLongestUncommonSubsequence() {
    string a, b; cin >> a >> b;
    if(a == b) cout << -1;
    else cout << max(a.size(), b.size());
}

// 15. B. Olympic Medal
void solveOlympicMedal() {
    int n, m, k;
    double A, B;
    cin >> n;
    double r1 = 0;
    for(int i = 0; i < n; i++) {
        double x; cin >> x;
        r1 = max(r1, x);
    }
    cin >> m;
    double p1 = 0;
    for(int i = 0; i < m; i++) {
        double y; cin >> y;
        p1 = max(p1, y);
    }
    cin >> k;
    double p2 = 1e18;
    for(int i = 0; i < k; i++) {
        double z; cin >> z;
        p2 = min(p2, z);
    }
    cin >> A >> B;
    double r2 = sqrt((B * p1 * r1 * r1) / (A * p2 + B * p1));
    cout << fixed << setprecision(12) << r2;
}

// 16. B. Filya and Homework
void solveFilyaAndHomework() {
    int n; cin >> n;
    set<long long> st;
    for(int i = 0; i < n; i++) {
        long long x; cin >> x;
        st.insert(x);
    }
    if(st.size() <= 2) cout << "YES";
    else if(st.size() == 3) {
        vector<long long> v(st.begin(), st.end());
        cout << (v[1] - v[0] == v[2] - v[1] ? "YES" : "NO");
    } else cout << "NO";
}

// 17. B. Inna and New Matrix of Candies
void solveInnaAndNewMatrixOfCandies() {
    int n, m; cin >> n >> m;
    set<int> dis;
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        int g = -1, candy = -1;
        for(int j = 0; j < m; j++) {
            if(s[j] == 'G') g = j;
            if(s[j] == 'S') candy = j;
        }
        if(g > candy) {
            cout << -1;
            return;
        }
        dis.insert(candy - g);
    }
    cout << dis.size();
}

// 18. B. Steps
void solveSteps() {
    long long n, m, x, y;
    cin >> n >> m >> x >> y;
    int k; cin >> k;
    long long ans = 0;
    while(k--) {
        long long dx, dy;
        cin >> dx >> dy;
        long long step = 4e18;
        if(dx > 0) step = min(step, (n - x) / dx);
        else if(dx < 0) step = min(step, (x - 1) / (-dx));
        if(dy > 0) step = min(step, (m - y) / dy);
        else if(dy < 0) step = min(step, (y - 1) / (-dy));
        x += step * dx;
        y += step * dy;
        ans += step;
    }
    cout << ans;
}

// 19. B. Growing Mushrooms
void solveGrowingMushrooms() {
    int n;
    double t1, t2, k;
    cin >> n >> t1 >> t2 >> k;
    vector<pair<double, int>> v;
    for(int i = 1; i <= n; i++) {
        double a, b; cin >> a >> b;
        double h1 = a * t1 * (100 - k) / 100.0 + b * t2;
        double h2 = b * t1 * (100 - k) / 100.0 + a * t2;
        v.push_back({-max(h1, h2), i});
    }
    sort(v.begin(), v.end());
    for(auto it : v) {
        cout << it.second << " " << fixed << setprecision(2) << -it.first << '\n';
    }
}

// 20. B. Escape
void solveEscape() {
    double vp, vd, t, f, c;
    cin >> vp >> vd >> t >> f >> c;
    if(vd <= vp) {
        cout << 0;
        return;
    }
    int ans = 0;
    double princess = vp * t;
    while(princess < c) {
        double catchTime = princess / (vd - vp);
        double catchPos = princess + vp * catchTime;
        if(catchPos >= c) break;
        ans++;
        double returnTime = catchPos / vd;
        princess = catchPos + vp * (returnTime + f);
    }
    cout << ans;
}

// 21. B. Roma and Changing Signs
void solveRomaAndChangingSigns() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n && k > 0; i++) {
        if(a[i] < 0) {
            a[i] = -a[i];
            k--;
        }
    }
    sort(a.begin(), a.end());
    if(k % 2) a[0] = -a[0];
    long long sum = 0;
    for(int x : a) sum += x;
    cout << sum;
}

// 22. B. Bear and Strings
void solveBearAndStrings() {
    string s; cin >> s;
    int n = s.size(), last = -1;
    long long ans = 0;
    for(int i = 0; i < n; i++) {
        if(i + 3 < n && s.substr(i, 4) == "bear") last = i;
        if(last != -1) ans += last + 1;
    }
    cout << ans;
}

// 23. B. I.O.U.
void solveIOU() {
    int n, m; cin >> n >> m;
    vector<int> balance(n + 1, 0);
    while(m--) {
        int a, b, c; cin >> a >> b >> c;
        balance[a] -= c;
        balance[b] += c;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) if(balance[i] > 0) ans += balance[i];
    cout << ans;
}

// 24. B. Jeff and Periods
void solveJeffAndPeriods() {
    int n; cin >> n;
    const int N = 100005;
    vector<int> last(N, -1), diff(N, 0);
    vector<bool> ok(N, true), found(N, false);
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        if(!found[x]) {
            found[x] = true;
            last[x] = i;
        } else {
            int d = i - last[x];
            if(diff[x] == 0) diff[x] = d;
            else if(diff[x] != d) ok[x] = false;
            last[x] = i;
        }
    }
    vector<pair<int,int>> ans;
    for(int x = 1; x < N; x++) {
        if(found[x] && ok[x]) ans.push_back({x, diff[x]});
    }
    cout << ans.size() << '\n';
    for(auto p : ans) cout << p.first << " " << p.second << '\n';
}

// 25. B. Meeting
void solveMeeting() {
    int xa, ya, xb, yb;
    cin >> xa >> ya >> xb >> yb;
    int x1 = min(xa, xb), x2 = max(xa, xb);
    int y1 = min(ya, yb), y2 = max(ya, yb);
    int n; cin >> n;
    vector<int> x(n), y(n), r(n);
    for(int i = 0; i < n; i++) cin >> x[i] >> y[i] >> r[i];
    int blankets = 0;
    for(int i = x1; i <= x2; i++) {
        for(int j = y1; j <= y2; j++) {
            if(i != x1 && i != x2 && j != y1 && j != y2) continue;
            bool warm = false;
            for(int h = 0; h < n; h++) {
                long long dx = i - x[h], dy = j - y[h];
                if(dx * dx + dy * dy <= 1LL * r[h] * r[h]) {
                    warm = true;
                    break;
                }
            }
            if(!warm) blankets++;
        }
    }
    cout << blankets;
}

// 26. B. Chocolate
void solveChocolate() {
    int n; cin >> n;
    vector<int> pos;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        if(x == 1) pos.push_back(i);
    }
    if(pos.empty()) {
        cout << 0;
        return;
    }
    long long ans = 1;
    for(int i = 1; i < (int)pos.size(); i++) ans *= pos[i] - pos[i - 1];
    cout << ans;
}

// 27. C. Magic Formulas
void solveMagicFormulas() {
    int n; cin >> n;
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        ans ^= x;
    }
    vector<int> xr(n + 1, 0);
    for(int i = 1; i <= n; i++) xr[i] = xr[i - 1] ^ i;
    for(int i = 1; i <= n; i++) {
        int full = n / i;
        int rem = n % i;
        if(full % 2) ans ^= xr[i - 1];
        ans ^= xr[rem];
    }
    cout << ans;
}

// 28. C. Pythagorean Triples
void solvePythagoreanTriples() {
    long long n; cin >> n;
    if(n == 1) cout << -1;
    else if(n % 2 == 0) {
        long long x = n / 2;
        cout << x * x - 1 << " " << x * x + 1;
    } else {
        cout << (n * n - 1) / 2 << " " << (n * n + 1) / 2;
    }
}

// 29. C. Gerald's Hexagon
void solveGeraldsHexagon() {
    long long a[6];
    for(int i = 0; i < 6; i++) cin >> a[i];
    long long x = a[0] + a[1] + a[2];
    cout << x * x - a[0] * a[0] - a[2] * a[2] - a[4] * a[4];
}

// 30. C. Points on Line
void solvePointsOnLine() {
    int n; long long d;
    cin >> n >> d;
    vector<long long> x(n);
    for(int i = 0; i < n; i++) cin >> x[i];
    long long ans = 0;
    int l = 0;
    for(int r = 0; r < n; r++) {
        while(x[r] - x[l] > d) l++;
        long long cnt = r - l;
        ans += cnt * (cnt - 1) / 2;
    }
    cout << ans;
}

// 31. C. Find Maximum
void solveFindMaximum() {
    int n; cin >> n;
    vector<long long> a(n), pref(n + 1, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        pref[i + 1] = pref[i] + a[i];
    }
    string s; cin >> s;
    long long ans = 0, higher = 0;
    for(int i = 0; i < n; i++) if(s[i] == '1') ans += a[i];
    for(int i = n - 1; i >= 0; i--) {
        if(s[i] == '1') {
            ans = max(ans, higher + pref[i]);
            higher += a[i];
        }
    }
    cout << ans;
}

// 32. B. Simple Game
void solveSimpleGame() {
    long long n, m;
    cin >> n >> m;
    if(m == 1) cout << 2;
    else if(m == n) cout << n - 1;
    else {
        long long left = m - 1;
        long long right = n - m;
        if(left >= right) cout << 1;
        else cout << n;
    }
}

// 33. C. Rational Resistance
void solveRationalResistance() {
    long long a, b;
    cin >> a >> b;
    long long ans = 0;
    while(a && b) {
        ans += a / b;
        a %= b;
        swap(a, b);
    }
    cout << ans;
}

// 34. C. Bulls and Cows
void solveBullsAndCows() {
    int n; cin >> n;
    vector<string> guess(n);
    vector<int> bull(n), cow(n);
    for(int i = 0; i < n; i++) cin >> guess[i] >> bull[i] >> cow[i];
    vector<string> possible;
    for(int num = 0; num <= 9999; num++) {
        string s = to_string(num);
        while(s.size() < 4) s = "0" + s;
        set<char> st(s.begin(), s.end());
        if(st.size() != 4) continue;
        bool ok = true;
        for(int i = 0; i < n; i++) {
            int b = 0, c = 0;
            for(int j = 0; j < 4; j++) {
                if(s[j] == guess[i][j]) b++;
                else if(s.find(guess[i][j]) != string::npos) c++;
            }
            if(b != bull[i] || c != cow[i]) {
                ok = false;
                break;
            }
        }
        if(ok) possible.push_back(s);
    }
    if(possible.empty()) cout << "Incorrect data";
    else if(possible.size() == 1) cout << possible[0];
    else cout << "Need more data";
}

// 35. C. Xor-tree
vector<int> xorTreeG[100005], xorInit, xorGoal, xorAns;
void xorTreeDfs(int node, int parent, int level, int flipEven, int flipOdd) {
    int cur = xorInit[node];
    if(level % 2 == 0) cur ^= flipEven;
    else cur ^= flipOdd;
    if(cur != xorGoal[node]) {
        xorAns.push_back(node);
        if(level % 2 == 0) flipEven ^= 1;
        else flipOdd ^= 1;
    }
    for(int child : xorTreeG[node]) {
        if(child != parent) xorTreeDfs(child, node, level + 1, flipEven, flipOdd);
    }
}
void solveXorTree() {
    int n; cin >> n;
    xorInit.assign(n + 1, 0);
    xorGoal.assign(n + 1, 0);
    xorAns.clear();
    for(int i = 1; i <= n; i++) xorTreeG[i].clear();
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        xorTreeG[u].push_back(v);
        xorTreeG[v].push_back(u);
    }
    for(int i = 1; i <= n; i++) cin >> xorInit[i];
    for(int i = 1; i <= n; i++) cin >> xorGoal[i];
    xorTreeDfs(1, 0, 0, 0, 0);
    cout << xorAns.size() << '\n';
    for(int x : xorAns) cout << x << '\n';
}

// 36. C. Median Smoothing
void solveMedianSmoothing() {
    int n; cin >> n;
    vector<int> a(n), ans, dist(n, -1);
    for(int i = 0; i < n; i++) cin >> a[i];
    ans = a;
    queue<int> q;
    for(int i = 0; i < n; i++) {
        if((i > 0 && a[i] == a[i - 1]) || (i + 1 < n && a[i] == a[i + 1])) {
            dist[i] = 0;
            q.push(i);
        }
    }
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int v : {u - 1, u + 1}) {
            if(v >= 0 && v < n && dist[v] == -1) {
                dist[v] = dist[u] + 1;
                ans[v] = ans[u];
                q.push(v);
            }
        }
    }
    for(int i = 0; i < n; i++) {
        if(dist[i] == -1) {
            cout << -1;
            return;
        }
    }
    int moves = 0;
    for(int x : dist) moves = max(moves, x);
    cout << moves << '\n';
    for(int x : ans) cout << x << " ";
}

// 37. C. Coloring Trees
void solveColoringTrees() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> c(n + 1);
    for(int i = 1; i <= n; i++) cin >> c[i];
    vector<vector<long long>> p(n + 1, vector<long long>(m + 1));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) cin >> p[i][j];
    }
    const long long INF = 4e18;
    vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(m + 1, vector<long long>(k + 1, INF)));
    for(int color = 1; color <= m; color++) {
        if(c[1] == 0 || c[1] == color) dp[1][color][1] = (c[1] == 0 ? p[1][color] : 0);
    }
    for(int i = 2; i <= n; i++) {
        for(int color = 1; color <= m; color++) {
            if(c[i] != 0 && c[i] != color) continue;
            long long cost = (c[i] == 0 ? p[i][color] : 0);
            for(int prev = 1; prev <= m; prev++) {
                for(int beauty = 1; beauty <= k; beauty++) {
                    if(dp[i - 1][prev][beauty] == INF) continue;
                    int nb = beauty + (color != prev);
                    if(nb <= k) dp[i][color][nb] = min(dp[i][color][nb], dp[i - 1][prev][beauty] + cost);
                }
            }
        }
    }
    long long ans = INF;
    for(int color = 1; color <= m; color++) ans = min(ans, dp[n][color][k]);
    cout << (ans == INF ? -1 : ans);
}

// 38. D. Quantity of Strings
const long long MOD = 1000000007;
int dsuParent[2005];
int findParent(int x) {
    if(dsuParent[x] == x) return x;
    return dsuParent[x] = findParent(dsuParent[x]);
}
void uniteDsu(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    if(a != b) dsuParent[a] = b;
}
long long modPower(long long a, long long b) {
    long long res = 1;
    while(b) {
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
void solveQuantityOfStrings() {
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) dsuParent[i] = i;
    for(int start = 1; start + k - 1 <= n; start++) {
        int l = start, r = start + k - 1;
        while(l < r) uniteDsu(l++, r--);
    }
    int components = 0;
    for(int i = 1; i <= n; i++) if(findParent(i) == i) components++;
    cout << modPower(m, components);
}

// 39. D. Eternal Victory
vector<pair<int,int>> victoryG[100005];
long long victoryFar = 0;
void victoryDfs(int u, int parent, long long dist) {
    victoryFar = max(victoryFar, dist);
    for(auto e : victoryG[u]) {
        int v = e.first, w = e.second;
        if(v != parent) victoryDfs(v, u, dist + w);
    }
}
void solveEternalVictory() {
    int n; cin >> n;
    long long sum = 0;
    for(int i = 1; i <= n; i++) victoryG[i].clear();
    for(int i = 0; i < n - 1; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        victoryG[x].push_back({y, w});
        victoryG[y].push_back({x, w});
        sum += w;
    }
    victoryFar = 0;
    victoryDfs(1, 0, 0);
    cout << 2 * sum - victoryFar;
}

// 40. D. Array Division
void solveArrayDivision() {
    int n; cin >> n;
    vector<long long> a(n);
    long long total = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        total += a[i];
    }
    multiset<long long> left, right;
    for(long long x : a) right.insert(x);
    long long pref = 0;
    for(int i = 0; i < n; i++) {
        pref += a[i];
        auto it = right.find(a[i]);
        if(it != right.end()) right.erase(it);
        left.insert(a[i]);
        long long other = total - pref;
        if(pref == other) {
            cout << "YES";
            return;
        }
        long long diff = llabs(pref - other);
        if(diff % 2 == 0) {
            long long need = diff / 2;
            if(pref > other && left.count(need)) {
                cout << "YES";
                return;
            }
            if(other > pref && right.count(need)) {
                cout << "YES";
                return;
            }
        }
    }
    cout << "NO";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Call only the function you need.
    // Example:
    // solveArrayDivision();

    return 0;
}
