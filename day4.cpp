#include <bits/stdc++.h>
using namespace std;

/*---------------------------------------------------
  1. Good Number
---------------------------------------------------*/
void goodNumber()
{
    int n, k;
    cin >> n >> k;

    int ans = 0;

    while(n--)
    {
        string s;
        cin >> s;

        vector<int> f(10, 0);

        for(char c : s)
            f[c - '0'] = 1;

        bool ok = true;

        for(int i = 0; i <= k; i++)
        {
            if(!f[i])
                ok = false;
        }

        if(ok) ans++;
    }

    cout << ans << endl;
}

/*---------------------------------------------------
  2. Dice Tower
---------------------------------------------------*/
void diceTower()
{
    int n, x;
    cin >> n >> x;

    int op = 7 - x;

    bool ok = true;

    while(n--)
    {
        int a, b;
        cin >> a >> b;

        if(a == x || b == x || a == op || b == op)
            ok = false;
    }

    cout << (ok ? "YES" : "NO") << endl;
}

/*---------------------------------------------------
  3. Alyona and Numbers
---------------------------------------------------*/
void alyonaNumbers()
{
    long long n, m;
    cin >> n >> m;

    long long a[5] = {0}, b[5] = {0};

    for(long long i = 1; i <= n; i++)
        a[i % 5]++;

    for(long long i = 1; i <= m; i++)
        b[i % 5]++;

    long long ans = 0;

    for(int i = 0; i < 5; i++)
    {
        ans += a[i] * b[(5 - i) % 5];
    }

    cout << ans << endl;
}

/*---------------------------------------------------
  4. Mountain Scenery
---------------------------------------------------*/
void mountainScenery()
{
    int n, k;
    cin >> n >> k;

    vector<int> r(2 * n + 1);

    for(int i = 0; i < 2 * n + 1; i++)
        cin >> r[i];

    for(int i = 1; i < 2 * n && k > 0; i += 2)
    {
        if(r[i] - 1 > r[i - 1] && r[i] - 1 > r[i + 1])
        {
            r[i]--;
            k--;
        }
    }

    for(int x : r)
        cout << x << " ";
}

/*---------------------------------------------------
  5. Help Vasilisa the Wise 2
---------------------------------------------------*/
void vasilisa()
{
    int r1,r2,c1,c2,d1,d2;
    cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;

    for(int a=1;a<=9;a++)
    {
        for(int b=1;b<=9;b++)
        {
            for(int c=1;c<=9;c++)
            {
                for(int d=1;d<=9;d++)
                {
                    set<int> s = {a,b,c,d};

                    if(s.size()!=4) continue;

                    if(a+b==r1 &&
                       c+d==r2 &&
                       a+c==c1 &&
                       b+d==c2 &&
                       a+d==d1 &&
                       b+c==d2)
                    {
                        cout << a << " " << b << endl;
                        cout << c << " " << d << endl;
                        return;
                    }
                }
            }
        }
    }

    cout << -1 << endl;
}

/*---------------------------------------------------
  6. Chewbacca and Number
---------------------------------------------------*/
void chewbacca()
{
    string s;
    cin >> s;

    for(int i = 0; i < s.size(); i++)
    {
        int d = s[i] - '0';

        if(i == 0 && d == 9)
            continue;

        if(d >= 5)
            s[i] = char('0' + (9 - d));
    }

    cout << s << endl;
}

/*---------------------------------------------------
  7. Ksenia and Pan Scales
---------------------------------------------------*/
void panScales()
{
    string s, extra;
    cin >> s >> extra;

    int pos = s.find('|');

    string left = s.substr(0, pos);
    string right = s.substr(pos + 1);

    for(char c : extra)
    {
        if(left.size() < right.size())
            left += c;
        else
            right += c;
    }

    if(left.size() == right.size())
        cout << left << "|" << right << endl;
    else
        cout << "Impossible" << endl;
}

/*---------------------------------------------------
  8. Launch of Collider
---------------------------------------------------*/
void collider()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> x(n);

    for(int i = 0; i < n; i++)
        cin >> x[i];

    int ans = INT_MAX;

    for(int i = 0; i < n - 1; i++)
    {
        if(s[i] == 'R' && s[i + 1] == 'L')
        {
            ans = min(ans, (x[i + 1] - x[i]) / 2);
        }
    }

    if(ans == INT_MAX)
        cout << -1 << endl;
    else
        cout << ans << endl;
}

/*---------------------------------------------------
  9. Polo the Penguin and Segments
---------------------------------------------------*/
void poloSegments()
{
    int n, k;
    cin >> n >> k;

    int sum = 0;

    while(n--)
    {
        int l, r;
        cin >> l >> r;

        sum += (r - l + 1);
    }

    cout << (k - sum % k) % k << endl;
}

