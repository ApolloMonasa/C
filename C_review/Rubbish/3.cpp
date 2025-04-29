/*************************************************************************
	> File Name: 3.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Mon 24 Mar 2025 04:23:00 PM CST
 ************************************************************************/
/*************************************************************************
        > File Name: 1.cpp
        > Author: HDU-Apollo
        > Mail: xyl6716@outlook.com
        > Created Time: Mon 24 Mar 2025 03:49:44 PM CST
 ************************************************************************/
/*************************************************************************
        > File Name: 1.cpp
        > Author: HDU-Apollo
        > Mail: xyl6716@outlook.com
        > Created Time: Mon 24 Mar 2025 03:49:44 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<cmath>
#include<cstring>
#include<climits>
#include<algorithm>
#include<iomanip>
#include<queue>
using namespace std;
struct Node{
    int val;
    struct Node *next;
};

void insert(Node *p, int x) {
    Node *q = p;
    while(q->next) q = q->next;
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->val = x;
    newnode->next = NULL;
    q->next = newnode;
    return;
}

void output(Node *p) {
    if(!p) {
        cout << endl;
        return;
    }
    cout << p->val;
    p = p->next;
    while(p){
        cout << "->" << p->val;
        p = p->next;
    }
}

int main() {
    Node *list1 = (Node*)malloc(sizeof(Node));
    Node *list2 = (Node*)malloc(sizeof(Node));
    list1->next = NULL;
    list2->next = NULL;
    vector<int> arr1;
    int t;
    while(cin >> t) arr1.push_back(t);
    sort(arr1.begin(), arr1.end());
    for (int i : arr1) {
        if(i % 2) insert(list1, i);
        else insert(list2, i);
    }
    output(list1->next);
    cout << "->";
    output(list2->next);
    cout << endl;
    output(list1->next);
    cout << endl;
    output(list2->next);
    cout << endl;

    return 0;
}
