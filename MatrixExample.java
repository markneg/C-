//Mark Negus
//Submitted 8/1/21
// Java 293

import java.util.Scanner;

public class Main
{
  public static void main (String[]args)
  {
    Scanner input = new Scanner (System.in);

    final int overtimePay = 48;
    final int basePay = 40;
    int i = 0;
    int hoursWorked[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    int overtimeHours = 0;
    int amountPaid[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    int workerRange[] = { 0, 0, 0, 0, 0, 0, 0 };


    System.out.printf ("How many workers? (10 max):");
    int amountWorkers = input.nextInt ();


    for (i = 0; i < amountWorkers; i++)
      {
	System.out.printf ("\nEnter worker #" + (i + 1));
	System.out.printf ("'s hours worked: ");
	hoursWorked[i] = input.nextInt ();
	if (hoursWorked[i] <= 8)
	  {
	    amountPaid[i] += (basePay * hoursWorked[i]);
	  }
	else
	  {
	    overtimeHours = 0;
	    overtimeHours = overtimeHours + (hoursWorked[i] - 8);
	    amountPaid[i] =
	      (overtimeHours * overtimePay) +
	      ((hoursWorked[i] - overtimeHours) * basePay);

	  }
	System.out.printf ("Amount paid:" + amountPaid[i]);
      }

    for (i = 0; i < amountWorkers; i++)
      {
	  
	System.out.println ("\nThe result for worker #" + (i + 1) +
			    " is: $" + amountPaid[i]);
			    
	if (amountPaid[i] < 300)
	  {
	    workerRange[0]++;
	  }
	else if (amountPaid[i] < 400)
	  {
	    workerRange[1]++;
	  }
	else if (amountPaid[i] < 500)
	  {
	    workerRange[2]++;
	  }
	else if (amountPaid[i] < 600)
	  {
	    workerRange[3]++;
	  }
	else if (amountPaid[i] < 700)
	  {
	    workerRange[4]++;
	  }
	else if (amountPaid[i] < 800)
	  {
	    workerRange[5]++;
	  }
	else if (amountPaid[i] > 800)
	  {
	    workerRange[6]++;
	  }
      }

    for (i = 0; i < 6; i++)
      {
          System.out.println("\n");
	System.out.println (+(i + 1) + "." + " Less than $" + (i + 3) +
			    "00:" + workerRange[i]);
      }
    System.out.println ("7. More than $800:" + workerRange[6]);

  }



}

