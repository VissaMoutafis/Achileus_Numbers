#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#define MAX 10000000

short int _gcd(short int a, short int b)
{
	unsigned int t = b;
	while(a && b){
	 	t = b;   
	    b = a%b;
	    a = t;
	}
	if(a == 0) return b;
	if(b == 0) return a;
    return 0;
}
int main()
{
	srand((unsigned int ) 1572712634);
	unsigned int counter = 0;
	short int isPowerful, gcd, isPrime;
	unsigned int power = 0; 
	unsigned int n;
	unsigned int num;
	for(num = 3; num < MAX; num++)
	{
		n = num;
		isPowerful = 1;
		gcd = 0;
		//////////////////////
		//check if the number is prime
		isPrime = 1;
	    if(n == 1)
	        isPrime = 0;
	    else if(n%2 == 0 && n > 4)
			isPrime = 0;
	   	else if(n%3 == 0 && n > 9)
	        isPrime = 0;
	    else
	    {
		    for(unsigned int i = 5;isPrime == 1 && i*i <= n; i+=6)
		    {
		        if(n%i == 0 || n%(i+2) == 0)
		        {
		            isPrime = 0;
		        }
		    }
		}
		/////////////////////
		if(!isPrime)
		{
			if(n % 2 == 0) 
			{ 
	       		power = 0; 
		        while(n % 2 == 0) 
		        { 
		            n >>= 1; 
		            power++; 
		        } 
		        if(power == 1) 
		        	isPowerful = 0;
		        else
		        	gcd = _gcd(gcd, power);
	    	} 
	    	if(n % 3 == 0 && isPowerful) 
			{ 
	       		power = 0; 
		        while(n % 3 == 0) 
		        { 
		            n /= 3; 
		            power++; 
		        } 
		        if(power == 1) 
		        	isPowerful = 0;
		        else
		        	gcd = _gcd(gcd, power);
	    	} 
	    	
		    if(isPowerful)
		    {
		    	for(unsigned int factor = 5; factor*factor <= n; factor += 6) 
			    { 
			        power = 0; 
			        while(n % factor == 0) { 
			            n = n / factor; 
			            power++; 
			        }
			        if(power == 1){ 
			            isPowerful = 0;
			        	break;
			    	}
			        else if(gcd == 0 || power > 1) //if not gcd > 0  and power <= 1
			        	gcd = _gcd(gcd, power); 

			        power = 0;
			        while(n % (factor+2) == 0) { 
			            n = n / (factor+2); 
			            power++; 
			        }
			        if(power == 1){ 
			            isPowerful = 0;
			        	break;
			    	}
			        else if(gcd == 0 || power > 1)
			        	gcd = _gcd(gcd, power); 
			    }
		    }

		    if(n == 1 && isPowerful && gcd == 1)
		    {
		    	//printf("%d is achilleus number\n",num );
		    	counter++;
		    }
		}
	}
printf("\nFound %d achilleus numbers up to %d\n",counter, MAX);
}
