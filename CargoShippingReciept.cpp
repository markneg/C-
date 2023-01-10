//Mark Negus
//Mini Project 7
#include <iostream>
#include<string>
#include <iomanip>
#include<ctime>
using namespace std;

// Prototypes
double getVol ();
int keepGoing ();
void welcomeMsg ();
void paymentMethod ();
void shipMethod(double vol);
void receipt();

// Global Variables
int welcomeFlag = 1;
double Total;
double saleTax = .0775;
int COUNTER =1;
string date;
string CustomerName;
double arrayVol[10] = {};
int j = 0;
string shipChoice[100] = {};
double packSize[100] = {}; 

int
main ()
{
  
  double height;
  double width;
  double length;
  double vol;
  double scost;
  double saleTax;
  double total;
  double package;
  double small = 1.50;
  double medium = 2.50;
  double large = 3.0;

  
  if (welcomeFlag)
    welcomeMsg ();
    
    
  vol = getVol ();
  arrayVol[j] = vol;
  j++;
  

  if (vol <= 15)
    {
      package = small;
     cout << "\nVolume of container #" <<""<<COUNTER<< " is "<<setprecision (2) << fixed << vol <<
	" cu ft" << endl;
	COUNTER++;
	  packSize[j-1] += (vol*package);
      scost = small * vol;
      cout << "Small Package";
      cout << " ($ " << package;
      cout << " per cu ft):";
      cout.width (3);
      cout << "$" << setprecision (2) << fixed << scost << endl;
      Total = Total + scost;
      shipMethod(vol);
      keepGoing ();
    }
  else if (vol > 45)
    {
      package = large;
      cout << "\nVolume of container #" <<""<<COUNTER<< " is "<<setprecision (2) << fixed << vol <<
	" cu ft" << endl;
	COUNTER++;
	packSize[j-1] += (vol*package);
      scost = large * vol;
      cout << "Large Package";
      cout << " ($ " << package;
      cout << " per cu ft):";
      cout.width (3);
      cout << "$" << setprecision (2) << fixed << scost << endl;
      Total = Total + scost;
      shipMethod(vol);
      keepGoing ();
    }
  else
    {
      package = medium;
      cout << "\nVolume of container #" <<""<<COUNTER<< " is "<<setprecision (2) << fixed << vol <<
	" cu ft" << endl;
	  COUNTER++;
	  packSize[j-1] += (vol*package);
      scost = medium * vol;
      cout << "Medium Package";
      cout << " ($ " << package;
      cout << " per cu ft):";
      cout.width (3);
      cout << "$" << setprecision (2) << fixed << scost << endl;
      Total = Total + scost;
      shipMethod(vol);
      keepGoing ();
    }

}

double
getVol ()
{
  double arrayVol[10] = {};
  int delivery;
  double height;
  double width;
  double length;
  double vol;

  cout <<"\nEnter dimensions for container #"<<j+1<< " (in feet): " << endl;
  cout<<"Height:   ";
  cin >> height;
  cout <<"\nLength:   ";
  cin >> length;
  cout <<"\nWidth:    ";
  cin >> width;
  vol = length * width * height;
 

  return vol;
    while (vol > 65)
    {
      cout << "Please enter dimensions smaller than 65 cubic feet:" << endl;
      vol = getVol ();
    }
    COUNTER++;
      return vol;
}

int
keepGoing ()
{
  char answer;
  int payment;
  double change;
  double amount;
  double SubTotal = ((Total * saleTax) + Total);

  cout << "\nAnother container (Y/N):";
  cin >> answer;
  if (answer == 'Y' || answer == 'y')
    {
      welcomeFlag = 0;
      return main ();

    }
  else if (answer == 'N' || answer == 'n')
    {
      //cout<<setw(26) << left <<"\nContainer Total" << setw(2) << left << "$ " << setw(8) << right << containerTotal<<endl;    
     // cout<<setw(25) << left <<"Premium Delivery"<< setw(2) << left << "$ " << setw(8) << right << deliveryFee<<endl;
     // cout << setprecision(2) << fixed;
      cout << setw(50) << left << "\n\n\n\n\nSubtotal " << setw(2) << left << "$ " << setw(8) << right << Total << endl;
      cout << setw(45) << left << "Sales Tax - 7.75% " << setw(2) << left << "$ " << setw(8) << right << saleTax*Total << endl << endl;
      cout << setw(45) << left << "Total " << setw(2) << left << "$ " << setw(8) << right << SubTotal << endl;
      paymentMethod ();
      receipt();

    }
}

void
welcomeMsg ()
{
  cout << "****East County Cargo Transport****"<<endl;
  cout<<"\nCashiering system 2.0\nStarting Transactions - date - ";
  cin>>date;
  cin.ignore();
  cout<<"\n\nStarting at Transaction #"<<COUNTER;
  cout<<"\n\nEnter Customer's name: ";
  getline(cin, CustomerName); 
  cout<<"\nCustomer - "<<CustomerName<<endl;
  
  return;
}

