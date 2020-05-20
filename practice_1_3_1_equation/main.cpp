//
//  main.cpp
//  practice_1_3_1_equation
//
//  Created by Admin on 2020/5/14.
//

#include <iostream>
#include <vector>

using namespace std;

#define MAX_SIZE 300005

const int SZ = 1 << 20;
struct fastio{   //fast io
    char inbuf[SZ];
    char outbuf[SZ];
    fastio(){
        setvbuf(stdin,inbuf,_IOFBF,SZ);
        setvbuf(stdout,outbuf,_IOFBF,SZ);
    }
}io;

int father[MAX_SIZE], theRank[MAX_SIZE];

void vectorUnion(int setA, int setB) {
    if (theRank[setA] == theRank[setB]) {
        father[setB] = setA;
        theRank[setA] += 1;
    } else if (theRank[setA] > theRank[setB]) {
        father[setB] = setA;
    } else {
        father[setA] = setB;
    }
}

int vectorFind(int x) {
    if (father[x] == x) {
        return x;
    } else {
        father[x] = vectorFind(father[x]);
        return father[x];
    }
//    while (father[x] != x) {
//        father[x] = father[father[father[x]]];
//        x = father[x];
//    }
    return x;
}

string getAnswer(vector<int> vector_a, vector<int> vector_b, vector<int> vector_e, int m, int n) {
    for (int i = 1; i <= n; i ++) {
        father[i] = i;
        theRank[i] = 0;
    }
    
    int lo = 0, hi = m - 1;
    while (lo < hi) {
        while (vector_e[lo] == 1) {
            lo ++;
        }
        while (vector_e[hi] == 0) {
            hi --;
        }
        if (lo < hi) {
            swap(vector_a[hi], vector_a[lo]);
            swap(vector_b[hi], vector_b[lo]);
            swap(vector_e[hi], vector_e[lo]);
        }
    }
    
    for (int i = 0; i < m; i++) {
        int setA = vectorFind(vector_a[i]);
        int setB = vectorFind(vector_b[i]);
        if (vector_e[i] == 0) {
            if (setA == setB) {
                return "No";
            }
        } else {
            if (setA != setB) {
                vectorUnion(setA, setB);
            }
        }
    }
    return "Yes";
}

int main(int argc, const char * argv[]) {
    // insert code here...
//#ifndef  _OJ_
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//#endif // ! _OJ_
    int num;
    scanf("%d", &num);
    while (num --) {
        int n, m;
        scanf("%d %d", &n, &m);
        vector<int> vector_a, vector_b, vector_e;
        for (int i = 0; i < m; i ++) {
            int a, b, e;
            scanf("%d %d %d", &a, &b, &e);
            vector_a.push_back(a);
            vector_b.push_back(b);
            vector_e.push_back(e);
        }
        printf("%s\n", getAnswer(vector_a, vector_b, vector_e, m, n).c_str());
    }
    
    return 0;
}

