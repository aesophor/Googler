#!/usr/bin/env python3

class Node:
    def __init__(self):
        self.next = None
        self.data = None

    def __str__(self):
        return self.data


class CircularBuffer:
    """ In this implementation of Circular Buffer,
    when the buffer is empty, head = tail
    when the buffer is full, (tail + 1) % size = head
    """
    def __init__(self, size: int):
        self.buffer = [0] * size
        self.head = 0
        self.tail = 0
        self.size = size

    def enqueue(self, data):
        self.buffer[self.tail] = data
        if self.full():
            self._increment_head()
        self._increment_tail()
        self.buffer[self.tail] = 0
        #print(self.__str__())

    def dequeue(self):
        if self.empty():
            return None
        data = self.buffer[self.head]
        self.buffer[self.head] = 0
        self._increment_head()
        return data

    def empty(self):
        return self.head == self.tail

    def full(self):
        return (self.tail + 1) % self.size == self.head

    def _increment_head(self):
        self.head = (self.head + 1) % self.size

    def _increment_tail(self):
        self.tail = (self.tail + 1) % self.size

    def __str__(self):
        return self.buffer.__str__() + " head=" + str(self.head) + "; tail=" + str(self.tail)


if __name__ == '__main__':
    c = CircularBuffer(5)
    c.enqueue(1)
    c.enqueue(2)
    c.enqueue(3)
    c.enqueue(4)
    c.enqueue(5)
    c.enqueue(6)
    c.enqueue(7)
    c.dequeue()
    print(c)
