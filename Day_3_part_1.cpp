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
    char ch;
    int n = ip.size(), m = ip[0].size(), curNum = 0, l = 0;
    auto checkPart = [&](int i, int jl, int jr)
    {
        for (int x = max(0, i - 1); x <= min(n - 1, i + 1); x++)
        {
            for (int y = max(0, jl - 1); y <= min(m - 1, jr + 1); y++)
            {
                ch = ip[x][y];
                if (ch != '.' && (ch < '0' || ch > '9'))
                    return 1;
            }
        }
        return 0;
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
                if (checkPart(i, j - l, j - 1))
                    sum += curNum;
                l = 0;
                curNum = 0;
            }
        }
        if (l and checkPart(i, m - l, m - 1))
            sum += curNum;
    }
    cout << sum;
}
