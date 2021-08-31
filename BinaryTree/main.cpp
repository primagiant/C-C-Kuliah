#include <iostream>

#include "BT.cpp"
using namespace std;

int main(int argc, char const *argv[]) {
    BinaryTree bt;

    bt.insert(100);
    bt.insert(87);
    bt.insert(102);
    bt.insert(67);
    bt.insert(10);
    bt.insert(105);
    bt.insert(113);
    bt.insert(124);
    bt.insert(119);

    bt.preOrderTranversal();
    cout << endl;

    bt.inOrderTranversal();
    cout << endl;

    bt.postOrderTranversal();
    cout << endl;

    return 0;
}
