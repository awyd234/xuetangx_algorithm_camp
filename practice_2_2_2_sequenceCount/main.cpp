//
//  main.cpp
//  practice_2_2_2_sequenceCount
//
//  Created by Admin on 2020/5/21.
//

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

const int N = 300005;

const int SZ = 1 << 20;
struct fastio{   //fast io
    char inbuf[SZ];
    char outbuf[SZ];
    fastio(){
        setvbuf(stdin,inbuf,_IOFBF,SZ);
        setvbuf(stdout,outbuf,_IOFBF,SZ);
    }
}io;

int n, d;
vector<int> value;
int maxValue[N], minValue[N];

int cal(vector<int> value, int l, int r, int mid) {
    return 0;
}

int min(int x, int y) {
    return x <= y? x : y;
}

int max(int x, int y) {
    return x >= y? x : y;
}

long long solve(int lo, int hi) {
    if (lo == hi) {
        return 0;
    }
    int mid = (lo + hi) >> 1;
    long long ans = solve(lo, mid) + solve(mid + 1, hi);
    for (int i = mid + 1; i <= hi; i++) {
        minValue[i] = (i == mid + 1) ? value[i] : min(minValue[i - 1], value[i]);
        maxValue[i] = (i == mid + 1) ? value[i]: max(maxValue[i - 1], value[i]);
    }
    int mn = 0, mx = 0, pos = hi;
    for (int i = mid; i >= lo && pos > mid; --i) {
        mn = (i == mid) ? value[i]:min(mn, value[i]);
        mx = (i == mid) ? value[i]:max(mx, value[i]);
        for (; pos > mid && max(mx, maxValue[pos]) - min(mn, minValue[pos]) > d; --pos) {
            
        }
        ans += pos - mid;
    }
    return ans;
}

long long getAnswer(int n, int d) {
    ::n = n;
    ::d = d;
//    ::value = value;
    return solve(0, n - 1);
}

int main(int argc, const char * argv[]) {
    int n, d;
    scanf("%d %d", &n, &d);
    for (int i = 0; i < n; i++) {
        int m;
        scanf("%d", &m);
        value.push_back(m);
    }
    printf("%lld\n", getAnswer(n, d));
    return 0;
}
