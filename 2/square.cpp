//Samuel Villarreal
//svill017
//cs141 fall2013

/* Description: this program takes a specified sized matrix and finds largest and 2nd largest area of Free 
 *  1 <- number of tests
 * 
 *  3 3
 *  F F R
 *  F F R
 *  R R F
 * 
 *  4 1 is the answer
 */
#include <iostream>
#include <fstream>

using namespace std;

//writes to output.txt takes the two biggest squares found 
void writeBack(int greatest,int second , fstream &out)
{
	out << greatest*greatest << " " << second*second << endl; 
}

//takes the two fstreams and works on data sets to calculate square sizes 
void setAnalysis(fstream &in, fstream &out)
{
	char c;
	int colSize = 0, rowSize = 0;
	// checking for correclty opened stream to retrieve data
	in >> colSize;
	in >> rowSize;
	//2d arrays that will hold values 
	char **matrix = new char*[colSize];
	int **sizeTable = new int*[colSize];
	int **sizeTable2= new int*[colSize];
	for(int i = 0; i < colSize ; i++)
	{
		matrix[i] = new char[rowSize];
		sizeTable[i] = new int[rowSize];
		sizeTable2[i] = new int[rowSize];
	}
	int big = 0;
	int nBig = 0;

	
	//populating the F/R 2d array 
	for(int col = 0; (col < colSize) && (in.good()); col++)
	{
		for(size_t row = 0; (row < rowSize) && (in.good()); row++)
		{
			in >> c;
			matrix[col][row] = c;
		}
	 }
	//fill sizeTable
	for(int w = colSize-1; w >= 0 ; w--)
	{
		for(int e = rowSize-1; e >= 0 ; e--)
		{
			//making sure the edges can't be size > 1
			if( e == rowSize-1 || w == colSize-1)
			{
				if(matrix[w][e] == 'F')
				{
					 sizeTable[w][e] = 1;
				}
				else
				{
					 sizeTable[w][e] = 0;
				}
			}
			else
			{
				int minTemp = sizeTable[w+1][e+1];
				if(minTemp > sizeTable[w+1][e])
				{
					minTemp = sizeTable[w+1][e];
				}
				if(minTemp > sizeTable[w][e+1])
				{
					minTemp = sizeTable[w][e+1];
				}

				if(matrix[w][e] == 'F')
					sizeTable[w][e] = 1 + minTemp;
				else sizeTable[w][e] = 0;
			}
		}
	}
	//find the max in these tables
	for(int i = 0; i < colSize; i++)
	{
		for(int j = 0; j < rowSize; j++)
		{
			if( big < sizeTable[i][j]) 
			{
				big = sizeTable[i][j];

			}
		}
	 }

	//find the 2nd biggest using a second size table
	for(int i = 0; i < colSize; i++)
	{
		for(int j = 0; j < rowSize; j++)
		{
			if( big == sizeTable[i][j])
			{
				for(int m = colSize-1; m >= 0 ; m--)
				{
					for(int n = rowSize-1; n >= 0 ; n--)
					{
						//zero out the first max
						if((i <= m  && i+big-1 >= m) && (j <= n  && j+big-1 >= n )) 
						{
							sizeTable2[m][n] = 0;
						}
						//making sure the edges can't be size > 1
						else if(n == rowSize-1 || m == colSize-1)
						{
							if( matrix[m][n] == 'F') sizeTable2[m][n] = 1;
							else sizeTable2[m][n] = 0;
						}
						else
						{
							int minTemp2 = sizeTable2[m+1][n+1];
							if(minTemp2 > sizeTable2[m+1][n])
							minTemp2 = sizeTable2[m+1][n];
							if(minTemp2 > sizeTable2[m][n+1])
							minTemp2 = sizeTable2[m][n+1];

							if(matrix[m][n] == 'F')
							sizeTable2[m][n] = 1 + minTemp2;
							else sizeTable2[m][n] = 0;
						}
						
					}
				}
				//
					for(int m = 0; m < colSize; m++)
					{
							for(int n = 0; n < rowSize; n++)
							{
								if( nBig <= sizeTable2[m][n]) 
								{
									nBig = sizeTable2[m][n];
									if(big == nBig)
									{
										i = colSize;
										j = rowSize;
									}
									
								}
							}
					}
			}
		}
	}
	// size table end



	writeBack(big,nBig,out);
}

int main(int argc,const char* argv[])
{
	// First make a in and out  file stream to read and write data
	fstream in, out;
	in.open(argv[1], fstream::in);
	out.open(argv[2], fstream::out);

	int dataSize; 
	//get number of data sets and run analysis that many times
	if(in.good()) in >> dataSize;
	for(int i = 0; i < dataSize; i++)
	{
		setAnalysis(in,out);
	}
	//closing the file streams 
	in.close();
	out.close();

				
  return 0;
}
