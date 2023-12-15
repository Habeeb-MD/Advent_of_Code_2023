#include <bits/stdc++.h>
using namespace std;

std::vector<std::string> split(const std::string &s, char delim)
{
    std::vector<std::string> result;
    std::stringstream ss(s);
    std::string item;

    while (getline(ss, item, delim))
    {
        result.push_back(item);
    }

    return result;
}

long getHash(string s)
{
    long ans = 0, mul = 17, div = 256;
    for (auto i : s)
        ans = ((ans + i) * mul) % div;
    return ans;
}

long calculateFocusingPower(vector<std::string> &inputStringVector)
{
    unordered_map<string, list<int>::iterator> Map[256];
    list<int> lst[256];
    int box, focalLength, p;
    for (auto s : inputStringVector)
    {
        if (s.back() != '-')
        {
            p = 1;
            focalLength = 0;
            while (s.back() != '=')
            {
                focalLength = focalLength + p * (s.back() - '0');
                p *= 10;
                s.pop_back();
            }
            s.pop_back();
            box = getHash(s);
            if (Map[box].find(s) != Map[box].end())
            {
                *Map[box][s] = focalLength;
            }
            else
            {
                lst[box].push_back(focalLength);
                Map[box][s] = prev(lst[box].end());
            }
        }
        else
        {
            s.pop_back();
            box = getHash(s);
            if (Map[box].find(s) != Map[box].end())
            {
                lst[box].erase(Map[box][s]);
                Map[box].erase(s);
            }
        }
    }
    long ans = 0;
    for (box = 0; box < 256; box++)
    {
        int slot = 1;
        for (auto it = lst[box].begin(); it != lst[box].end(); it++, slot++)
        {
            ans += (box + 1) * slot * (*it);
        }
    }
    return ans;
}
long calculateSumofHash(vector<std::string> &inputStringVector)
{
    long ans = 0;
    for (auto s : inputStringVector)
        ans += getHash(s);
    return ans;
}
int main()
{
    string nextLine, inputString;
    ifstream inputFile("input/Day_15_input.txt");
    if (inputFile.is_open())
    {
        while (getline(inputFile, nextLine))
        {
            inputString = nextLine;
        }
        inputFile.close();
    }
    vector<std::string> inputStringVector = split(inputString, ',');

    std::cout << "Soltion Part 1: " << calculateSumofHash(inputStringVector) << "\n";
    std::cout << "Soltion Part 2: " << calculateFocusingPower(inputStringVector) << "\n";
}