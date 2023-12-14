#include <bits/stdc++.h>
using namespace std;

vector<string> grid;
int n, m;

void tiltNorth()
{
    for (int j = 0; j < m; j++)
    {
        int k = -1;
        for (int i = 0; i < n; i++)
        {
            if (grid[i][j] == '#')
            {
                k = -1;
            }
            else if (grid[i][j] == '.')
            {
                if (k < 0 or grid[k][j] != '.')
                    k = i;
            }
            else if (k >= 0)
            {
                swap(grid[i][j], grid[k][j]);
                k++;
            }
        }
    }
}
void tiltSouth()
{
    for (int j = 0; j < m; j++)
    {
        int k = -1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (grid[i][j] == '#')
            {
                k = -1;
            }
            else if (grid[i][j] == '.')
            {
                if (k < 0 or grid[k][j] != '.')
                    k = i;
            }
            else if (k >= 0)
            {
                swap(grid[i][j], grid[k][j]);
                k--;
            }
        }
    }
}
void tiltWest()
{
    for (int i = 0; i < n; i++)
    {
        int k = -1;
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '#')
            {
                k = -1;
            }
            else if (grid[i][j] == '.')
            {
                if (k < 0 or grid[i][j] != '.')
                    k = j;
            }
            else if (k >= 0)
            {
                swap(grid[i][k], grid[i][j]);
                k++;
            }
        }
    }
}
void tiltEast()
{
    for (int i = 0; i < n; i++)
    {
        int k = -1;
        for (int j = m - 1; j >= 0; j--)
        {
            if (grid[i][j] == '#')
            {
                k = -1;
            }
            else if (grid[i][j] == '.')
            {
                if (k < 0 or grid[i][j] != '.')
                    k = j;
            }
            else if (k >= 0)
            {
                swap(grid[i][k], grid[i][j]);
                k--;
            }
        }
    }
}

long calculateLoad()
{
    long int load = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'O')
                load += (n - i);
        }
    }
    return load;
}

pair<string, int> getGridAsString()
{
    string gridString;
    int zeroCount = 0;
    for (auto w : grid)
    {
        gridString += (w + "_");
        for (auto c : w)
            zeroCount += (c == 'O');
    }
    return {gridString, zeroCount};
}
void tiltInAllDir(int t)
{
    unordered_map<string, int> Map;
    auto [gridString, zeroCount] = getGridAsString();
    Map[gridString] = 1;
    for (int i = 2; i <= t and zeroCount; i++)
    {
        tiltNorth();
        tiltWest();
        tiltSouth();
        tiltEast();
        auto [x, y] = getGridAsString();
        gridString = x;
        zeroCount = y;
        if (Map.find(gridString) != Map.end())
        {
            int z = Map[gridString];
            tiltInAllDir((t - z) % (i - z) + 1);
            return;
        }
        else
            Map[gridString] = i;
    }
}
int main()
{
    string nextLine;
    ifstream inputFile("input/Day_14_input.txt");
    grid.clear();
    if (inputFile.is_open())
    {
        while (getline(inputFile, nextLine))
        {
            grid.push_back(nextLine);
        }
        inputFile.close();
    }
    n = grid.size(), m = grid[0].size();
    tiltNorth();
    cout << "Soltion Part 1: " << calculateLoad() << "\n";
    tiltWest();
    tiltSouth();
    tiltEast();
    tiltInAllDir(1000000000);
    cout << "Soltion Part 2: " << calculateLoad() << "\n";
}