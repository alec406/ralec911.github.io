/*
 * Used Late Pass on this assignment
 */
import edu.princeton.cs.algs4.Digraph;
import edu.princeton.cs.algs4.LinearProbingHashST;
import edu.princeton.cs.algs4.Queue;

public class WordNet {

    private LinearProbingHashST<String, Queue<Integer>> wordKey;
    private LinearProbingHashST<Integer, String> idKey;
    private Digraph g;
    private ShortestCommonAncestor sca;
        
    public WordNet(String synsets, String hypernyms) 
    {
        if(synsets == null || hypernyms == null) 
        {
            throw new NullPointerException();
        }
        
        wordKey = new LinearProbingHashST<String, Queue<Integer>>();
        idKey = new LinearProbingHashST<Integer, String>();


        //synsets
        In synsetsIn = new In(synsets);     
        int numVertices = 0;

                
        while(synsetsIn.hasNextLine()) 
        {
            String[] syn = synsetsIn.readLine().split(",");
            int synId = Integer.parseInt(syn[0]);
            String[] nouns = syn[1].split(" ");
            
            for(int i= 0; i < nouns.length; i++) 
            {
                String word = nouns[i];
            	
            	if(wordKey.contains(word)) 
                {
                    wordKey.get(word).enqueue(synId);;
                }
                else 
                {
                    Queue<Integer> myQueue = new Queue<Integer>();
                    myQueue.enqueue(synId);
                    wordKey.put(word, myQueue);
                }
          
            //wordKey.put(word, synId);
            idKey.put(synId, word);
            numVertices++;
            }
        }
        
        g = new Digraph(numVertices);
        
        //hypernyms
        In hyperIn = new In(hypernyms);
        
        while (hyperIn.hasNextLine())
        {
            String[] hyper = hyperIn.readLine().split(",");
            int hyperId = Integer.parseInt(hyper[0]);
            for(int i = 1; i < hyper.length; i++) 
            {
                int id = Integer.parseInt(hyper[i]);
            	g.addEdge(hyperId, id);
            }
        }
        
        sca = new ShortestCommonAncestor(g);
        
        
    }
    
    public Iterable<String> nouns()
    {
        return wordKey.keys();
        
    }
    
    public boolean isNoun(String word) 
    {
        if(word == null) 
        {
            throw new NullPointerException();
        }
        
        return wordKey.contains(word);
        
    }
    
    public String sca(String noun1, String noun2) 
    {
        if(noun1 == null || noun2 == null) 
        {
            throw new NullPointerException();
        }
        
        if(isNoun(noun1) == false || !isNoun(noun2) == false) 
        {
        	throw new IllegalArgumentException();
        }
                
        Iterable<Integer> a, b;
        
        a = wordKey.get(noun1);
        b = wordKey.get(noun2);

        
        int scaID = sca.ancestor(a, b);
        
        return idKey.get(scaID);
    }
    
    public int distance(String noun1, String noun2) 
    {
        if(noun1 == null || noun2 == null) 
        {
            throw new NullPointerException();
        }
        
        if(isNoun(noun1) == false || isNoun(noun2) == false) 
        {
        	throw new IllegalArgumentException();
        }
        
        Iterable<Integer> a, b;

        
        a = wordKey.get(noun1);
        b = wordKey.get(noun2);

        
        int length = sca.length(a, b);
        return length;
    }
    
    public static void main(String[] args) {
        
        WordNet wordnet = new WordNet(args[0], args[1]);
        StdOut.println(wordnet.sca("acquired_immune_deficiency_syndrome", "terrace")); 
        StdOut.println(wordnet.distance("acquired_immune_deficiency_syndrome", "terrace")); 
        StdOut.println(wordnet.isNoun("horse"));
    }

}
