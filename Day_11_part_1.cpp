#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> grid;
    string nextLine;
    ifstream inputFile("input/Day_11_input.txt");

    if (inputFile.is_open())
    {
        while (getline(inputFile, nextLine))
        {
            grid.push_back(nextLine);
        }
        inputFile.close();
    }
    int n = grid.size(), m = grid[0].size();
    map<array<int, 2>, array<int, 2>> loc;
    int r = 0, cnt = 0;
    for (int i = 0; i < n; i++,r++)
    {
        cnt = 0;
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '#')
            {
                loc[{i, j}][0] = r;
                cnt++;
            }
        }
        if (!cnt)
            r++;
    }
    r = 0;
    for (int j = 0; j < m; j++,r++)
    {
        cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (grid[i][j] == '#')
            {
                loc[{i, j}][1] = r;
                cnt++;
            }
        }
        if (!cnt)
            r++;
    }
    long ans = 0;
    array<int, 2> v[loc.size()];
    cnt = 0;
    for (auto [x, y] : loc)
        v[cnt++] = y;
    for (int i = 0; i < cnt; i++)
    {
        for (int j = i + 1; j < cnt; j++)
        {
            ans += (abs(v[i][0] - v[j][0]) + abs(v[i][1] - v[j][1]));
        }
    }
    cout << ans;
}