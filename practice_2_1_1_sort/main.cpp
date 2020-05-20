//
//  main.cpp
//  practice_2_1_1_sort
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

void selectionSort(vector<int> &value, int n) {
    for (int i = n - 1; i >= 0; i --) {
        int maxIndex = i;
        int maxValue = value[i];
        for (int j = i - 1; j >= 0; j--) {
            if (value[j] > maxValue) {
                maxValue = value[j];
                maxIndex = j;
            }
        }
        swap(value[i], value[maxIndex]);
    }
}

void mergeSort(vector<int> &value, int lo, int hi) {
    int mid = (lo + hi) >> 1;
    if (hi - lo == 1) {
        return;
    }
    vector<int> l;
    for (int i = lo; i < hi; i++) {
        l.push_back(value[i]);
    }
    mergeSort(value, lo, mid);
    mergeSort(value, mid, hi);
    int frontIndex = lo, backIndex = mid;
    int lIndex = 0;
    
    while (frontIndex < mid && backIndex < hi) {
        if (value[frontIndex] <= value[backIndex]) {
            l[lIndex] = value[frontIndex];
            frontIndex += 1;
        } else {
            l[lIndex] = value[backIndex];
            backIndex += 1;
        }
        lIndex += 1;
    }
    while (frontIndex < mid) {
        l[lIndex] = value[frontIndex];
        frontIndex += 1;
        lIndex += 1;
    }
    
    while (backIndex < hi) {
        l[lIndex] = value[backIndex];
        backIndex += 1;
        lIndex += 1;
    }
    
    for (int i = lo; i < hi; i++) {
        value[i] = l[i - lo];
    }
}

void quickSort(vector<int> &valu, int n) {
    
}

void heapSort(vector<int> &value, int n) {
    for (int i = 1; i < n)
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    vector<int> value;
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) {
        int m;
        scanf("%d", &m);
        value.push_back(m);
    }
//    selectionSort(value, n);
//    mergeSort(value, 0, n);
    quickSort(value, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", value[i]);
    }
    printf("\n");
    return 0;
}
