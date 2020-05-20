//
//  main.cpp
//  practice_1_1_1
//
//  Created by Admin on 2020/5/10.
//

#include <iostream>

const int SZ = 1 << 20;
struct fastio {    // Ê¹ÓÃÁËProgramCaiCaiÌá¹©µÄIOÍâ¹Ò
    char inbuf[SZ];
    char outbuf[SZ];
    fastio() {
        setvbuf(stdin, inbuf, _IOFBF, SZ);
        setvbuf(stdout, outbuf, _IOFBF, SZ);
    }
}io;

using namespace std;
#define MAX_SIZE 100010

int main(int argc, const char * argv[]) {
    // insert code here...
    string myStack[MAX_SIZE];
    int topIndex = 0;
    int num;
    int opSelector;
    string opChar;
    int opNum;
    cin >> num;
    while (num --) {
        cin >> opSelector;
        switch (opSelector) {
            case 1:
                cin >> opChar;
                myStack[topIndex++] = opChar;
                break;

            case 2:
                cout << myStack[--topIndex] << endl;
                break;
                
            case 3:
                cin >> opNum;
                cout << myStack[opNum - 1] << endl;
                break;
                
            default:
                break;
        }
    }
    return 0;
}
