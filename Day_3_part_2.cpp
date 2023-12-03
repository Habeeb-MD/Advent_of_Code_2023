#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long sum = 0;
    ifstream inputFile("input/Day_3_input.txt");

    vector<string> ip;
    string nextLine;
    if (inputFile.is_open())
    {
        while (getline(inputFile, nextLine))
        {
            ip.push_back(nextLine);
        }
        inputFile.close();
    }

    int n = ip.size(), m = ip[0].size(), curNum = 0, l = 0;
    vector<vector<vector<int>>> v(n, vector<vector<int>>(m));
    auto checkPart = [&](int i, int jl, int jr)
    {
        for (int x = max(0, i - 1); x <= min(n - 1, i + 1); x++)
        {
            for (int y = max(0, jl - 1); y <= min(m - 1, jr + 1); y++)
            {
                if (ip[x][y] == '*')
                {
                    v[x][y].push_back(curNum);
                }
            }
        }
    };

    for (int i = 0; i < n; i++)
    {
        l = curNum = 0;
        for (int j = 0; j < m; j++)
        {
            char ch = ip[i][j];
            if (ch >= '0' && ch <= '9')
            {
                curNum = curNum * 10 + (ch - '0');
                l++;
            }
            else if (curNum)
            {
                checkPart(i, j - l, j - 1);
                curNum = 0;
                l=0;
            }
        }
        if (curNum)
            checkPart(i, m - l, m - 1);
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (ip[i][j] == '*')
            {
                if (v[i][j].size() == 2)
                    sum += v[i][j][0] * v[i][j][1];
            }
    cout << sum;
}
