#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#define MAX 10000000

int isPrime(unsigned int num)
{
	//check if the number is below zero
    if(num == 1)
        return 0;
    if(num%2 == 0)
    {
        if(num == 2)
            return 1;
        else
            return 0;
    }
    else if(num%3 == 0)
    {
        if(num == 3)
            return 1;
        else
            return 0;
    }
    else
    {
        for(unsigned int i = 5; i*i <= num; i+=6)
        {
            if(num%i == 0 || num%(i+2) == 0)
            {
                return 0;
            }
        }
    }

    return 1;
}
unsigned int _gcd(unsigned int a, unsigned int b)
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
	short int isPowerful,isPP, gcd;
	unsigned int power = 0; 
	unsigned int n,y,z,x;
	unsigned int num;
	for(num = 3; num < MAX; num++)
	{
		 y = rand();
		 z = rand();
		x= ((y % 32768) + 1)*((z % 32768) + 1) + 1;
		n = x;
		isPowerful = 1;
		gcd = 0;
		if(!isPrime(n))
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

		    if(isPowerful && gcd == 1 && n == 1)
		    {
		    	printf("%d\n",x );
		    	counter++;
		    }
		}	
	}
printf("%d\n",counter);
}
