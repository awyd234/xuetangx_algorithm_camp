//
//  main.cpp
//  practice_1_2_queue
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

typedef struct treeNode{
    int value;
    treeNode* left;
    treeNode* right;
} treeNode, *tree;

using namespace std;
#define MAX_SIZE 100010

void preTraverse(tree thisTree) {
    if (!thisTree) {
        return;
    }
    cout << thisTree->value << " ";
    preTraverse(thisTree->left);
    preTraverse(thisTree->right);
}

void postTraverse(tree thisTree) {
    if (!thisTree) {
        return;
    }
    postTraverse(thisTree->left);
    postTraverse(thisTree->right);
    cout << thisTree->value << " ";
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int num, nodeValue;
    cin >> num;
    cin >> nodeValue;
    tree myTree = (tree)malloc(sizeof(treeNode));
    myTree->value = nodeValue;
    myTree->left = NULL;
    myTree->right = NULL;
    num --;
    while (num --) {
        cin >> nodeValue;
        treeNode *thisNode = (tree)malloc(sizeof(treeNode));
        treeNode *pNode = myTree;
        thisNode->value = nodeValue;
        thisNode->left = NULL;
        thisNode->right = NULL;
        while (true) {
            if (nodeValue > pNode->value) {
                if (pNode->right) {
                    pNode = pNode->right;
                } else {
                    pNode->right = thisNode;
                    break;
                }
            } else if (nodeValue < pNode->value) {
                if (pNode->left) {
                    pNode = pNode->left;
                } else {
                    pNode->left = thisNode;
                    break;
                }
            }
        }
    }
    preTraverse(myTree);
    cout << endl;
    postTraverse(myTree);
    cout << endl;
    return 0;
}

