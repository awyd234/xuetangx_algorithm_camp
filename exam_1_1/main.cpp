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

void getAnswer(queue<int> value, int n) {
    queue<int> ans;
    while (!value.empty()) {
        int thisValue = value.front();
        value.pop();
        if (ans.empty() || value.front() <= ans.back()) {
            ans.push(thisValue);
        } else {
            value.push(b )
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    queue<int> value;
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) {
        int num;
        scanf("%d", &num);
        value.push_back(num);
        getAnswer(value, n);
    }
    return 0;
}
