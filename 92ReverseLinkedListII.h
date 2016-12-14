//
// Created by zp on 12/14/16.
//

#ifndef LEETCODE_CPP_92REVERSELINKEDLISTII_H
#define LEETCODE_CPP_92REVERSELINKEDLISTII_H

#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int m, int n);
};

ListNode* Solution::reverseBetween(ListNode *head, int m, int n)
{
    if(m==n)
    {
        return head;
    }
    n -= m;
    ListNode dummy(0);
    dummy.next = head;
    ListNode *pre = &dummy;
    while(--m)
    {
        pre = pre->next;
    }
    ListNode *pStart = pre->next;
    while(n--)
    {
        ListNode *p = pStart->next;
        pStart->next = p->next;
        p->next = pre->next;
        pre->next = p;
    }
    return dummy.next;
}
#endif //LEETCODE_CPP_92REVERSELINKEDLISTII_H
