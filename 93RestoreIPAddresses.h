//
// Created by zp on 12/14/16.
//

#ifndef LEETCODE_CPP_93RESTOREIPADDRESSES_H
#define LEETCODE_CPP_93RESTOREIPADDRESSES_H

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s);
    void dfs(string s, int start, int step, string ip, vector<string> &result);
};

vector<string> Solution::restoreIpAddresses(string s)
{
    vector<string> result;
    string ip;
    dfs(s, 0, 0, ip, result);
    return result;
}

void Solution::dfs(string s, int start, int step, string ip, vector<string> &result) {
    if (start == s.size() && step == 4) {
        ip.erase(ip.end() - 1);
        result.push_back(ip);
        return;
    }
    if (s.size() - start > (4 - step) * 3) return;
    if (s.size() - start < (4 - step)) return;
    int num = 0;
    for (int i = start; i < start + 3; i++)
    {
        num = num*10+(s[i]-'0');
        if(num<=255)
        {
            ip+=s[i];
            dfs(s, i+1, step+1, ip+'.', result);
        }
        if(num==0) break;
    }
}
#endif //LEETCODE_CPP_93RESTOREIPADDRESSES_H