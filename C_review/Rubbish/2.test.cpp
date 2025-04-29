/*************************************************************************
	> File Name: 2.test.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Mon 24 Mar 2025 04:14:45 PM CST
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
    cout << endl;
}

int main() {
    Node *list1 = (Node*)malloc(sizeof(Node));
    Node *list2 = (Node*)malloc(sizeof(Node));
    list1->next = NULL;
    list2->next = NULL;
    vector<int> arr1, arr2;
    int t;
    while(cin >> t) {
        if(t > 0) arr1.push_back(t);
        else arr2.push_back(t);
    }
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    for (int i : arr1) {
        insert(list1, i);
    }
    for (int i : arr2) {
        insert(list2, i);
    }
    output(list1->next);
    output(list2->next);
    
    Node *p = list2;
    while(p->next) p = p->next;
    p->next = list1->next;
    output(list2->next);
    return 0;
}
