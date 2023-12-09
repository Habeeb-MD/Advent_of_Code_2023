#include <bits/stdc++.h>
using namespace std;

int main()
{
    long ans = 0;
    vector<long> temp;

    string nextLine, s;
    ifstream inputFile("input/Day_9_input.txt");

    if (inputFile.is_open())
    {
        while (getline(inputFile, nextLine))
        {
            temp.clear();

            stringstream ss(nextLine);

            while (getline(ss, s, ' '))
            {
                temp.push_back(stol(s));
            }
            int z = 0, c = 1;
            long firstNum = 0;
            vector<long> v;
            while (z != temp.size())
            {
                z = 0;
                firstNum += c * temp.front();
                c *= -1;
                for (int i = 1; i < temp.size(); i++)
                {
                    v.push_back(temp[i] - temp[i - 1]);
                    z += (temp[i] == temp[i - 1]);
                }
                temp = v;
                v.clear();
            }
            ans += firstNum;
        }
        inputFile.close();
    }
    cout << ans;
}