#include <bits/stdc++.h>
using namespace std;

vector<string> grid;
long long shortestPath(int expansionFactor)
{
    int n = grid.size(), m = grid[0].size();
    map<array<int, 2>, array<long long int, 2>> loc;
    long int r = 0, cnt = 0;
    for (int i = 0; i < n; i++, r++)
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
            r += (expansionFactor - 1);
    }
    r = 0;
    for (int j = 0; j < m; j++, r++)
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
            r += (expansionFactor - 1);
    }
    long long ans = 0;
    for (auto itr = loc.begin(); itr != loc.end(); itr++)
    {
        for (auto itr2 = next(itr); itr2 != loc.end(); itr2++)
        {
            ans += (abs(itr->second[0] - itr2->second[0]) + abs(itr->second[1] - itr2->second[1]));
        }
    }
    return ans;
}
int main()
{
    string nextLine;
    ifstream inputFile("input/Day_11_input.txt");
    grid.clear();
    if (inputFile.is_open())
    {
        while (getline(inputFile, nextLine))
        {
            grid.push_back(nextLine);
        }
        inputFile.close();
    }
    cout << "Soltion Part 1: "<<shortestPath(2) << "\n";
    cout << "Soltion Part 2: "<<shortestPath(1000000) << "\n";
}