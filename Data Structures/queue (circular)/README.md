# Circular Queue (Circular Buffer, Ring Buffer)
* A circular buffer, circular queue, cyclic buffer or ring buffer is a data structure that uses a single, **fixed-size** buffer as if it were **connected end-to-end**.

* The usefulness of a circular buffer is that it does not need to have its elements shuffled around when one is consumed.
  * circular buffer is well-suited as a FIFO buffer
  * non-circular buffer is well suited as a LIFO buffer.

## How it works
```
     0 1 2 3 4
     a b c d -
tail         ^
head ^
```

* **tail** points to the next position to **write**
* **head** points to the next position to **read**
* initialize tail = 0, head = 0
* **empty** : **tail == head**
* **full** : **tail.next == head**

## Resources
* https://www.youtube.com/watch?v=GbBrp6K7IvM


## Result
```
0. CircularQueue<int> q;
     0 1 2 3 4
     0 0 0 0 0
tail ^         
head ^
-------------------------------
1. q.push(3);
     0 1 2 3 4
     3 0 0 0 0
tail   ^       
head ^         
-------------------------------
2. q.push(5);
     0 1 2 3 4
     3 5 0 0 0
tail     ^     
head ^         
-------------------------------
3. q.push(4);
     0 1 2 3 4
     3 5 4 0 0
tail       ^   
head ^         
-------------------------------
4. q.push(2);
     0 1 2 3 4
     3 5 4 2 0
tail         ^ 
head ^         
-------------------------------
5. q.push(1);
     0 1 2 3 4
     3 5 4 2 1
tail ^         
head   ^       
-------------------------------
6. q.push(6);
     0 1 2 3 4
     6 5 4 2 1
tail   ^       
head     ^     
-------------------------------
7. q.pop();
     0 1 2 3 4
     6 5 4 2 1
tail   ^       
head       ^   
-------------------------------
8. q.pop();
     0 1 2 3 4
     6 5 4 2 1
tail   ^       
head         ^ 
-------------------------------
9. q.push(6);
     0 1 2 3 4
     6 6 4 2 1
tail     ^     
head         ^
```
