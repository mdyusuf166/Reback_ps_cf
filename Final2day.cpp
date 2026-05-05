#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void word() {
    string s; cin >> s;
    int u = 0, l = 0;
    for(char c:s) isupper(c) ? u++ : l++;
    if(u > l) for(char &c:s) c = toupper(c);
    else for(char &c:s) c = tolower(c);
    cout << s;
}

void magnets() {
    int n; cin >> n;
    string s, last;
    int ans = 0;
    for(int i=0;i<n;i++) {
        cin >> s;
        if(i == 0 || s != last) ans++;
        last = s;
    }
    cout << ans;
}

void sereja_dima() {
    int n; cin >> n;
    vector<int>a(n);
    for(int &x:a) cin >> x;
    int l=0,r=n-1,s=0,d=0,turn=0;
    while(l<=r) {
        int x;
        if(a[l] > a[r]) x = a[l++];
        else x = a[r--];
        if(turn == 0) s += x;
        else d += x;
        turn ^= 1;
    }
    cout << s << " " << d;
}

void stones() {
    int n; string s;
    cin >> n >> s;
    int ans = 0;
    for(int i=1;i<n;i++) if(s[i] == s[i-1]) ans++;
    cout << ans;
}

void police() {
    int n; cin >> n;
    int p = 0, ans = 0;
    while(n--) {
        int x; cin >> x;
        if(x == -1) {
            if(p) p--;
            else ans++;
        } else p += x;
    }
    cout << ans;
}

void black_square() {
    int a[5];
    for(int i=1;i<=4;i++) cin >> a[i];
    string s; cin >> s;
    int ans = 0;
    for(char c:s) ans += a[c-'0'];
    cout << ans;
}

void museum() {
    string s; cin >> s;
    char cur = 'a';
    int ans = 0;
    for(char c:s) {
        int d = abs(c-cur);
        ans += min(d, 26-d);
        cur = c;
    }
    cout << ans;
}

void games() {
    int n; cin >> n;
    vector<int> h(n), a(n);
    for(int i=0;i<n;i++) cin >> h[i] >> a[i];
    int ans = 0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(i != j && h[i] == a[j]) ans++;
    cout << ans;
}

void shovel() {
    int k,r; cin >> k >> r;
    for(int i=1;;i++) {
        int x = i*k;
        if(x%10 == 0 || x%10 == r) {
            cout << i;
            return;
        }
    }
}

void horseshoe() {
    set<int>s;
    for(int i=0;i<4;i++) {
        int x; cin >> x;
        s.insert(x);
    }
    cout << 4 - s.size();
}

void magic_number() {
    string n; cin >> n;
    int ans = 0;
    while(n.size() > 1) {
        int sum = 0;
        for(char c:n) sum += c-'0';
        n = to_string(sum);
        ans++;
    }
    cout << ans;
}

void coins() {
    vector<string> v(3);
    for(auto &x:v) cin >> x;
    string s = "ABC";
    do {
        bool ok = true;
        for(string t:v) {
            int x = s.find(t[0]);
            int y = s.find(t[2]);
            if(t[1] == '<' && x > y) ok = false;
            if(t[1] == '>' && x < y) ok = false;
        }
        if(ok) {
            cout << s;
            return;
        }
    } while(next_permutation(s.begin(), s.end()));
    cout << "Impossible";
}

void effective_approach() {
    int n; cin >> n;
    vector<int> pos(n+1);
    for(int i=1;i<=n;i++) {
        int x; cin >> x;
        pos[x] = i;
    }
    int m; cin >> m;
    ll v = 0, p = 0;
    while(m--) {
        int x; cin >> x;
        v += pos[x];
        p += n - pos[x] + 1;
    }
    cout << v << " " << p;
}

void decoding() {
    int n; cin >> n;
    string s; cin >> s;
    string ans = "";
    for(int i=0;i<n;i++) {
        if((n-i)%2 == 0) ans = s[i] + ans;
        else ans += s[i];
    }
    cout << ans;
}

void lovely_palindrome() {
    string s; cin >> s;
    string r = s;
    reverse(r.begin(), r.end());
    cout << s << r;
}