void
paymentMethod ()
{
  int payment;
  double change;
  double amount;
  double SubTotal = ((Total * saleTax) + Total);
  string license = "";
  int asciiTotal = 0;		//used later to determine whether or not the licence is in the right format by
  int i = 1;			// summing the numbers in it (it should have a max value of 399 if its only 0123399789 numbers, as the max would be 999999 == 399 in ascii values)
  char card;			//however, this isnt completely full proof as one could enter higher ascii values like letters and stay below the 399 limit with 0s or lower numbers
  string cardDigit;

  cout << "\nPayment (1. Cash, 2. Check, 3. Credit): ";
  cin >> payment;
  if (payment == 1)
    {
      cout << "\nAccepted:";
      cout <<setw(40)<<right<<"$   "<<setw(7)<<right;
      cin >> amount;
      if (amount >= SubTotal)
	{
	  change = amount - SubTotal;
	  cout << "Change:";
	  cout <<setw(39)<<right<< "$" <<setw(9)<<right<< change;
	}
      else
	{
	  while (amount < SubTotal)
	    {
	      cout << "Invalid amount!";
	      cout << "\nAccepted:";
	      cout.width (32);
	      cout << "$\t";
	      cin >> amount;

	    }
	  cout << "Accepted:";
	  cout.width (31);
	  cout << "$";
	  cout << "\t" << amount;
	  change = amount - SubTotal;
	  cout << "\nChange:";
	  cout.width (34);
	  cout << "$\t" << change;
	}
    }
  if (payment == 2)
    {
      cout << "\nEnter Driver License No: ";
      cout.width (30);
      cin >> license;
      for (i = 1; i < license.size (); i++)
	{
	  asciiTotal = asciiTotal + (int) license[i];
	}
      if (license.length () == 8 && (license[0] >= 'A' && license[0] <= 'Z')
	  && asciiTotal <= 399)
	{
	  cout << "\nAccepted Check Payment: ";
	  cout << "$" << SubTotal;
	}
      else
	{
	  cout << "Invalid Number, Rejected";
	  paymentMethod ();
	}
    }
  if (payment == 3)
    {
      cout << "\nVisa (V) or Mastercard (M):";
      cin >> card;
      cout << "\nEnter Last Four Digits of Card:  ";
      cin >> cardDigit;
      if (cardDigit.size () == 4 && (card == 'V' || card == 'M'))
	{
	  cout << "\nAccepted Credit Card Payment:";
	  cout.width (15);
	  cout << "$\t" << SubTotal;
	}
      else
	{
	  cout << "Invalid Card or Number";
	  paymentMethod ();
	}

    }

}

