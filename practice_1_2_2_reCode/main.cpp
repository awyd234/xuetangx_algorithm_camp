//
//  main.cpp
//  practice_1_2_2_reCode
//
//  Created by Admin on 2020/5/10.
//

#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <stack>

using namespace std;

#define MAX_SIZE 5010;

const int SZ = 1 << 20;
struct fastio{   //fast io
    char inbuf[SZ];
    char outbuf[SZ];
    fastio(){
        setvbuf(stdin,inbuf,_IOFBF,SZ);
        setvbuf(stdout,outbuf,_IOFBF,SZ);
    }
}io;

typedef long long ll;

priority_queue<ll, vector<ll>, greater<ll>> pq;

ll getAnswer() {
    ll sum = 0;
    while (pq.size() > 1) {
        ll newEle = 0;
        for (int k = 0; k < 2; k ++) {
            newEle = newEle + pq.top();
            pq.pop();
        }
        sum += newEle;
        pq.push(newEle);
    }
    return sum;
}

int main(int argc, const char * argv[]) {
    // insert code here...
//#ifndef  _OJ_
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//#endif // ! _OJ_
    int num;
    ll x;
    
    scanf("%d", &num);
    while (num --) {
        scanf("%lld", &x);
        pq.push(x);
    }
    
    printf("%lld\n", getAnswer());
    
    return 0;
}

