//
//  main.cpp
//  practice_2_3_1_minExchange
//
//  Created by Admin on 2020/5/22.
//

#include <iostream>
#include <vector>

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

vector<int> value;
vector<int> l;

long mergeSort(int lo, int hi) {
    long thisAns = 0;
    if (1 == hi - lo) {
        return 0;
    }
    int mid = (lo + hi) >> 1;
    thisAns += mergeSort(lo, mid);
    thisAns += mergeSort(mid, hi);
    int frontIndex = lo, backIndex = mid;
//    int lIndex = 0;
    
    for (int i = lo; i < hi; i ++) {
        if (backIndex == hi || (frontIndex < mid && value[frontIndex] < value[backIndex])) {
            l[i - lo] = value[frontIndex++];
        } else {
            l[i - lo] = value[backIndex++];
            thisAns += (mid - frontIndex);
        }
    }
    
//    while (frontIndex < mid && backIndex < hi) {
//        if (value[frontIndex] < value[backIndex]) {
//            l[lIndex] = value[frontIndex];
//            frontIndex += 1;
//        } else {
//            l[lIndex] = value[backIndex];
//            backIndex += 1;
//            thisAns += (mid - frontIndex);
//        }
//        lIndex += 1;
//    }
//    while (frontIndex < mid) {
//        l[lIndex] = value[frontIndex];
//        frontIndex += 1;
//        lIndex += 1;
//    }
//
//    while (backIndex < hi) {
//        l[lIndex] = value[backIndex];
//        backIndex += 1;
//        lIndex += 1;
//    }
    
    for (int i = lo; i < hi; i++) {
        value[i] = l[i - lo];
    }
    return thisAns;
}

long getAnswer(vector<int> l, vector<int> value, int n) {
    ::value = value;
    ::l = l;
    long ans = mergeSort(0, n);
    return ans;
}

int main(int argc, const char * argv[]) {
    int n;
    vector<int> value;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        l.push_back(0);
    }
    for (int i = 0; i < n; i++) {
        int m;
        scanf("%d", &m);
        value.push_back(m);
    }
    printf("%ld\n", getAnswer(l, value, n));
    return 0;
}
