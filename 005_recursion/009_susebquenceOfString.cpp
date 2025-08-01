#include <iostream>
#include <vector>
using namespace std;

void generate(vector<string> &ans, string s, string k, int i)
{
    if (i == s.length())
    {
        ans.push_back(k);
        return;
    }
    generate(ans, s, k + s[i], i + 1);

    generate(ans, s, k, i + 1);
}

vector<string> subsequenceString(string s)
{
    vector<string> ans;
    string k = "";
    generate(ans, s, k, 0);
    return ans;
}

int main()
{
    string s = "abc";
    vector<string> ans = subsequenceString(s);
    for (auto it : ans)
    {
        cout << it << endl;
    }
    return 0;
}