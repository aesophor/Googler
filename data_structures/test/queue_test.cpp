#include "queue.cpp"
#include <iostream>

using std::cout;
using std::endl;

int main() {
    Queue<int> queue;
    queue.enqueue(0);
    queue.enqueue(1);
    queue.enqueue(2);
    cout << queue.ToString() << endl;

    queue.dequeue();
    cout << queue.ToString() << endl;

    queue.dequeue();
    queue.dequeue();
    cout << queue.ToString() << endl;

    queue.enqueue(5);
    queue.enqueue(6);
    queue.enqueue(7);
    cout << queue.ToString() << endl;
    cout << "Peeking: " << queue.peek() << endl;
}
