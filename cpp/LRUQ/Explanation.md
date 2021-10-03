# Least Recently Used Queue Problem

> **Explanation :**

* In this exercises we will be given a list of numbers or array of numbers.

* We have to insert these numbers in a cache memory having a fixed size and access numbers stored in cache memory.

* In most case the size of the or the capacity of the cache memory will be lower then the element in list.
    * Example: Suppose there are 7 elements in out list but capacity of our cache memory is only to hold 3 elememts at a time. Therefore to insert the 4th element in cache memory we have to delete the LEAST RECENTLY USED ELEMENT.

    * The LEAST RECENTLY USED element in the cache memory among the 3 element will be the element which was inserted first and that is the oldest element in the cache memory.
* Therefore we will delete that LEAST RECENTLY USED element from the rear of the cache memory and insert the newest element from the list in the front of cache memmory.

* If the element from the list which is to be inserted in cache memory is already present in the cache memory but at rear position we will change its position to front of the cache memory.

* In the exercise we have to access the last 3 element remain in the cache memory.

> **Code Execution :**

* Firstly we make a list of integer numbers.

* Then we will make a unordered map which will have integer value as the key and elements of the above list as reference of the key.
* Then we will check whether the cache is full or not if empty : 

    * Then we will push 3 elements of the list in cache memory 1 by 1.


* If the cache is full :
    * Then we will check whether the entring element is already present in the cache or not.

    * If not present then we will delete the rear element and add the new element in the front of the list.

    * If present then we will change the position of the element present in the cache to front.

* Later we will traverse and diplay the remaining element in the cache memory.



