
import java.util.Arrays;
import java.util.Comparator;

public class Term implements Comparable<Term>{
    String query;
    long weight;
    
    public Term(String query, long weight) 
    {
        if(query == null) 
        {
            throw new NullPointerException();
        }
        
        if(weight < 0) 
        {
            throw new IllegalArgumentException();
        }
        
        this.query = query;
        this.weight = weight;
    }
    
    public static Comparator<Term> byReverseWeightOrder()
    {
        return new Comparator<Term>()
        {
            public int compare(Term arg0, Term arg1) 
            {
                if(arg0.weight < arg1.weight) 
                {
                    return 1;
                }
                else if(arg0.weight == arg1.weight) 
                {
                    return 0;
                }
                else 
                {
                    return -1;
                }
            }
            
        };
    }
    
    public static Comparator<Term> byPrefixOrder(int r)
    {
        if(r < 0) 
        {
            throw new IllegalArgumentException();
        }
        
        final int rr = r;
        return new Comparator<Term>() 
        {
            public int compare(Term one, Term two) 
            {
                String compare1;
                String compare2;
                       
                compare1 = one.query.substring(0, rr);        
                compare2 = two.query.substring(0,rr);
                
                return compare1.compareTo(compare2);
            }
        };
        
    }
    
    @Override
    public int compareTo(Term that) {
        String query1 = this.query;
        String query2 = that.query;
        return query1.compareTo(query2);
    }
    
    public String toString() 
    {
        return weight + "   " + query;
    }
    
    public static void main(String[] args) 
    {
        Term[] terms = {new Term("Debbie", 3), new Term("Abcd", 8), new Term("Cathy", 1), new Term("Cat", 1)};
        for (Term term : terms) System.out.println(term);
        System.out.println();
        
        Arrays.sort(terms, Term.byReverseWeightOrder());
        for (Term term : terms) System.out.println(term);
        System.out.println();
        
        Arrays.sort(terms, Term.byPrefixOrder(4));
        for (Term term : terms) System.out.println(term);
        System.out.println();
        
        Arrays.sort(terms);
        for (Term term : terms) System.out.println(term);
    }

}
