#include <iostream>
#include "LinkedList.h"
using namespace std;

main()
{
     LinkedList list;

     list.addToHead(5);
     list.addToHead(6);
     list.addToHead(3);

     list.printAllElement();

     return 0;
}