void shipMethod(double vol){
    int delivery;
    time_t now;
    struct tm nowLocal;
    now = time(NULL);
    nowLocal=*localtime(&now);
    double VOLUME = vol;

    
    if(VOLUME < 30){
 
        cout<<"\nHow is this container to be shipped: "<<endl;
        cout<<"\n(1) Standard - (one to two weeks) - No change to the price"<<endl;
        cout<<"(2) Fast Ground - (3 to 5 business days) - Extra $1.50 per cubic foot"<<endl;
        cout<<"(3) Air - (1 to 2 business days) - Only applies to packages under 30 cubic feet - Extra $3.00 per cubic foot"<<endl;
        cout<<"\nDelivery: ";
        cin>>delivery;
    }else{
        cout<<"\nHow is this container to be shipped: "<<endl;
        cout<<"\n(1) Standard - (one to two weeks) - No change to the price"<<endl;
        cout<<"(2) Fast Ground - (3 to 5 business days) - Extra $1.50 per cubic foot"<<endl;
        cout<<"\nDelivery: ";
        cin>>delivery;
        
    }
        if(delivery == 1){
            cout<<"\nStandard: $0.00"<<endl;
            shipChoice[j] = "STD";

         //    cout<<"\nEst Arrival - "<<nowLocal.tm_mon+1<<"/"<<nowLocal.tm_mday+14; //Still havent completely figured this part out yet
        }else if(delivery == 2){
            cout<<"\nFast Ground ($1.50 per cu ft): $"<<1.5*VOLUME<<endl;
            shipChoice[j] = "FG";

          // cout<<"\nEst arrival - "<<nowLocal.tm_mon+1<<"/"<<nowLocal.tm_mday+4;
            Total = Total + (1.5*VOLUME);
        }else if (delivery == 3 && VOLUME < 30){
            shipChoice[j] = "AIR";

            cout<<"\nAir ($3.00 per cu ft): $"<<3*VOLUME<<endl;
           // cout<<"\nEst Arrival - "<<nowLocal.tm_mon+1<<"/"<<nowLocal.tm_mday+2;
            Total = Total + (3*VOLUME);
        }else{
            cout<<"Invalid volume or number";
        }
        
    
}
void receipt(){
int i;
double SubTotal = ((Total * saleTax) + Total);

cout<<"\n\n\n\n\n__________________________________________________________________________________"<<endl;
cout<<"\nEast County Cargo Transport"<<endl;
cout<<"\n123 First Street\nEl Cajon, CA  92071"<<endl;
cout<<"\nCustomer Receipt - "<<date<<endl;
cout<<"\nCustomer Name: "<<CustomerName;


    for(i=0;i<sizeof(arrayVol); i++){
        if(arrayVol[i] != 0){
            if(shipChoice[i+1] == "FG"){
                cout<<setw(45)<<"\n\nContainer #"<<(i+1)<<"- "<<arrayVol[i]<<" cu ft";
                cout<<setw(22)<<"$\t"<<setw(7)<<packSize[i];
                cout<<"\nShipping: "<<shipChoice[i+1];
                cout<<setw(38)<<right<<"    $    ";
                cout<<""<<1.5*arrayVol[i];
            }else if(shipChoice[i+1] == "AIR"){
                cout<<setw(45)<<"\n\nContainer #"<<(i+1)<<"- "<<arrayVol[i]<<" cu ft";
                cout<<setw(23)<<"$\t"<<setw(7)<<packSize[i];
                cout<<"\nShipping: "<<shipChoice[i+1];
                cout<<setw(33)<<right<<"$"<<setw(4);
                cout<<""<<3.0*arrayVol[i];
            }
            else{
                cout<<setw(45)<<"\n\nContainer #"<<(i+1)<<"- "<<arrayVol[i]<<" cu ft";
                cout<<setw(22)<<"$\t"<<setw(7)<<packSize[i];
                cout<<"\nShipping: "<<shipChoice[i+1];
                cout<<setw(33)<<right<<"$"<<setw(5);
                cout<<""<<0.0*arrayVol[i];
            }
        }else{
            break;
        }
        
   }
            cout << setw(46) << left << "\n\nSubtotal " << setw(2) << left << " $ " << setw(8) << right << Total << endl;
            cout << setw(45) << left << "Sales Tax - 7.75% " << setw(2) << left << "$ " << setw(8) << right << saleTax*Total << endl << endl;
            cout << setw(45) << left << "Total " << setw(2) << left << "$ " << setw(8) << right << SubTotal << endl;
}
/*Output
****East County Cargo Transport****

Cashiering system 2.0
Starting Transactions - date - 05/28/2020


Starting at Transaction #1

Enter Customer's name: Jerry Lewis

Customer - Jerry Lewis

Enter dimensions for container #1 (in feet): 
Height:   3

Length:   4

Width:    2

Volume of container #1 is 24.00 cu ft
Medium Package ($ 2.50 per cu ft):  $60.00

How is this container to be shipped: 

(1) Standard - (one to two weeks) - No change to the price
(2) Fast Ground - (3 to 5 business days) - Extra $1.50 per cubic foot
(3) Air - (1 to 2 business days) - Only applies to packages under 30 cubic feet - Extra $3.00 per cubic foot

Delivery: 2

Fast Ground ($1.50 per cu ft): $36.00

Another container (Y/N):y

Enter dimensions for container #2 (in feet): 
Height:   9

Length:   2

Width:    3

Volume of container #2 is 54.00 cu ft
Large Package ($ 3.00 per cu ft):  $162.00

How is this container to be shipped: 

(1) Standard - (one to two weeks) - No change to the price
(2) Fast Ground - (3 to 5 business days) - Extra $1.50 per cubic foot

Delivery: 1

Standard: $0.00

Another container (Y/N):y

Enter dimensions for container #3 (in feet): 
Height:   1

Length:   2

Width:    4

Volume of container #3 is 8.00 cu ft
Small Package ($ 1.50 per cu ft):  $12.00

How is this container to be shipped: 

(1) Standard - (one to two weeks) - No change to the price
(2) Fast Ground - (3 to 5 business days) - Extra $1.50 per cubic foot
(3) Air - (1 to 2 business days) - Only applies to packages under 30 cubic feet - Extra $3.00 per cubic foot

Delivery: 3

Air ($3.00 per cu ft): $24.00

Another container (Y/N):n





Subtotal                                     $   294.00
Sales Tax - 7.75%                            $    22.79

Total                                        $   316.79

Payment (1. Cash, 2. Check, 3. Credit): 1

Accepted:                                    $   320.00
Change:                                      $     3.21





__________________________________________________________________________________

East County Cargo Transport

123 First Street
El Cajon, CA  92071

Customer Receipt - 05/28/2020

Customer Name: Jerry Lewis                                

Container #1- 24.00 cu ft                    $	  60.00
Shipping: FG                                 $    36.00                                

Container #2- 54.00 cu ft                    $	 162.00
Shipping: STD                                $     0.00                                

Container #3- 8.00 cu ft                     $	  12.00
Shipping: AIR                                $    24.00

Subtotal                                     $   294.00
Sales Tax - 7.75%                            $    22.79

Total                                        $   316.79



*/



















