#include <bits/stdc++.h>
using namespace std;

vector<string> grid;
int n, m;

// prevDirection => 0 right 1 down 2 left 3 up
unordered_map<int, array<int, 2>> Directions = {
    {0, {0, 1}},
    {1, {1, 0}},
    {2, {0, -1}},
    {3, {-1, 0}},
};
set<array<int, 3>> beamSet;
queue<array<int, 3>> beams;

void addNewBeam(int i, int j, int newDir)
{
    auto [dx, dy] = Directions[newDir];
    int x = i + dx, y = j + dy;
    if (x >= 0 and y >= 0 and x < n and y < m and beamSet.find({x, y, newDir}) == beamSet.end())
    {
        beamSet.insert({x, y, newDir});
        beams.push({x, y, newDir});
    }
}
int getEnergizedCells(int startCellX = 0, int startCellY = 0, int startDir = 0)
{
    beamSet.clear();
    while (!beams.empty())
        beams.pop();

    beams.push({startCellX, startCellY, startDir});
    beamSet.insert({startCellX, startCellY, startDir});

    while (!beams.empty())
    {
        auto [i, j, prevDir] = beams.front();
        beams.pop();
        int newDir = prevDir;
        /*
        If the beam encounters a mirror (/ or \), the beam is reflected 90 degrees
        */
        if (grid[i][j] == '/' or grid[i][j] == '\\')
        {
            if (prevDir == 0)
                newDir = grid[i][j] == '/' ? 3 : 1;
            if (prevDir == 1)
                newDir = grid[i][j] == '/' ? 2 : 0;
            if (prevDir == 2)
                newDir = grid[i][j] == '/' ? 1 : 3;
            if (prevDir == 3)
                newDir = grid[i][j] == '/' ? 0 : 2;
        }

        /*
        If the beam encounters the flat side of a splitter (| or -), the beam is split into two beams
        */
        if (grid[i][j] == '|' and (prevDir == 0 or prevDir == 2))
        {
            newDir = 1;
            addNewBeam(i, j, newDir);
            newDir = 3;
        }
        if (grid[i][j] == '-' and (prevDir == 1 or prevDir == 3))
        {
            newDir = 0;
            addNewBeam(i, j, newDir);
            newDir = 2;
        }
        addNewBeam(i, j, newDir);
    }
    set<pair<int, int>> distinctEnergizedCells;
    for (auto [x, y, z] : beamSet)
        distinctEnergizedCells.insert({x, y});
    return distinctEnergizedCells.size();
}
int getMaxEnergy()
{
    int maxEnergy = 0;
    for (int j = 0; j < m; j++)
    {
        maxEnergy = max(maxEnergy, getEnergizedCells(0, j, 1));
        maxEnergy = max(maxEnergy, getEnergizedCells(n - 1, j, 3));
    }
    for (int i = 0; i < n; i++)
    {
        maxEnergy = max(maxEnergy, getEnergizedCells(i, 0, 0));
        maxEnergy = max(maxEnergy, getEnergizedCells(i, m - 1, 2));
    }
    return maxEnergy;
}

int main()
{
    string nextLine;
    ifstream inputFile("input/Day_16_input.txt");
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
    cout << "Soltion Part 1: " << getEnergizedCells() << "\n";
    cout << "Soltion Part 2: " << getMaxEnergy() << "\n";
}