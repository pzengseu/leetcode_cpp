//
// Created by zp on 12/13/16.
//

#ifndef LEETCODE_CPP_DECODEWAYS91_H
#define LEETCODE_CPP_DECODEWAYS91_H

#include <iostream>
using namespace std;

class Solution {
public:
    static int numDecodings(string s);
};

int Solution::numDecodings(string s) {
    const int n = s.size();
    if(!n||s[0]=='0') return 0;
    else if(n==1 && (s[0]<'0'||s[0]>'9')) return 0;

    int pre=1, next=1, res=1;
    for(int i=1;i<n;i++)
    {
        if(s[i]=='0') next=0;
        if(!(s[i-1]=='1'||s[i-1]=='2'&&s[i]<='6')) pre=0;

        res = pre + next;
        pre = next;
        next = res;
    }
    return res;
}
#endif //LEETCODE_CPP_DECODEWAYS91_H
