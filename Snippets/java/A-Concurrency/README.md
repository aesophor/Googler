# Java Concurrency Test

From Chapter 6 Memory and Concurrency of **Java in a Nutshell: A Quick Desktop Reference** by Benjamin. J. Evans & David Flanagan:
```
Acquiring the monitor does not prevent access to the object. 
It only prevents any other thread from claiming the lock.
```
```
If a synchronized method is working on an object and has
placed it into an illegal state, and another method
(which is not synchronized) reads from the object
it can still see the inconsistent state.
```

Making Account::getBalance a synchronized method will prevent other threads from seeing the account's inconsistent state.

### Test Result (non-thread-safe)
```
The balance should be: 995.0 now.
Reading balance without synchronization: 1000.0
Reading balance without synchronization: 995.0
The balance should be: 990.0 now.
Reading balance without synchronization: 995.0
Reading balance without synchronization: 990.0
The balance should be: 985.0 now.
Reading balance without synchronization: 985.0
The balance should be: 980.0 now.
The balance should be: 975.0 now.
BUILD SUCCESSFUL (total time: 25 seconds)
```


### Test Result (thread-safe)
```
The balance should be: 995.0 now.
Reading balance without synchronization: 995.0
The balance should be: 990.0 now.
Reading balance without synchronization: 990.0
The balance should be: 985.0 now.
Reading balance without synchronization: 985.0
The balance should be: 980.0 now.
Reading balance without synchronization: 980.0
The balance should be: 975.0 now.
Reading balance without synchronization: 975.0

BUILD SUCCESSFUL (total time: 25 seconds)
```
