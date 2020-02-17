import edu.princeton.cs.algs4.Digraph;
import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.Queue;

public class ShortestCommonAncestor {
    
    private Digraph g;
    private boolean[] markedV;
    private boolean[] markedW;
    private int[] distToV;
    private int[] distToW;
    
    public ShortestCommonAncestor(Digraph g) 
    {
        if(g == null) 
        {
            throw new NullPointerException();
        }
        
        this.g= g;
        
    }
    
    public int length(int v, int w) 
    {        
        if (v < 0 || v > g.V() - 1 || w < 0 || w > g.V() - 1) 
        {
            throw new IndexOutOfBoundsException();
        }
        
    	int dist = -1;
        
        markedV = new boolean[g.V()];
        distToV = new int[g.V()];
        
        markedW = new boolean[g.V()];
        distToW = new int[g.V()];
        
        
        Queue<Integer> path = new Queue<Integer>();
        markedV[v] = true;
        markedW[w] = true;
        
        
        //first path
        path.enqueue(v);
        while (!path.isEmpty()) {
            int x = path.dequeue();
            for (int y : g.adj(x)) {
                if (!markedV[y]) {
                    distToV[y] = distToV[x] + 1;
                    markedV[y] = true;
                    path.enqueue(y);
                }
            }
            
        }
        
        //second path
        
        path.enqueue(w);
        while (!path.isEmpty()) {
            int x = path.dequeue();
            for (int y : g.adj(x)) {
                if (!markedW[y]) {
                    distToW[y] = distToW[x] + 1;
                    markedW[y] = true;
                    path.enqueue(y);
                }
            }
            
        }
        
        
        for(int i = 0; i < g.V(); i++){
                
       	 if (markedV[i] == true && markedW[i] == true) {

        	     if (dist == -1) {
                     dist = distToV[i] + distToW[i];
                 } else if (distToV[i] + distToW[i] < dist) {
                     dist = distToV[i] + distToW[i];
                 }
         }
        }
        return dist;
    }
    
    public int ancestor(int v, int w) 
    {
    	if (v < 0 || v > g.V() - 1 || w < 0 || w > g.V() - 1) 
    	{
            throw new IndexOutOfBoundsException();
    	}
    	
    	int dist = -1;
        int ancestor = -1;
       
    	markedV = new boolean[g.V()];
        distToV = new int[g.V()];
        
        markedW = new boolean[g.V()];
        distToW = new int[g.V()];
        
        
        Queue<Integer> path = new Queue<Integer>();
        markedV[v] = true;
        markedW[w] = true;
        
        
        //first path
        path.enqueue(v);
        while (!path.isEmpty()) {
            int x = path.dequeue();
            for (int y : g.adj(x)) {
                if (!markedV[y]) {
                    distToV[y] = distToV[x] + 1;
                    markedV[y] = true;
                    path.enqueue(y);
                }
            }
            
        }
        
        //second path
        
        path.enqueue(w);
        while (!path.isEmpty()) {
            int x = path.dequeue();
            for (int y : g.adj(x)) {
                if (!markedW[y]) {
                    distToW[y] = distToW[x] + 1;
                    markedW[y] = true;
                    path.enqueue(y);
                }
            }
            
        }
        
        
        for(int i = 0; i < g.V(); i++){
        	 if (markedV[i] == true && markedW[i] == true) {
                 if (dist == -1) {
                     dist = distToV[i] + distToW[i];
                     ancestor = i;
                 } else if (distToV[i] + distToW[i] < dist) {
                     dist = distToV[i] + distToW[i];
                     ancestor = i;
                 } 
                
         }
        	 
        }  
        return ancestor;
    }
    
    public int length(Iterable<Integer> subsetA, Iterable<Integer> subsetB) 
    {
    	 for (int i : subsetA) {
             if (i < 0 || i > g.V() - 1) 
             {
            	 throw new IndexOutOfBoundsException();
             }
         }
         for (int i : subsetB) 
         {
             if (i < 0 || i > g.V() - 1) 
             {
            	 throw new IndexOutOfBoundsException();
             }
         }
         
         if(subsetA.iterator() == null || subsetB.iterator() == null) 
         {
        	 throw new IllegalArgumentException();
         }
    	
    	int dist = -1;
       
        for (Integer A : subsetA) {
            for (Integer B : subsetB) {
                int temp = length(A, B);
                if(dist == -1) 
                {
                    dist = temp;
                }
                else if ((temp < dist) && temp != -1)
                    dist = temp;
            }
        }
        return dist;
        
        
        
    }
    
    public int ancestor(Iterable<Integer> subsetA, Iterable<Integer> subsetB) 
    {
    	 for (int i : subsetA) {
             if (i < 0 || i > g.V() - 1)
             {
            	 throw new IndexOutOfBoundsException();
             }
         }
         for (int i : subsetB) {
             if (i < 0 || i > g.V() - 1) 
             { 
            	 throw new IndexOutOfBoundsException();
             }
         }
         
         if(subsetA.iterator() == null || subsetB.iterator() == null) 
         {
        	 throw new IllegalArgumentException();
         }
    	
    	
    	int dist = -1; 
        int ancestor = -1;
        
        for (Integer A : subsetA) {
            for (Integer B : subsetB) {
                int temp = length(A, B);
                
                if(dist  == -1) 
                {
                	dist = temp;
                    ancestor = ancestor(A, B);
                }
                
                else if (temp < dist) {
                    dist = temp;
                    ancestor = ancestor(A, B);
                }
            }
        }
        return ancestor;

    }
    
    
    public static void main(String[] args) {
        
        In in = new In(args[0]);
        Digraph G = new Digraph(in);
        ShortestCommonAncestor sca = new ShortestCommonAncestor(G);
        while (!StdIn.isEmpty()) {
            int v = StdIn.readInt();
            int w = StdIn.readInt();
            int length   = sca.length(v, w);
            int ancestor = sca.ancestor(v, w);
            StdOut.printf("length = %d, ancestor = %d\n", length, ancestor);
        }

    }

}
