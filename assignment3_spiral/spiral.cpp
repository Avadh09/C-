	#include<iostream>
	#include<iomanip>

	using namespace std;

	const int MAX_SIZE  = 101;  // maximum size of the square matrix
	const int MAX_START = 50;   // maximum starting number

	/***** Complete this program. *****/

	//int spiral[MAX_SIZE][MAX_SIZE];

	void do_spiral(const int n, const int start);
	//void print_spiral(int spiral[][MAX_SIZE]);

	//void print_spiral(int spiral[],const int n, const int start);
	/**
	 * The main: Generate and print spirals of various sizes.
	 */
	int main()
	{
		//do_spiral(1, 1);
		do_spiral(5, 1);
		do_spiral(9, 11);
		//do_spiral(12, 13);
		//do_spiral(15, 17);


	}

	void do_spiral(const int n, const int start)   // to make spiral
	{

		if(n%2 == 0 || n>MAX_SIZE)   // if size is even there print error message
		{
			cout<<endl;
			cout<<" Spiral of size "<<n<< " starting at "<<start<<endl;
			cout<<" ***** Error: Size 12 must be odd."<<endl;
		}

		else
		{
			int pass_array[n*n];

			if(n==1)    // to print in required format
			{
				cout<<" Spiral of size "<<n<< " starting at "<<start<<endl;
							cout<<endl;
			}
			else
			{
			cout<<endl;
			cout<<" Spiral of size "<<n<< " starting at "<<start<<endl;
			cout<<endl;

			}


			int i;
			int x=start;

			int row = (n - 1) / 2;   // to find the starting point
			int col = (n - 1) / 2;   // to find the starting point
			int right = 0;
			int left = 0;

			int array[n][n] = {{0}};   // make array of zeros

			int count = 1;

			array[row][col] = start;    // start from the middle element of the array.

			while (count < n)        //  rotate till last n-1 positions are left. eg for 5 *5 matrix rotate till last 4 value are left.
			{

				right = 0;
				left = 0;

				//move right and up
				for (i = 1; i <= count; i++)   // for the value of count=x values of count move x positions right and then x position upwards
				{
					//move right
					while (right < count)
					{
						col = col + 1;
						x++;
						array[row][col] = x;
						right++;
					}

					//move up.
					row = row - 1;
					x++;
					array[row][col] = x;

				}

				count = count + 1;

				//cout << row << col << endl;

				//move left and down

				for (i = 1; i <= count; i++)  // for the value of count=x values of count move x positions left side and then x position downward.
				{
					//move left
					while (left < count)
					{
						col = col - 1;
						left = left + 1;
						x++;
						array[row][col] = x;

					}

					// move downwards
					//cout << endl << row << col;
					row = row + 1;
					x++;
					array[row][col] = x;

				}

				count++;

				if(count==n)  // for last n-1 positions.
				{
					for(int j=0;j<count;j++)
					{
						col=col+1;
						x++;
						array[row][col]=x;
					}
				}

			}


			for (int x = 0; x < n; x++)   // to print spiral
							{
								for (int y = 0; y < n; y++)
								{
									cout << setw(3) << array[x][y] << " ";
								}
								cout << endl;
							}



	//							for (int x = 0; x < n; x++)
	//								{
	//									for (int y = 0; y < n; y++)
	//									{
	//										pass_array[x]=array[x][y];
	//										cout<<pass_array[x]<<" ";
	//									}
	//								}

	//print_spiral(pass_array,n,start);


	}

	}
	//void print_spiral(int spiral[],const int n, const int start)
	//{
	//
	//	for (int x = 0; x < sizeof(spiral); x++)
	//		{
	//			if(n%x==0)
	//			{
	//				cout << setw(3) << spiral[x] << " "<<endl;
	//			}
	//			else
	//			{
	//			cout << setw(3) << spiral[x] << " ";
	//			}
	//			//cout << endl;
	//		}
	//
	//
	//}
