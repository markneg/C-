//Mark Negus
//Project 2
//Java 293

import java.util.Scanner;

public class Main
{


  public static void main (String[]args)
  {
    Scanner scan = new Scanner (System.in);
    int total = 99;		//This is to counteract the fact that when the user enters -99, 
    int userInput = 0;		//it will be scanned and subtract from the real sum
    int largest = 0;
    int smallest = 0;
    boolean first = true;
    
    while (userInput != -99)
      {
	if (userInput % 2 == 0)
	  {			//This makes sure that even ints wont be counted
	    total = total - userInput;
	  }
	else
	  {
	      if (first == true){                                    // This acts like a flag to make sure the 
	          largest = userInput;                               // "largest" and "smallest" actually get assigned instead of the 
	          smallest = userInput;                              // original initialization of "0"
	          first = false; 
	      }
	    if (userInput > largest)
	      {
		largest = userInput;
	      }
	    else if (userInput < smallest)
	      {
		smallest = userInput;
	      }
	  }
	System.out.println ("Enter odd integers(type -99 to stop):");
	userInput = scan.nextInt ();
	total = total + userInput;                                 // Keeps a running total

      }
    if (userInput == -99)                                      // Escape sequence
      {

	System.out.println ("\nSum of all odds:" + total);
	System.out.println ("Largest odd:" + largest);
	System.out.println ("Smallest odd:" + smallest);
      }
  }
}






