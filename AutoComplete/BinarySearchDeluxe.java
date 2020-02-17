
import java.util.Comparator;

public class BinarySearchDeluxe {

    public static <Key> int firstIndexOf(Key[] a, Key key,  Comparator<Key> comparator) 
    {
        
        if(a == null || key == null || comparator == null)
        {
            throw new NullPointerException();
        }
        
        int low = 0;
        int high = a.length-1;
        int firstIndex = 0;
        while(low <= high) 
        {
            int mid = low + (high - low) / 2;
            //if key is greater than mid
            if(comparator.compare(key, a[mid]) > 0) 
            {
                low = mid + 1;
            }
            //if key is less than mid
            else if(comparator.compare(key, a[mid]) < 0) 
            {
                high = mid - 1;
            }
            //if key is equal to mid
            else
            {
                //checks if key is first in array
                if(mid == 0) 
                {
                    firstIndex = mid;
                    return firstIndex;
                }
                //decrements mid until first index of key is found
                while(comparator.compare(key, a[mid]) == 0) 
                {
                    
                    firstIndex = mid;
                    mid--;
                    if(mid == 0) 
                    {
                        firstIndex = mid;
                        break;
                    }
                }
                
                return firstIndex;
            }
        }
        return -1;
    }
    
    public static <Key> int lastIndexOf(Key[] a, Key key, Comparator<Key> comparator) 
    {
        if(a == null || key == null || comparator == null)
        {
            throw new NullPointerException();
        }
        
        int low = 0;
        int high = a.length-1;
        int lastIndex = 0;
        while(low <= high) 
        {
            int mid = low + (high - low) / 2;
            //if key is greater than mid
            if(comparator.compare(key, a[mid]) > 0) 
            {
                low = mid + 1;
            }
            //if key is less than mid
            else if(comparator.compare(key, a[mid]) < 0) 
            {
                high = mid - 1;
            }
            //if key is equal to mid
            else
            {
                //checks if key is at the end of the array
                if(mid == a.length-1) 
                {
                    lastIndex = mid;
                    return lastIndex;
                }
                //increments mid until last index of key is found
                while(comparator.compare(key, a[mid]) == 0) 
                {
                    lastIndex = mid;
                    mid++;
                    if(mid == a.length-1) 
                    {
                        lastIndex = mid;
                        break;
                    }
                }
                
                return lastIndex;
            }
        }
        return -1;
    }
    
    public static void main(String[] args) 
    {
        
    }
}
