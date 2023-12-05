#include <bits/stdc++.h>
using namespace std;

int main()
{
    long curNum = 0;
    int num = -1;
    vector<array<long int, 3>> conversion_map[8];
    vector<long> seeds, temp;

    string nextLine;
    ifstream inputFile("input/Day_5_input.txt");

    if (inputFile.is_open())
    {
        while (getline(inputFile, nextLine))
        {
            temp.clear();
            curNum = 0;

            int len = nextLine.size();
            for (int i = 0; i < len; i++)
            {
                char ch = nextLine[i];
                if (ch >= '0' && ch <= '9')
                {
                    curNum = curNum * 10 + (ch - '0');
                    if (i == len - 1)
                    {
                        temp.push_back(curNum);
                    }
                }
                else
                {
                    if (ch == ':')
                    {
                        num++;
                    }
                    if (ch == ' ' and nextLine[i - 1] >= '0' and nextLine[i - 1] <= '9')
                    {
                        temp.push_back(curNum);
                    }
                    curNum = 0;
                }
            }
            if (num == 0)
                for (auto i : temp)
                    seeds.push_back(i);
            else if (temp.size() == 3)
                conversion_map[num].push_back({temp[1], temp[0], temp[2]});
        }
        inputFile.close();
    }
    for (int i = 1; i < 8; i++)
    {
        sort(conversion_map[i].begin(), conversion_map[i].end());
    }
    long ans = LONG_MAX;
    for (auto seed : seeds)
    {
        long int t = seed;
        for (int i = 1; i < 8; i++)
        {
            int x = upper_bound(conversion_map[i].begin(), conversion_map[i].end(), array<long, 3>{t, -1L, -1L}) - conversion_map[i].begin();
            if (x and conversion_map[i][x - 1][0] + conversion_map[i][x - 1][2] >= t)
                t = conversion_map[i][x - 1][1] + t - conversion_map[i][x - 1][0];
        }
        ans = min(ans, t);
    }
    cout << ans;
}