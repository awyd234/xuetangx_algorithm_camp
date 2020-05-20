//
//  main.cpp
//  practice_2_1_3_eurerCircuit
//
//  Created by Admin on 2020/5/20.
//

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

const int N = (2 << 16) + 3;

const int SZ = 1 << 20;
struct fastio{   //fast io
    char inbuf[SZ];
    char outbuf[SZ];
    fastio(){
        setvbuf(stdin,inbuf,_IOFBF,SZ);
        setvbuf(stdout,outbuf,_IOFBF,SZ);
    }
}io;

int allOne;
vector<bool> visit[2];
stack<int> ans;

void dfs(int u) {
    for (int i = 0; i < 2; i++) {
        if (!visit[i][u]) {
            int v = ((u << 1) | i) & allOne;
            visit[i][u] = 1;
            dfs(v);
            ans.push(i);
        }
    }
}

void getAnswer(int n) {
    allOne = (1 << (n - 1)) - 1;
    for (int i = 0; i < 2; i++) {
        visit[i].resize((1 << (n - 1)), 0);
    }
    dfs(0);
    while (!ans.empty()) {
        printf("%d", ans.top());
        ans.pop();
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    scanf("%d", &n);
    getAnswer(n);
    printf("\n");
    return 0;
}