void sort_array() {
    int n; cin >> n;
    vector<int>a(n), b;
    for(int &x:a) cin >> x;
    b = a;
    sort(b.begin(), b.end());
    int l = 0, r = n-1;
    while(l<n && a[l] == b[l]) l++;
    while(r>=0 && a[r] == b[r]) r--;
    if(l >= r) {
        cout << "yes\n1 1";
        return;
    }
    reverse(a.begin()+l, a.begin()+r+1);
    if(a == b) cout << "yes\n" << l+1 << " " << r+1;
    else cout << "no";
}

void triangle() {
    int n; cin >> n;
    vector<ll>a(n);
    for(ll &x:a) cin >> x;
    sort(a.begin(), a.end());
    for(int i=0;i+2<n;i++) {
        if(a[i] + a[i+1] > a[i+2]) {
            cout << "YES";
            return;
        }
    }
    cout << "NO";
}

void watchmen() {
    int n; cin >> n;
    map<ll,ll>x,y;
    map<pair<ll,ll>,ll> same;
    for(int i=0;i<n;i++) {
        ll a,b; cin >> a >> b;
        x[a]++; y[b]++;
        same[{a,b}]++;
    }
    ll ans = 0;
    for(auto p:x) ans += p.second*(p.second-1)/2;
    for(auto p:y) ans += p.second*(p.second-1)/2;
    for(auto p:same) ans -= p.second*(p.second-1)/2;
    cout << ans;
}

void theatre() {
    int n,m,t; cin >> n >> m >> t;
    ll C[35][35] = {};
    for(int i=0;i<=30;i++) {
        C[i][0] = C[i][i] = 1;
        for(int j=1;j<i;j++) C[i][j] = C[i-1][j-1] + C[i-1][j];
    }
    ll ans = 0;
    for(int boys=4;boys<=n;boys++) {
        int girls = t - boys;
        if(girls >= 1 && girls <= m) ans += C[n][boys] * C[m][girls];
    }
    cout << ans;
}

