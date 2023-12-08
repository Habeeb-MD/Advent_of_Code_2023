#include <bits/stdc++.h>
using namespace std;

int main()
{
    string moves;
    unordered_map<string, array<string, 2>> Map;

    string nextLine;
    ifstream inputFile("input/Day_8_input.txt");

    if (inputFile.is_open())
    {
        string key, leftVal, rightVal;
        while (getline(inputFile, nextLine))
        {
            if(nextLine.empty())
                continue;

            if (moves.empty())
            {
                moves = nextLine;
                continue;
            }
                
            key = nextLine.substr(0, nextLine.find_first_of(' '));
            leftVal = nextLine.substr(nextLine.find_first_of('(') + 1, 3);
            rightVal = nextLine.substr(nextLine.find_first_of(',') + 2, 3);
            Map[key] = {leftVal, rightVal};
        }
        inputFile.close();
    }
    string curNode = "AAA";
    int n = moves.size(), ans = 0;
    for (int i = 0; curNode != "ZZZ"; i = (i + 1) % n)
    {
        curNode = moves[i] == 'L' ? Map[curNode][0] : Map[curNode][1];
        ans++;
    }
    cout << ans;
}