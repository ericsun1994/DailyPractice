import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        
        Scanner sc=new Scanner(System.in);
        String A=sc.next();
        String B=sc.next();
        /* Enter your code here. Print output to STDOUT. */
    
        System.out.println(A.length()+B.length());
        if(A.compareTo(B) > 0)
        {
            System.out.println("Yes");    
        }else{
            System.out.println("No");
        }
    //  System.out.println(A.replace("h","H")+" "+B.replace("j","J"));
        
    //  String AA = A.charAt(1).toUpperCase();
        String AA = A.substring(0,1).toUpperCase()+A.substring(1,A.length());
    //  String BB = B.charAt(1).toUpperCase();
        String BB = B.substring(0,1).toUpperCase()+B.substring(1,B.length());
        System.out.println(AA+" "+BB);   
    }
}