void kefa_park() {
    int n,m; cin >> n >> m;
    vector<int> cat(n+1);
    vector<vector<int>> g(n+1);
    for(int i=1;i<=n;i++) cin >> cat[i];
    for(int i=0;i<n-1;i++) {
        int u,v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans = 0;
    function<void(int,int,int)> dfs = [&](int u,int p,int cnt) {
        if(cat[u]) cnt++;
        else cnt = 0;
        if(cnt > m) return;
        bool leaf = true;
        for(int v:g[u]) {
            if(v != p) {
                leaf = false;
                dfs(v,u,cnt);
            }
        }
        if(leaf) ans++;
    };
    dfs(1,0,0);
    cout << ans;
}

void hamburgers() {
    string s; cin >> s;
    ll nb,ns,nc,pb,ps,pc,r;
    cin >> nb >> ns >> nc;
    cin >> pb >> ps >> pc;
    cin >> r;
    ll B=0,S=0,C=0;
    for(char c:s) {
        if(c=='B') B++;
        else if(c=='S') S++;
        else C++;
    }
    auto can = [&](ll x) {
        ll b = max(0LL, x*B-nb);
        ll ss = max(0LL, x*S-ns);
        ll c = max(0LL, x*C-nc);
        return b*pb + ss*ps + c*pc <= r;
    };
    ll l=0,h=1e13,ans=0;
    while(l<=h) {
        ll mid=(l+h)/2;
        if(can(mid)) ans=mid,l=mid+1;
        else h=mid-1;
    }
    cout << ans;
}

void classy_numbers() {
    int T; cin >> T;

    function<ll(string,int,int,int,vector<vector<vector<ll>>>&)> dfs =
    [&](string s,int pos,int cnt,int tight,vector<vector<vector<ll>>>& dp)->ll {
        if(cnt > 3) return 0;
        if(pos == (int)s.size()) return 1;
        ll &res = dp[pos][cnt][tight];
        if(res != -1) return res;
        res = 0;
        int lim = tight ? s[pos]-'0' : 9;
        for(int d=0;d<=lim;d++) {
            res += dfs(s,pos+1,cnt+(d!=0),tight && d==lim,dp);
        }
        return res;
    };

    auto calc = [&](ll x) {
        if(x <= 0) return 0LL;
        string s = to_string(x);
        vector<vector<vector<ll>>> dp(20, vector<vector<ll>>(4, vector<ll>(2,-1)));
        return dfs(s,0,0,1,dp);
    };

    while(T--) {
        ll l,r; cin >> l >> r;
        cout << calc(r) - calc(l-1) << '\n';
    }
}

void permutation_game() {
    int n; cin >> n;
    vector<int>a(n+1),pos(n+1),dp(n+1);
    for(int i=1;i<=n;i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    for(int val=n;val>=1;val--) {
        int i = pos[val];
        for(int j=i+val;j<=n;j+=val) {
            if(a[j] > val && dp[j] == 0) {
                dp[i] = 1;
                break;
            }
        }
        for(int j=i-val;j>=1 && !dp[i];j-=val) {
            if(a[j] > val && dp[j] == 0) {
                dp[i] = 1;
                break;
            }
        }
    }
    for(int i=1;i<=n;i++) cout << (dp[i] ? 'A' : 'B');
}

void binary_and_sum() {
    const ll MOD = 998244353;
    int n,m; cin >> n >> m;
    string a,b; cin >> a >> b;
    vector<int> pref(m+1);
    for(int i=0;i<m;i++) pref[i+1] = pref[i] + (b[i]=='1');
    reverse(a.begin(), a.end());
    ll ans = 0, pw = 1;
    for(int i=0;i<n;i++) {
        if(a[i] == '1') {
            int len = m - i;
            if(len > 0) ans = (ans + pw * pref[len]) % MOD;
        }
        pw = pw * 2 % MOD;
    }
    cout << ans;
}

void sea_battle() {
    int n,a,b,k; cin >> n >> a >> b >> k;
    string s; cin >> s;
    vector<int> shot;
    int cnt = 0;
    for(int i=0;i<n;i++) {
        if(s[i] == '0') {
            cnt++;
            if(cnt == b) {
                shot.push_back(i+1);
                cnt = 0;
            }
        } else cnt = 0;
    }
    int need = shot.size() - a + 1;
    cout << need << '\n';
    for(int i=0;i<need;i++) cout << shot[i] << " ";
}

void segments_removal() {
    struct Node {
        int len,id;
    };
    struct cmp {
        bool operator()(Node a, Node b) {
            if(a.len != b.len) return a.len < b.len;
            return a.id > b.id;
        }
    };

    int n; cin >> n;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];

    vector<int>L,R,val,pre,nxt;
    priority_queue<Node, vector<Node>, cmp> pq;

    int id = 0;
    for(int i=1;i<=n;) {
        int j = i;
        while(j<=n && a[j]==a[i]) j++;
        L.push_back(i);
        R.push_back(j-1);
        val.push_back(a[i]);
        pre.push_back(id-1);
        nxt.push_back(id+1);
        pq.push({j-i,id});
        id++;
        i = j;
    }

    if(id) nxt[id-1] = -1;

    vector<int> alive(id,1);
    int ans = 0;

    while(!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        int x = cur.id;
        if(!alive[x]) continue;
        if(cur.len != R[x]-L[x]+1) continue;

        ans++;
        alive[x] = 0;

        int l = pre[x], r = nxt[x];
        if(l != -1) nxt[l] = r;
        if(r != -1) pre[r] = l;

        if(l != -1 && r != -1 && alive[l] && alive[r] && val[l] == val[r]) {
            alive[r] = 0;
            R[l] = R[r];
            nxt[l] = nxt[r];
            if(nxt[r] != -1) pre[nxt[r]] = l;
            pq.push({R[l]-L[l]+1,l});
        }
    }

    cout << ans;
}

void greg_array() {
    int n,m,k; cin >> n >> m >> k;
    vector<ll>a(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];

    vector<int> l(m+1), r(m+1);
    vector<ll> d(m+1);

    for(int i=1;i<=m;i++) cin >> l[i] >> r[i] >> d[i];

    vector<ll> cnt(m+2);
    while(k--) {
        int x,y; cin >> x >> y;
        cnt[x]++;
        cnt[y+1]--;
    }

    for(int i=1;i<=m;i++) cnt[i] += cnt[i-1];

    vector<ll> add(n+2);

    for(int i=1;i<=m;i++) {
        ll val = cnt[i] * d[i];
        add[l[i]] += val;
        add[r[i]+1] -= val;
    }

    for(int i=1;i<=n;i++) {
        add[i] += add[i-1];
        cout << a[i] + add[i] << " ";
    }
}

void alice_bob_gcd() {
    int n; cin >> n;
    ll g = 0, mx = 0;
    for(int i=0;i<n;i++) {
        ll x; cin >> x;
        g = gcd(g,x);
        mx = max(mx,x);
    }
    ll move = mx/g - n;
    cout << (move%2 ? "Alice" : "Bob");
}

void almost_equal() {
    int n; cin >> n;
    if(n%2 == 0) {
        cout << "NO";
        return;
    }
    cout << "YES\n";
    vector<int> ans(2*n);
    for(int i=0;i<n;i++) {
        int x = 2*i+1;
        int y = 2*i+2;
        if(i%2 == 0) ans[i] = x, ans[i+n] = y;
        else ans[i] = y, ans[i+n] = x;
    }
    for(int x:ans) cout << x << " ";
}

void make_equal() {
    int n; ll k;
    cin >> n >> k;
    vector<int> cnt(200005);
    int mn = 200005, mx = 0;
    for(int i=0;i<n;i++) {
        int h; cin >> h;
        cnt[h]++;
        mn = min(mn,h);
        mx = max(mx,h);
    }
    ll cur = 0, towers = 0;
    int ans = 0;
    for(int h=mx;h>mn;h--) {
        towers += cnt[h];
        if(cur + towers > k) {
            ans++;
            cur = 0;
        }
        cur += towers;
    }
    if(cur) ans++;
    cout << ans;
}

void colorful_field() {
    ll n,m; int k,t;
    cin >> n >> m >> k >> t;
    vector<ll> waste(k);
    for(int i=0;i<k;i++) {
        ll a,b; cin >> a >> b;
        waste[i] = (a-1)*m + b;
    }
    sort(waste.begin(), waste.end());
    while(t--) {
        ll i,j; cin >> i >> j;
        ll pos = (i-1)*m + j;
        int before = lower_bound(waste.begin(), waste.end(), pos) - waste.begin();
        if(before < k && waste[before] == pos) cout << "Waste\n";
        else {
            ll id = pos - before;
            if(id%3 == 1) cout << "Carrots\n";
            else if(id%3 == 2) cout << "Kiwis\n";
            else cout << "Grapes\n";
        }
    }
}

void knight_tournament() {
    int n,m; cin >> n >> m;
    vector<int> par(n+2), ans(n+1);
    iota(par.begin(), par.end(), 0);

    function<int(int)> find = [&](int v) {
        return par[v] == v ? v : par[v] = find(par[v]);
    };

    while(m--) {
        int l,r,x; cin >> l >> r >> x;
        int cur = find(l);
        while(cur <= r) {
            if(cur == x) {
                cur = find(cur+1);
                continue;
            }
            ans[cur] = x;
            par[cur] = find(cur+1);
            cur = find(cur);
        }
    }

    for(int i=1;i<=n;i++) cout << ans[i] << " ";
}

void flowers() {
    int n; ll p;
    cin >> n >> p;
    vector<double> prob(n);
    for(int i=0;i<n;i++) {
        ll l,r; cin >> l >> r;
        ll total = r-l+1;
        ll divs = r/p - (l-1)/p;
        prob[i] = (double)divs / total;
    }
    double ans = 0;
    for(int i=0;i<n;i++) {
        int j = (i+1)%n;
        double good = 1.0 - (1.0-prob[i])*(1.0-prob[j]);
        ans += good * 2000.0;
    }
    cout << fixed << setprecision(10) << ans;
}

void balls_boxes() {
    int n,x; cin >> n >> x;
    x--;
    vector<ll>a(n);
    for(ll &v:a) cin >> v;

    int pos = x;
    ll mn = a[x];

    for(int i=(x-1+n)%n;i!=x;i=(i-1+n)%n) {
        if(a[i] < mn) {
            mn = a[i];
            pos = i;
        }
    }

    for(ll &v:a) v -= mn;
    ll taken = mn*n;

    int cur = (pos+1)%n;
    while(cur != (x+1)%n) {
        a[cur]--;
        taken++;
        cur = (cur+1)%n;
    }

    a[pos] = taken;
    for(ll v:a) cout << v << " ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    /*
    call only one function here.
    example:
    word();
    */

    word();

    return 0;
}