/******************************************************************************
 *  Name: Alec Richardson    
 *
 *  Hours to complete assignment (optional): 18
 *
 ******************************************************************************/

Programming Assignment 3: Autocomplete


/******************************************************************************
 *  Describe how your firstIndexOf() method in BinarySearchDeluxe.java
 *  finds the first index of a key that equals the search key.
 *****************************************************************************/
It first performs as a standard binary search. It looks at the middle point of the list and then decides if the search key is higher or lower
than the midpoint. It then takes the half of the array that contains the key. It continually does this until the key is found. Once the key was
found I had to find the first index of the key. I did this by starting a while loop that decremented until a different value from
the key was found. Once this next value was found, the while loop would end and the first index gets returned.

/******************************************************************************
 *  What is the order of growth of the number of compares (in the
 *  worst case) that each of the operations in the Autocomplete
 *  data type make, as a function of the number of terms n and the
 *  number of matching terms m?
 *
 *  Recall that with order-of-growth notation, you should discard
 *  leading coefficients and lower-order terms, e.g., m^2 + m log n.
 *****************************************************************************/

constructor: NlogN

allMatches(): logN + MlogM 

numberOfMatches(): logN

/******************************************************************************
 *  Known bugs / limitations.
 *****************************************************************************/
With certain words I enter I get a StringOutOfBoundsException. Most of the time it gives me a list of results but I can't figure out
why I get the StringOutOfBoundsException for longer words.

/******************************************************************************
 *  Describe whatever help (if any) that you received.
 *  Don't include readings or lectures, but do include
 *  any help from people (including course staff, lab TAs,
 *  classmates, and friends) and attribute them by name.
 *
 *  Also include any resources (including the web) that you may
 *  may have used in creating your design.
 *****************************************************************************/
I used a youtube video that described the difference of comparators and comparables
https://www.youtube.com/watch?v=oAp4GYprVHM

I also watched a youtube video on what is lexicographic ordering
https://www.youtube.com/watch?v=LtlZtFXe8Io

/******************************************************************************
 *  Describe any serious problems you encountered.                    
 *****************************************************************************/
I had a bug in my binary search that took me quite a while to resolve. I had if comparator.compare(key, a[mid] == 1) 
instead (key, a[mid] > 1). That took me a very long time to resolve. Also, I was getting a StringIndexOutOfBoundsException
when I would enter in bigger words. I wasn't able to resolve this issue.


/******************************************************************************
 *  List any other comments here. Feel free to provide any feedback   
 *  on how much you learned from doing the assignment, and whether    
 *  you enjoyed doing it.                                             
 *****************************************************************************/
I learned quite a bit from this assignment. It helped get familiar with camparable and comparator. It was really challenging but it also felt 
manageable for the most part.
  