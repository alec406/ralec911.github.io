
import edu.princeton.cs.algs4.WeightedQuickUnionUF;

public class Percolation {
	private boolean[][] open;
	private WeightedQuickUnionUF myUnion;
	private int numOfOpenSites = 0;
	private int sink;
	private int faucet;
	private int N;
	
	public Percolation(int n) {
		if(n <= 0) {
			throw new IllegalArgumentException();
		}
		
		N = n;
		
		myUnion = new WeightedQuickUnionUF((N*N)+2);
		
		sink = (N*N);
		faucet = (N*N)+1;
		
		open = new boolean[N][N];		
	}
	
	public void open(int row, int col) {
		
		if(row < 0 || row >= N || col < 0 || col >= N) {
			throw new IllegalArgumentException();
		}
		//set site to open
		open[row][col] = true;
		numOfOpenSites++;
		int id = findID(row, col);
		
		//check if connected to faucet 
		if(row == 0) {
			myUnion.union(faucet, id);
		}
		//check if site above is open
		else if(open[row-1][col]) {
			myUnion.union(id, id-N);
		}
		
		//check if connected to sink
		if(row == (N-1)) {
			myUnion.union(sink, id);
		}
		//check if site below is open
		else if(open[row+1][col]) {
			myUnion.union(id, id+N);
		}
		
		//check site to the left
		if(col != 0 && open[row][col-1]) {
			myUnion.union(id, id-1);
		}
		
		//check site to the right 
		if(col != (N-1) && open[row][col+1]) {
			myUnion.union(id, id+1);
		}
		
	}
	
	public boolean isOpen(int row, int col) {
		if(row < 0 || row >= N || col < 0 || col >= N) {
			throw new IllegalArgumentException();
		}
		return open[row][col];
	}
	
	public boolean isFull(int row, int col) {
		if(row < 0 || row >= N || col < 0 || col >= N) {
			throw new IllegalArgumentException();
		}
		return !(open[row][col]);
	}
	
	public int numberOfOpenSites() {
		return numOfOpenSites;
	}
	
	public boolean percolates() {
		return myUnion.connected(sink, faucet);
	}
	
	public int findID(int row, int col) {
		return (row * N) + col;
	}

}
