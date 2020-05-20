//
//  main.cpp
//  practice_2_1_2_group
//
//  Created by Admin on 2020/5/20.
//

#include <iostream>
#include <vector>
#include <queue>

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

bool check(long long d, int n, int m, vector<int> &a) {
    long long sum = 0;
    int cnt = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] > d) {
            return false;
        }
        sum += a[i];
        if (sum > d) {
            cnt += 1;
            sum = a[i];
        }
    }
    return cnt <= m;
}

long long getAnswer(int n, int m, vector<int> a) {
    long long l = 1, r = 0;
    for (int i = 0; i < n; i++) {
        r += a[i];
    }
    while (l <= r) {
        long long mid = (l + r) >> 1;
        if (check(mid, n, m, a)) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return r + 1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> value;
    for (int i = 0; i < n; i++) {
        int input;
        scanf("%d", &input);
        value.push_back(input);
    }
    printf("%lld\n", getAnswer(n, m, value));
    return 0;
}
