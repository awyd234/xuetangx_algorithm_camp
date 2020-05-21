//
//  main.cpp
//  practice_2_2_1_ChineseChess
//
//  Created by Admin on 2020/5/21.
//

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

//const int N = 502;

const int SZ = 1 << 20;
struct fastio{   //fast io
    char inbuf[SZ];
    char outbuf[SZ];
    fastio(){
        setvbuf(stdin,inbuf,_IOFBF,SZ);
        setvbuf(stdout,outbuf,_IOFBF,SZ);
    }
}io;

//vector<bool> used(N, false);
//vector<int> girl(N, 0);
//
//bool find(vector<vector<int>> value, int n, int x) {
//    for (int j = 0; j < n; j++) {
//        if(value[x][j] && !used[j]) {
//            used[j] = true;
//            if (girl[j] == 0 || find(value, n, girl[j])) {
//                girl[j] = x;
//                return true;
//            }
//        }
//    }
//    return false;
//}
//
//int getAnswer(vector<vector<int>> value, int n) {
//    int count = 0;
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j ++) {
//            used[j] = false;
//        }
//        if (find(value, n, i)) {
//            count += 1;
//        }
//    }
//    return count;
//}

const int N = 505 * 2, M = N * N;

struct E {
    int next, to;
} e[M];

int cnt, ihead[N], mc[N];
bool visited[N];

void add(int x, int y) {
    cnt ++;
    e[cnt].next = ihead[x];
    e[cnt].to = y;
    ihead[x] = cnt;
}

bool dfs(int x) {
    for (int i = ihead[x]; i; i = e[i].next) {
        int y = e[i].to;
        if (!visited[y]) {
            visited[y] = true;
            if (mc[y] == 0 || dfs(mc[y])) {
                mc[y] = x;
                mc[x] = y;
                return true;
            }
        }
    }
    return false;
}

int getAnswer(vector<vector<int>> value, int n) {
    cnt = 0;
    int count = 0;
    for (int i = 1; i < 2 * n + 1; i ++) {
        ihead[i] = 0;
        mc[i] = 0;
    }
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            if (value[i - 1][j - 1] == 1) {
                add(i, j + n);
//                add(j + n, i);
//                add(j, i);
            }
        }
    }
    for (int i = 1; i < n + 1; i ++) {
        if (!mc[i]) {
            for (int j = 1; j < N; j++) {
                visited[j] = false;
            }
            if (dfs(i)) {
                count++;
            }
        }
    }
    return count;
}

int main(int argc, const char * argv[]) {
    int n;
    scanf("%d", &n);
//    vector<vector<int>> value(n, vector<int>(n));
    vector<vector<int>> value;
    for (int i = 0; i < n; i++) {
        vector<int> t;
        for (int j = 0; j < n; j ++) {
            int m;
            scanf("%d", &m);
            t.push_back(m);
//            value[i][j] = m;
        }
        value.push_back(t);
    }
    printf("%d\n", getAnswer(value, n));
    return 0;
}
