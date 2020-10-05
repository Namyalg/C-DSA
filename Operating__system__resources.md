DUAL MODE OF OPERATION

1. Multiprogramming, 2 .multiprocessing, 3.multitasking, 4.multithreading

1. More than one task needs to be executed, IO bound more preference than CPU bound, context switching occurs
2. More than 1 physical CPU, like mine has 2 cores, also encompasses the elements of multiprogramming
3. An extension of multi-programming but the point being there is a strict element of time-slicing so ensuring each task is given a fair chance/time to execute
4. Multiple threads to execute a task

https://www.geeksforgeeks.org/difference-between-multitasking-multithreading-and-multiprocessing/#:~:text=Multiprogramming%20%E2%80%93%20A%20computer%20running%20more,is%20an%20extension%20of%20multitasking.


- http://www2.cs.uregina.ca/~hamilton/courses/330/notes/introduction/introduction.html#:~:text=Dual%2Dmode%20operation%20forms%20the,access%20all%20areas%20of%20memory.

Explanation of the exact dual mode of operation and what it is and why it is needed
- Trap or interrupts always go to the same place in the interrupt vector after which it is mapped to the place where it was called from
- http://boron.physics.metu.edu.tr/ozdogan/OperatingSystems/ceng328/node48.html

