// Avadh Boriya
// 011487242


#include <iostream>
#include <iomanip>
#include<stdio.h>

#include <mpir.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

const int MAX_ITERATIONS = 6;
const int PLACES         = 1000;        // desired decimal places
const int PRECISION      = PLACES + 1;  // +1 for the digit 3 before the decimal

const int BASE       = 10;  // base 10 numbers
const int BIT_COUNT  = 8;   // bits per machine word

const int BLOCK_SIZE = 10;                // print digits in blocks
const int LINE_SIZE  = 100;               // digits to print per line
const int LINE_COUNT = PLACES/LINE_SIZE;  // lines to print
const int GROUP_SIZE = 5;                 // line grouping size

/***** Function declarations here. *****/
void print(const mpf_t& pi);

/**
 * The main.
 * Set constants, initialize variables, and iterate
 * to compute pi to the desired number of decimal places.
 */
int main()
{
    mpf_set_default_prec(BIT_COUNT*PRECISION);  // precision in bits

    mpf_t count;
    mpf_init(count);

    mpf_t a0,y0,y1,a1;
	mpf_t two,sqrt_two,number_four,number_six,number_one,temp_yo,temp_root,temp_numerator,temp_denominator,temp_yi,temp_2i,temp_first_part,pi,temp_a1;


    mpf_init(a0);
    mpf_init(y0);
    mpf_init(sqrt_two);
    mpf_init(number_four);
    mpf_init(y1);
    mpf_init(a1);

    mpf_init(number_six);
    mpf_init(number_one);
    mpf_init(temp_yo);
    mpf_init(temp_root);
    mpf_init(temp_numerator);
    mpf_init(temp_denominator);
    mpf_init(temp_yi);
    mpf_init(temp_2i);
    mpf_init(temp_first_part);
    mpf_init(temp_a1);
    mpf_init(two);
    mpf_init(pi);


    mpf_set_ui (sqrt_two,2);
    mpf_set_ui (number_four,4);
    mpf_set_ui (number_six,6);
    mpf_set_ui (number_one,1);
    mpf_set_ui(two,2);

    mpf_sqrt(sqrt_two,sqrt_two); //sqrt 2

    mpf_mul(number_four,number_four,sqrt_two); // 4*sqrt(2)

    mpf_sub(a0,number_six,number_four);  // value of a0

    mpf_sub(y0,sqrt_two,number_one);  // value of y0

    // Loop MAX_ITERATIONS times.

    for (int i = 1; i <= MAX_ITERATIONS; i++)
    {

    		mpf_set_ui(count,i);  //set count value similar to i to find 2^2i+1

    		// to find y1
    		mpf_pow_ui (temp_yo,y0,4);  //y0^4

    	    mpf_sub(temp_root,number_one,temp_yo); //1-y0^4

    	    mpf_sqrt(temp_root,temp_root);

    	    mpf_sqrt(temp_root,temp_root);

    	    mpf_sub(temp_numerator,number_one,temp_root); // y1 numerator


    	    mpf_add(temp_denominator,number_one,temp_root); // demominator

    	    mpf_div(y1,temp_numerator,temp_denominator); //y1


    	    // find a1

    	    mpf_pow_ui (temp_yi,y1,2);//yi^2
    	    mpf_add(temp_yi,temp_yi,y1); //yi+yi^2
    	    mpf_add(temp_yi,number_one,temp_yi);//1+yi+yi^2

    	    mpf_mul(temp_yi,temp_yi,y1); // yi(1+yi+yi^2)



    	    //mpf_mul(k,two,count); //2i

    	    //mpf_add(k,d,k);	//2i+1

    	    mpf_pow_ui(temp_2i,two,((2*i)+1));//2^2i+1



    	    mpf_mul(temp_2i,temp_2i,temp_yi);// 2^2i+1 * yi(1+yi+yi^2)

    	    mpf_add(temp_first_part,number_one,y1); //1+yi

    	    mpf_pow_ui(temp_a1,temp_first_part,4); //(1+yi)^4

    	    mpf_mul(temp_a1,a0,temp_a1);//a0*(1+yi)^4


    	    mpf_sub(a1,temp_a1,temp_2i); //a1

   	    mpf_set(y0,y1);
   	    mpf_set(a0,a1);

    }

    mpf_div(pi,number_one,a1);

    //mpf_out_str(stdout,10,200,pi);
    //printf ("\n");



    print(pi);

    //mpf_clears(y0,a0,a,b,c,d,e,f);

    return 0;
}

/***** Function definitions. *****/
void print(const mpf_t& pi)
{
	char *number=NULL;
	char * output_number;
	int space_count=0;
	int digits=0;
	int line_count=0;
	int block_count=0;
	mp_exp_t expo=1;

	output_number=mpf_get_str(number,&expo,10,PLACES+1,pi);

	for(int i=0;i<PLACES+1;i++)
	{
		if(i==0)
		{
			cout<<output_number[i]<<".";

		}
		if(digits==BLOCK_SIZE)
		{
			cout<<" ";
			space_count=space_count+1;
			digits=0;
		}

		if(space_count==10)
		{
			cout<<endl;
			space_count=0;
			cout<<"  ";
			line_count=line_count+1;
		}

		if(line_count==5)
		{
			cout<<endl;
			line_count=0;
			cout<<"  ";
			block_count=block_count+1;

		}

		if(block_count==5)
		{
			cout<<endl<<endl;
			cout<<"  ";
			block_count=0;
		}

		if(i!=0)
		{
		digits=digits+1;
		cout<<output_number[i];
		}
	}


	//cout<<output_number;
}
