#include <bits/stdc++.h>
using namespace std;

unordered_map<char, array<array<int, 2>, 2>> m = {
    {'F', {{{1, 0}, {0, 1}}}},
    {'7', {{{-1, 0}, {0, 1}}}},
    {'L', {{{0, -1}, {1, 0}}}},
    {'J', {{{0, -1}, {-1, 0}}}},
    {'-', {{{-1, 0}, {1, 0}}}},
    {'|', {{{0, -1}, {0, 1}}}}};

int sx, sy, rx, ry;
map<array<int, 2>, vector<array<int, 2>>> adj;
map<array<int, 2>, bool> rec;

int f(int i, int j, int px, int py)
{
    if (i == rx and j == ry)
    {
        return 0;
    }
    if (rec[{i, j}])
        return -1e9;

    rec[{i, j}] = 1;
    int len = -1e9;
    for (auto [x, y] : adj[{i, j}])
    {
        if (x == px and y == py)
            continue;
        len = max(len, f(x, y, i, j) + 1);
    }
    rec[{i, j}] = 0;
    return len;
}
int main()
{
    vector<string> grid;
    string nextLine;
    ifstream inputFile("input/Day_10_input.txt");

    if (inputFile.is_open())
    {
        while (getline(inputFile, nextLine))
        {
            grid.push_back(nextLine);
        }
        inputFile.close();
    }
    int r = grid.size(), c = grid[0].size();
    int x, y, xx, yy;
    adj.clear();
    for (int i = 0; i < r; i++)
    {
        y = i * 2 + 1;
        for (int j = 0; j < c; j++)
        {
            x = j * 2;
            if (grid[i][j] == '.')
                continue;
            if (grid[i][j] == 'S')
            {
                sx = x;
                sy = y;
                continue;
            }
            auto [x1, y1] = m[grid[i][j]][0];
            auto [x2, y2] = m[grid[i][j]][1];
            x1 += x;
            x2 += x;
            y1 += y;
            y2 += y;
            adj[{x1, y1}].push_back({x2, y2});
            adj[{x2, y2}].push_back({x1, y1});
        }
    }
    int ans = 0, s;
    for (auto [a, b] : m)
    {
        rec.clear();
        auto [x1, y1] = b[0];
        auto [x2, y2] = b[1];
        x1 += sx;
        x2 += sx;
        y1 += sy;
        y2 += sy;
        rx = x2;
        ry = y2;
        s = f(x1, y1, sx, sy) + 1;
        ans = max(ans, s / 2);
    }
    cout << ans;
}