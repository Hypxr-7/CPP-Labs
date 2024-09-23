Assignment 1: Deques and Randomized Queues


/* *****************************************************************************
 *  Explain briefly how you implemented the randomized queue and deque.
 *  Which data structure did you choose (array, linked list, etc.)
 *  and why?
 **************************************************************************** */

For the Deque I used a doubly linked list as we needed to remove and add elements to both end of the data structure and having two pointer (front and rear) to performed this seemed intuitive and more feasible than using an array.

For the RandomizedQueue I used a resizable array primarily due to the fact that we needed to remove an element at random. Using a linked list for this would mean that I would have to traverse the list to get to the element that I need to remove. On the other hand, using an array allowed me to have a constant time for accessing and removing that random element.

/* *****************************************************************************
 *  How much memory (in bytes) do your data types use to store n items
 *  in the worst case? Use the 64-bit memory cost model from Section
 *  1.4 of the textbook and use tilde notation to simplify your answer.
 *  Briefly justify your answers and show your work.
 *
 *  Do not include the memory for the items themselves (as this
 *  memory is allocated by the client and depends on the item type)
 *  or for any iterators, but do include the memory for the references
 *  to the items (in the underlying array or linked list).
 **************************************************************************** */

Randomized Queue:   ~  0  bytes (Due to an array there is no need for extra pointers)

Deque:              ~  16n  bytes (8 bytes for 2 new pointers per element)




/* *****************************************************************************
 *  Known bugs / limitations.
 **************************************************************************** */
Not any that I am aware of


/* *****************************************************************************
 *  Describe any serious problems you encountered.                    
 **************************************************************************** */
N/A


/* *****************************************************************************
 *  List any other comments here. Feel free to provide any feedback   
 *  on how much you learned from doing the assignment, and whether    
 *  you enjoyed doing it.                                             
 **************************************************************************** */
This was a very fun and educative assignment and more assignments like this would be more helpful for the students 