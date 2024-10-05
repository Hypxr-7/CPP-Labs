Programming Assignment: Autocomplete


/* *****************************************************************************
 *  Describe how your firstIndexOf() method in BinarySearchDeluxe.cpp
 *  finds the first index of a key that is equal to the search key.
 **************************************************************************** */

1. It first finds the mid value from the known high and low
2. It then checks if a[mid] < key and if it is, then it changes low as key is in upper half
3. Similarly, key < a[mid] is true if key is in lower half so high is updated
4. If neither is true, them a[mid] == key, so result is updated with mid and high with mid -1
5. The search continues to check if there is any key in the lower indices
6. Continues while low <= high
7. returns the value of the lowest index if found, else returns -1

/* *****************************************************************************
 *  Identify which sorting algorithm (if any) that your program uses in the
 *  Autocomplete constructor and instance methods. Choose from the following
 *  options:
 *
 *    none, selection sort, insertion sort, mergesort, quicksort, heapsort
 *
 **************************************************************************** */

quicksort


/* *****************************************************************************
 *  How many compares (in the worst case) does each of the operations in the
 *  Autocomplete data type make, as a function of both the number of terms n
 *  and the number of matching terms m? Use Big Theta notation to simplify
 *  your answers.
 *
 *  Recall that with Big Theta notation, you should discard both the
 *  leading coefficients and lower-order terms, e.g., Theta(m^2 + m log n).
 **************************************************************************** */

Autocomplete():     Theta(n.log n)

allMatches():       Theta(m.log m + log n)

numberOfMatches():  Theta(log n)

/* *****************************************************************************
 *  Known bugs / limitations.
 **************************************************************************** */

Not any that I know of

/* *****************************************************************************
 *  Describe any serious problems you encountered.                    
 **************************************************************************** */

No serious problems
Needed to modify the given main to handle command line arguments properly

/* *****************************************************************************
 *  List any other comments here. Feel free to provide any feedback   
 *  on how much you learned from doing the assignment, and whether    
 *  you enjoyed doing it.                                             
 **************************************************************************** */

N/A
