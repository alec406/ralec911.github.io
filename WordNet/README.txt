/******************************************************************************
 *  Name: Alec Richardson  
 *
 *  Hours to complete assignment (optional): 20+
 *
 *  NOTE: LATE PASS WAS USED
 ******************************************************************************/

Programming Assignment 3: WordNet


/******************************************************************************
 *  Describe concisely the data structure(s) you used to store the 
 *  information in synsets.txt. Why did you make this choice?
 *****************************************************************************/
I used two symbol tables. One that used the word as a key and the other used the
ID as the key. This was to make it easy to access a word given the ID or the noun.
For the one that used the word as a key, I used a queue as the value. This
was to deal with the fact that words could appear in multiple vertices. Therefore, it was
necessary to create a queue that could hold the different ID's that the same word may be 
pointing to. I then stored the nouns as vertices on a digraph.


/******************************************************************************
 *  Describe concisely the data structure(s) you used to store the 
 *  information in hypernyms.txt. Why did you make this choice?
 *****************************************************************************/
I used a digraph to store the information in hypernyms.txt. It stored the information
as edges that conncected related words. I made this choice because the edges represent
a relationship between 2 words(vertex).


/******************************************************************************
 *  Describe concisely the algorithm you use in the constructor of
 *  ShortestCommonAncestor to check if the digraph is a rooted DAG.
 *  What is the order of growth of the worst-case running times of
 *  your algorithms as a function of the number of vertices V and the
 *  number of edges E in the digraph?
 *****************************************************************************/

Description: I left that part incomplete.



Order of growth of running time:


/******************************************************************************
 *  Describe concisely your algorithm to compute the shortest common
 *  ancestor in ShortestCommonAncestor. For each method, what is the order of
 *  growth of the worst-case running time as a function of the number of
 *  vertices V and the number of edges E in the digraph? For each method,
 *  what is the order of growth of the best-case running time?
 *
 *  If you use hashing, you should assume the uniform hashing assumption
 *  so that put() and get() take constant time.
 *
 *  Be careful! If you use a BreadthFirstDirectedPaths object, don't
 *  forget to count the time needed to initialize the marked[],
 *  edgeTo[], and distTo[] arrays.
 *****************************************************************************/

Description: I ran a breadth first search for each of the nouns and stored the
information in a marked[] and distTo[] array. I then used a for loop to iterate through
all the vertices in the graph. I had an int variable called dist that I would compare against
the sum of distToV[i] + distToW[i]. If disToV[i] + distToW[i] was less than the dist, that 
value was assigned to dist and i was assigned to ancestor because it was the shortest path seen yet.
Once I finished iterating through all the vertices, the shortest distance was stored as dist and 
the sca was stored as ancestor. 

                                              running time
method                               best case            worst case
------------------------------------------------------------------------
length(int v, int w)                    V^4                 V^4(E+V)

ancestor(int v, int w)                  V^4                 V^4(E+V)

length(Iterable<Integer> v,             V^4                 V^4(E+V)
       Iterable<Integer> w)

ancestor(Iterable<Integer> v,           V^4                 V^4(E+V)
         Iterable<Integer> w)




/******************************************************************************
 *  Known bugs / limitations.
 *****************************************************************************/
I failed to check if it was a rooted DAG. I also instantiated arrays within the ancestor
and length methods causing their runtime to be slower than desired.

/******************************************************************************
 *  Describe whatever help (if any) that you received.
 *  Don't include readings, lectures, but do include any 
 *  help from people (including course staff, TAs,
 *  classmates, and friends) and attribute them by name.
 *****************************************************************************/
I talked concepts with Andrew Owen.

/******************************************************************************
 *  Describe any serious problems you encountered.                    
 *****************************************************************************/
I kept getting a null pointer exception when I'd run Outcast. So I used the debugger and
figured out that many nouns weren't showing up in the graph. After some intensive debugging,
I realized that when reading in the synset file, I needed to split the synset part with spaces
because there were multiple synonyms of the word. For example, my program was giving a null
pointer exception when it tried to read in horse because in my symbol table I had horse Equus_cabllus
stored as one word. I needed to split those by spaces and store them as seperate words. This took
me a very long time to resolve.

I was also originally using only one symbol table. I realized it would be easier if I had two. One 
using the noun as the key and one using the id as the key. This allowed me to access either the noun or id
no matter what the key was. This didn't take me quite as long to figure out but it was still a hurdle.

I also had a hard time with the shortest ancestor path. I was trying to determine a way to not initilize the
arrays inside the methods but I ended up giving up on it. I also was trying to determine a way to only use 
one marked[] array and one distance[] array but I ended up using 2 for each argument. This led to my runtime
being longer than desired.


/******************************************************************************
 *  List any other comments here. Feel free to provide any feedback   
 *  on how much you learned from doing the assignment, and whether    
 *  you enjoyed doing it.                                             
 *****************************************************************************/