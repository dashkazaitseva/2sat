//******************************
//Dasha Zaitseva's code
//******************************

#include <bits/stdc++.h>

using namespace std;

int n, m;
vector <vector <int> > g;
vector <vector <int> > gc;
vector <int> ord;
vector <int> comp;
vector <int> used;
int cur_num = 0;

void dfs1(int v)
{
    used[v] = 1;
    for (size_t i = 0; i < g[v].size(); i ++)
    {
        int to = g[v][i];
        if (used[to] == 0)
        {
            dfs1(to);
        }
    }
    ord.push_back(v);
}

void dfs2(int v)
{
    used[v] = 1;
    comp[v] = cur_num;
    for (size_t i = 0; i < gc[v].size(); i ++)
    {
        int to = gc[v][i];
        if (comp[to] == 0)
        {
            dfs2(to);
        }
    }

}

int main()
{
    freopen("2sat.in", "r", stdin);
    freopen("2sat.out", "w", stdout);
    while (cin >> n)
    {
    cin >> m;
    n *= 2;
    if (m == 0)
    {
        for (int i = 0; i < n / 2; i ++)
        {
           cout << 0;
        }
        cout << "\n";
        continue;
    }
    cur_num = 0;
    g.resize(n);
    gc.resize(n);
    comp.assign(n, 0);
    used.assign(n, 0);
    for (size_t i = 0; i < m; i ++)
    {
        int i1, i2, a, b;
        cin >> i1 >> a >> i2 >> b;
        i1 *= 2;
        i2 *= 2;
        if (a == 0 && b == 0)
        {
            g[i1].push_back(i2^1);
            g[i2].push_back(i1^1);
            gc[i2^1].push_back(i1);
            gc[i1^1].push_back(i2);
        }
        else if (a == 0 && b == 1)
        {
            g[i1].push_back(i2);
            g[i2^1].push_back(i1^1);
            gc[i2].push_back(i1);
            gc[i1^1].push_back(i2^1);
        }
        else if (a == 1 && b == 0)
        {
            gc[i1].push_back(i2);
            gc[i2^1].push_back(i1^1);
            g[i2].push_back(i1);
            g[i1^1].push_back(i2^1);
        }
        else if (a == 1 && b == 1)
        {
            gc[i1].push_back(i2^1);
            gc[i2].push_back(i1^1);
            g[i2^1].push_back(i1);
            g[i1^1].push_back(i2);
        }
    }
    for (size_t i = 0; i < n; i ++)
    {
        if (used[i] == 0)
        {
            dfs1(i);
        }
    }

    used.assign(n, 0);
    for (int i = n - 1; i >= 0; i --)
    {
        int v = ord[i];
        if (used[v] == 0)
        {
            cur_num ++;
            dfs2(v);
        }
    }

    for (size_t i = 0; i < n; i += 2)
    {
        if (comp[i] > comp[i^1])
        {
            cout << "1";
        }
        else
        {
            cout << "0";
        }
    }
    cout << "\n";
    }
}

