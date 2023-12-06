#include <bits/stdc++.h>
using namespace std;

int main()
{
    int curNum = 0, num = -1;
    vector<int> Time, Dist, temp;

    string nextLine;
    ifstream inputFile("input/Day_6_input.txt");

    if (inputFile.is_open())
    {
        while (getline(inputFile, nextLine))
        {
            temp.clear();
            curNum = 0;
            num++;

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
                    if (ch == ' ' and nextLine[i - 1] >= '0' and nextLine[i - 1] <= '9')
                    {
                        temp.push_back(curNum);
                    }
                    curNum = 0;
                }
            }
            if (num == 0)
                for (auto i : temp)
                    Time.push_back(i);
            else
                for (auto i : temp)
                    Dist.push_back(i);
        }
        inputFile.close();
    }

    long long t,d,ans;
    string tmp;
    for(auto i:Time)tmp+=to_string(i);
    
    t = stoll(tmp);
    tmp = "";
    for(auto i:Dist)tmp+=to_string(i);
    d = stoll(tmp);

    long long D = sqrt(t * t - 4 * d);
    long long a = (t - D) / 2;
    if (a * (t - a) <= d)
        a++;
    long long b = (t + D) / 2;
    if (b * (t - b) <= d)
        b--;
    ans = b - a + 1;
    cout << ans;
}