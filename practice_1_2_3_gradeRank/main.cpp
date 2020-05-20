//
//  main.cpp
//  practice_1_2_queue
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

typedef struct StudentScore {
    int index;
    int algorithm;
    int dataStructure;
} StudentScore;

int main(int argc, const char * argv[]) {
    // insert code here...
//#ifndef  _OJ_
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//#endif // ! _OJ_
    int num;
    
    scanf("%d", &num);
    queue<StudentScore> bucketVector[201];
    stack<StudentScore> bucketTotalVector[301];
    vector<int> rank(num * 2, 0);
    
    for (int i = 0; i < num; i ++) {
        int algorithm, dataStructure;
        scanf("%d %d", &algorithm, &dataStructure);
        StudentScore thisStudentScore;
        thisStudentScore.index = i;
        thisStudentScore.dataStructure = dataStructure;
        thisStudentScore.algorithm = algorithm;
        bucketVector[algorithm].push(thisStudentScore);
    }
    
    for (int i = 0; i <= 101; i ++) {
        while (!bucketVector[i].empty()) {
            StudentScore thisStudentScore = bucketVector[i].front();
            bucketVector[i].pop();
            int total = thisStudentScore.algorithm + thisStudentScore.dataStructure;
            bucketTotalVector[total].push(thisStudentScore);
        }
    }
    
    int count = 0;
    for (int i = 201; i >= 0; i --) {
        while (!bucketTotalVector[i].empty()) {
            StudentScore thisStudentScore = bucketTotalVector[i].top();
            printf("%d %d %d %d\n", thisStudentScore.index + 1, thisStudentScore.algorithm + thisStudentScore.dataStructure, thisStudentScore.algorithm, thisStudentScore.dataStructure);
            bucketTotalVector[i].pop();
            rank[count++] = thisStudentScore.index + 1;
        }
    }

    count = 0;
    for (int i = 0; i < num; i++) {
        for (int j = i + 1; j < num; j++) {
            if (rank[i] > rank[j]) {
                count ++;
            }
        }
    }

    printf("%d\n", count);
    
    return 0;
}

