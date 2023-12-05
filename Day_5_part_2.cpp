#include <bits/stdc++.h>
using namespace std;

vector<array<long int, 3>> conversion_map[8];
long Search(long a, long b, int i)
{
    if (i == 8)
        return a;
    long ans = LONG_MAX;

    if (a >= (conversion_map[i].back()[0] + conversion_map[i].back()[2]))
        return Search(a, b, i + 1);

    if (a < conversion_map[i][0][0])
    {
        ans = Search(a, min(b, conversion_map[i][0][0] - 1), i + 1);
        a = conversion_map[i][0][0];
    }

    if (a > b)
        return ans;

    int x = upper_bound(conversion_map[i].begin(), conversion_map[i].end(),
                        array<long, 3>{a, LONG_MAX, LONG_MAX}) -
            conversion_map[i].begin();
    auto [p, q, r] = conversion_map[i][x - 1];

    if (p + r <= a)
    {
        if (x == conversion_map[i].size())
            return min(ans, Search(a, b, i + 1));
        ans = min(ans, Search(a, min(b, conversion_map[i][x][0] - 1), i + 1));
        if (b >= conversion_map[i][x][0])
            ans = min(ans, Search(conversion_map[i][x][0], b, i));
        return ans;
    }

    long na = q + a - p;
    long nb = q + b - p;
    if (b >= p + r)
    {
        nb = q + r - 1;
        a = p + r;
        ans = min(ans, Search(a, b, i));
    }
    return min(ans, Search(na, nb, i + 1));
}
int main()
{
    for (int i = 1; i < 8; i++)
    {
        conversion_map[i].clear();
    }

    long curNum = 0;
    int num = -1;
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
    for (int i = 0; i + 1 < seeds.size(); i += 2)
    {
        long t = Search(seeds[i], seeds[i] + seeds[i + 1] - 1, 1);
        ans = min(ans, t);
    }
    cout << ans;
}