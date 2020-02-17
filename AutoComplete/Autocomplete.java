
import edu.princeton.cs.algs4.MergeX;

public class Autocomplete {
    public Term[] list;
    
    public Autocomplete(Term[] terms) 
    {
        if(terms == null) 
        {
            throw new NullPointerException();
        }
        
        this.list = terms;
        
        MergeX.sort(list);
    }
    
    public Term[] allMatches(String prefix) 
    {
        int i = 0;
        
        if(prefix == null) 
        {
            throw new NullPointerException();
        }
        
        Term myTerm = new Term(prefix, 0);
        
        //get first and last index of key
        int firstIndex = BinarySearchDeluxe.firstIndexOf(list, myTerm, Term.byPrefixOrder(prefix.length()));
        int lastIndex = BinarySearchDeluxe.lastIndexOf(list, myTerm, Term.byPrefixOrder(prefix.length()));
        
        int range = lastIndex - firstIndex;
        
        int j = firstIndex;
        
        //create new list
        Term[] newList = new Term[range+1];
    
        //copy keys to new list
        while(j <= lastIndex) 
        {
           newList[i] = list[j];
           i++;
           j++;
        }
        
        //sort by reverse weight order
        MergeX.sort(newList, Term.byReverseWeightOrder());
        
        
        return newList;
    }
    
    public int numberOfMatches(String prefix) 
    {
        if(prefix == null) 
        {
            throw new NullPointerException();
        }
        
        Term myTerm = new Term(prefix,0);
        
        int firstIndex = BinarySearchDeluxe.firstIndexOf(list, myTerm, Term.byPrefixOrder(myTerm.query.length()));
        int lastIndex = BinarySearchDeluxe.lastIndexOf(list, myTerm, Term.byPrefixOrder(myTerm.query.length())); 
        
        int range = lastIndex - firstIndex;

        return range;
    }
    
    public static void main(String[] args) {

        // read in the terms from a file
        String filename = args[0];
        In in = new In(filename);
        int N = in.readInt();
        Term[] terms = new Term[N];
        for (int i = 0; i < N; i++) {
            long weight = in.readLong();           // read the next weight
            in.readChar();                         // scan past the tab
            String query = in.readLine();          // read the next query
            terms[i] = new Term(query, weight);    // construct the term
        }

        // read in queries from standard input and print out the top k matching terms
        int k = Integer.parseInt(args[1]);
        Autocomplete autocomplete = new Autocomplete(terms);
        while (StdIn.hasNextLine()) {
            String prefix = StdIn.readLine();
            Term[] results = autocomplete.allMatches(prefix);
            for (int i = 0; i < Math.min(k, results.length); i++)
                StdOut.println(results[i]);
        }
    }

}
