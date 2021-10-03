# Reverse First K Elements In A Queue

> **Explanation :**
* In this exercise we will be given a queue of integer numbers and a number upto which we have to reverse the numbers nside the queue.

> **Code Execution :**

* Firstly we will push the element in queue one by one.

* Now we will choose upto which first element we have to reverse the element of queue.[Let it be number k]

* Now we will make a "reverse" function and in reverse function we will make a stack in which we will push the front element of queue on by one to for k times.

* Now as we know stack follows LIFO methodology, therefore element in the stack will get reversed.

* Now we will push these reverse element in the queue again until stack got empty.

* And now we will push the element of queue which were after the k index one by one.

* This will result into reversed first element queue.

