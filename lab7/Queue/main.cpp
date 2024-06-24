#include <iostream>
#include <queue>
#include "Queue.cpp"

using namespace std;


int main()
{
    // Queue
    cout << "------Queue------" << endl;
    MyQueue<int> myQueue;
    for (int i = 0; i < 10; i++)
        myQueue.push(i);

    myQueue.showQueue();

    myQueue.pop();
    myQueue.pop();
    myQueue.showQueue();

    cout << myQueue.getSize() << endl;

    myQueue.push(45);
    myQueue.push(34);
    myQueue.push(12);

    myQueue.showQueue();

    cout << myQueue.getTop() << endl;

    myQueue.pop();
    cout << myQueue.getTop() << endl;

    myQueue.pop();
    cout << myQueue.getTop() << endl;

    myQueue.showQueue();

    myQueue.clear();
    cout << std::boolalpha << myQueue.isEmpty() << endl;


    // Queue with priority
    cout << "----Queue with priority----" << endl;

    MyPriorityQueue myPriorityQueue;
    cout << std::boolalpha << myPriorityQueue.isEmpty() << endl;

    myPriorityQueue.push(12, 7);
    myPriorityQueue.push(67, 8);
    myPriorityQueue.push(34, 3);
    myPriorityQueue.push(87, 8);
    myPriorityQueue.push(10, 87);

    myPriorityQueue.showPriorityQueue();

    myPriorityQueue.pop();
    myPriorityQueue.pop();

    cout << myPriorityQueue.getSize() << endl;

    myPriorityQueue.showPriorityQueue();

    myPriorityQueue.push(65, 5);
    myPriorityQueue.push(567, 432);

    myPriorityQueue.showPriorityQueue();

    cout << myPriorityQueue.getTop() << endl;

    myPriorityQueue.pop();
    cout << myPriorityQueue.getTop() << endl;

    myPriorityQueue.pop();
    cout << myPriorityQueue.getTop() << endl;

    myPriorityQueue.showPriorityQueue();

    myPriorityQueue.clear();
    cout << myPriorityQueue.isEmpty() << endl;

    return 0;
}