/*---------------------------------------------------
  10. IQ Test
---------------------------------------------------*/
void iqTest()
{
    vector<string> g(4);

    for(int i = 0; i < 4; i++)
        cin >> g[i];

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            int black = 0;

            for(int x = i; x < i + 2; x++)
            {
                for(int y = j; y < j + 2; y++)
                {
                    if(g[x][y] == '#')
                        black++;
                }
            }

            if(black != 2)
            {
                cout << "YES" << endl;
                return;
            }
        }
    }

    cout << "NO" << endl;
}

/*---------------------------------------------------
  11. Yaroslav and Permutations
---------------------------------------------------*/
void yaroslav()
{
    int n;
    cin >> n;

    map<int,int> mp;

    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }

    int mx = 0;

    for(auto p : mp)
        mx = max(mx, p.second);

    cout << (mx <= (n + 1) / 2 ? "YES" : "NO") << endl;
}

/*---------------------------------------------------
  12. Snow Footprints
---------------------------------------------------*/
void snowFootprints()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    for(int i = 0; i < n; i++)
    {
        if(s[i] == 'R')
        {
            int j = i;

            while(j < n && s[j] == 'R')
                j++;

            cout << i + 1 << " " << j + 1 << endl;
            return;
        }

        if(s[i] == 'L')
        {
            int j = i;

            while(j < n && s[j] == 'L')
                j++;

            cout << j << " " << i << endl;
            return;
        }
    }
}

/*---------------------------------------------------
  13. Raising Bacteria
---------------------------------------------------*/
void bacteria()
{
    int x;
    cin >> x;

    cout << __builtin_popcount(x) << endl;
}

/*---------------------------------------------------
  14. BowWow and the Timetable
---------------------------------------------------*/
void bowwow()
{
    string s;
    cin >> s;

    int len = s.size();

    bool power = true;

    for(int i = 1; i < len; i++)
    {
        if(s[i] == '1')
            power = false;
    }

    int ans = (len - 1) / 2;

    if(!power || (len - 1) % 2)
        ans++;

    cout << ans << endl;
}

/*---------------------------------------------------
  15. Balanced Rating Changes
---------------------------------------------------*/
void balancedRating()
{
    int n;
    cin >> n;

    int odd = 0;

    while(n--)
    {
        int x;
        cin >> x;

        if(x % 2 == 0)
        {
            cout << x / 2 << endl;
        }
        else
        {
            if(odd % 2 == 0)
                cout << x / 2 << endl;
            else
            {
                if(x > 0)
                    cout << x / 2 + 1 << endl;
                else
                    cout << x / 2 - 1 << endl;
            }

            odd++;
        }
    }
}

/*---------------------------------------------------
  16. Word Capitalization
---------------------------------------------------*/
void wordCapitalization()
{
    string s;
    cin >> s;

    s[0] = toupper(s[0]);

    cout << s << endl;
}

/*---------------------------------------------------
  17. Next Round
---------------------------------------------------*/
void nextRound()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);

    for(int i = 0; i < n; i++)
        cin >> a[i];

    int score = a[k - 1];
    int ans = 0;

    for(int x : a)
    {
        if(x >= score && x > 0)
            ans++;
    }

    cout << ans << endl;
}

/*---------------------------------------------------
  18. Young Physicist
---------------------------------------------------*/
void youngPhysicist()
{
    int n;
    cin >> n;

    int x = 0, y = 0, z = 0;

    while(n--)
    {
        int a,b,c;
        cin >> a >> b >> c;

        x += a;
        y += b;
        z += c;
    }

    cout << ((x==0 && y==0 && z==0) ? "YES" : "NO") << endl;
}

/*---------------------------------------------------
  19. Bit++
---------------------------------------------------*/
void bitpp()
{
    int n;
    cin >> n;

    int x = 0;

    while(n--)
    {
        string s;
        cin >> s;

        if(s[1] == '+')
            x++;
        else
            x--;
    }

    cout << x << endl;
}

/*---------------------------------------------------
  20. Case of the Zeros and Ones
---------------------------------------------------*/
void zerosOnes()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    int zero = 0, one = 0;

    for(char c : s)
    {
        if(c == '0')
            zero++;
        else
            one++;
    }

    cout << abs(zero - one) << endl;
}

/*---------------------------------------------------
  21. Translation
---------------------------------------------------*/
void translation()
{
    string s, t;
    cin >> s >> t;

    reverse(s.begin(), s.end());

    cout << (s == t ? "YES" : "NO") << endl;
}

/*---------------------------------------------------
  22. String Task
---------------------------------------------------*/
bool vowel(char c)
{
    c = tolower(c);

    return c=='a'||c=='e'||c=='i'||
           c=='o'||c=='u'||c=='y';
}

void stringTask()
{
    string s;
    cin >> s;

    string ans = "";

    for(char c : s)
    {
        if(!vowel(c))
        {
            ans += '.';
            ans += tolower(c);
        }
    }

    cout << ans << endl;
}

/*---------------------------------------------------
  MAIN
---------------------------------------------------*/
int main()
{
    // Call any function here

    // Example:
    // goodNumber();

    return 0;
}