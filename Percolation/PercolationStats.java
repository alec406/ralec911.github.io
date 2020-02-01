import edu.princeton.cs.algs4.StdRandom;
import edu.princeton.cs.algs4.StdStats;

public class PercolationStats {
	 private double[] percThresholds;
	 private double percThresh;
	 private Percolation myPercolation;
	 private double mean = 0.0;
	 private double stddev = 0.0;
	 private int randRow = 0;
	 private int randCol = 0;
	 private int T = 0;
	 
	
	 public PercolationStats(int n, int trials) {
		 if(n <= 0 || trials <= 0) {
			 throw new IllegalArgumentException();
		 }
		 
		 percThresholds = new double[trials];
		 T = trials;
		 
		 for(int i = 0; i < trials; i++) {
			 myPercolation = new Percolation(n);
			 
			 while(myPercolation.percolates() == false) {
				 randRow = StdRandom.uniform(0, n);
				 randCol = StdRandom.uniform(0, n);
				 myPercolation.open(randRow, randCol);
			 }
			 
			 percThresh = (double)myPercolation.numberOfOpenSites() / (n*n);
             percThresholds[i] = percThresh;
		 }
		  
	 }
	 
	 public double mean() {
		mean = StdStats.mean(percThresholds);
		return mean;
	 }
	 
	 public double stddev() {
		 stddev = StdStats.stddev(percThresholds);
		 return stddev;
	 }
	 
	 public double confidenceLo() {
		 return (mean - ((1.96 * stddev)/Math.sqrt(T)));
	 }
	 
	 public double confidenceHi() {
		return (mean + ((1.96 * stddev)/Math.sqrt(T)));
	 }

	 public static void main(String[] args) {
		 //int N = Integer.parseInt(args[0]);
		// int trials = Integer.parseInt(args[1]);
		 
		 PercolationStats myPerc = new PercolationStats(1000, 1000);
		 
		 System.out.println("Mean = " + myPerc.mean());
		 System.out.println("Stddev = " + myPerc.stddev());
		 System.out.println("95% confidence interval = [" + myPerc.confidenceLo() + " , " + myPerc.confidenceHi() + "]");
	 }
	 
}
