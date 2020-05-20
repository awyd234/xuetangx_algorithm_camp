//
//  main.cpp
//  practice_1_3_2_roadUpdate
//
//  Created by Admin on 2020/5/15.
//

#include <iostream>
#include <vector>

using namespace std;

const int N = 500005;

const int SZ = 1 << 20;
struct fastio{   //fast io
    char inbuf[SZ];
    char outbuf[SZ];
    fastio(){
        setvbuf(stdin,inbuf,_IOFBF,SZ);
        setvbuf(stdout,outbuf,_IOFBF,SZ);
    }
}io;

struct UnionSet {
    int f[N];
    
    void init(int n) {
        for (int i = 1; i <= n; i++) {
            f[i] = i;
        }
    }
    
    int find(int x) {
        if (f[x] == x) {
            return x;
        }
        f[x] = find(f[x]);
        return f[x];
    }
    
    bool merge(int x, int y) {
        int findX = find(x);
        int findY = find(y);
        if (findX == findY) {
            return false;
        }
        f[findX] = findY;
        return true;
    }
} us;


vector<int> getAnswer(int n, int m, vector<int> vectorU, vector<int> vectorV) {
    vector<int> ans;
    us.init(n);
    for (int i = m - 1; i >= 0; i--) {
        if (us.merge(vectorU[i], vectorV[i])) {
            ans.push_back(i + 1);
        }
    }
    for (int i = 0; i < ans.size() / 2; i++) {
        swap(ans[i], ans[ans.size() - i - 1]);
    }
    return ans;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    int n, m;
    vector<int> vectorU, vectorV;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        vectorU.push_back(u);
        vectorV.push_back(v);
    }
    vector<int> ans = getAnswer(n, m, vectorU, vectorV);
    printf("%d\n", int(ans.size()));
    for (int i = 0; i < (ans.size()); i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
