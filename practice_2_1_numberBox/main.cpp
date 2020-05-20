//
//  main.cpp
//  practice_1_2_queue
//
//  Created by Admin on 2020/5/10.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

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

const int MOD = 100003;
vector<ll> table[MOD];

int myHash(ll x) {
    return x % MOD;
}

bool check(int op, ll x) {
    int h = myHash(x);
    vector<ll>::iterator ptr = table[h].end();
    for (vector<ll>::iterator it = table[h].begin(); it != table[h].end(); ++it) {
        if (*it == x) {
            ptr = it;
            break;
        }
    }
    if (op == 1) {
        if (ptr == table[h].end()) {
            table[h].push_back(x);
            return true;
        }
        return false;
    } else {
        if (ptr != table[h].end()) {
            *ptr = table[h].back();
            table[h].pop_back();
            return true;
        }
        return false;
    }
}

set<ll> mySet;
bool check2(int op, ll x) {
    if (op == 1) {
        if (mySet.count(x)) {
            return false;
        } else {
            mySet.insert(x);
            return true;
        }
    } else {
        if (mySet.count(x)) {
            mySet.erase(x);
            return true;
        } else {
            return false;
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
//#ifndef  _OJ_
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//#endif // ! _OJ_
    int num, op;
    ll value;
    scanf("%d", &num);
    while (num --) {
        scanf("%d %lld", &op, &value);
        if (check(op, value)) {
            printf("Succeeded\n");
        } else {
            printf("Failed\n");
        }
    }
    return 0;
}

