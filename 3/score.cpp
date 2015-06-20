#include <iostream>

using namespace std;
float emptypenalty(bool consec)
{
	if(consec)
	{
		return -0.05;
	}
	consec = true;
	return -0.2;
}

float newscore(char a, char b, bool consec)
{
	switch(a)
	{
		if ( a == '_')
		{
			return emptypenalty(consec);
		} 
		consec = false;
		case 'A':
			switch(b)
			{
				case 'A': return 1;
				break;
				case 'C': return -0.1;
				break;
				case 'T': return -0.15;
				break;
				case 'G': return -0.1;
				break;
				default: break;
			}
		break;
		case 'C':
			switch(b)
			{
				case'A': return -0.1;
				break;
				case 'C': return 1;
				break;
				case 'T': return -0.1;
				break;
				case 'G': return -0.15;
				break;
				default: break;
			}
		break;
		case 'T':
			switch(b)
			{
				case'A': return -0.15;
				break;
				case 'C': return -0.1;
				break;
				case 'T': return 1;
				break;
				case 'G': return -0.1;
				break;
				default: break;
			}
		break;
		case 'G':
			switch(b)
			{
				case 'A': return -0.1;
				break;
				case 'C': return -0.15;
				break;
				case'T': return -0.1;
				break;
				case 'G': return 1;
				break;
				default: break;
			}
		break;
		default: break;
	}
}



int main()
{
	string R = "_AACCTGACATCTT";
	string Q = "_CCAGCGTCAACTT";
	bool consec = false;
	float** scoretable = new float*[Q.size()];
	float** scoretable2 = new float*[Q.size()];
	for(int i = 0 ; i < Q.size(); i++)
	{
		scoretable[i] = new float[R.size()];
		scoretable2[i] = new float[R.size()];
	}
	// generic score
	for(int i = 0; i < R.size(); i++)
	{
		for(int j = 0; j < Q.size(); j++)
		{
			if( i == 0 && j == i)
			{
				scoretable[i][j] = 0;
			}
			else if( (i ==0 && j== 1) || ( i == 1 && j == 0))
			{
				scoretable[i][j] = -0.2;
			}
			else if( i == 0 || j == 0)
			{
				scoretable[i][j] = -0.05;
			}
			else
			scoretable[i][j] = newscore(Q[i], R[j], consec);
		}
	}
	// end generic score
	
	//print 
	for(int i = 0; i < Q.size(); i++)
	{
		for(int j = 0; j < R.size(); j++)
		{
			cout << scoretable[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
	// end print
	
	//max score populate
	for(int i = 0; i < Q.size(); i++)
	{
		for(int j = 0; j < R.size(); j++)
		{
			if( i == 0 && j == 0)
			{
				scoretable2[i][j] = scoretable[i][j];
			}
			else if( i == 0)
			{
				scoretable2[i][j] = scoretable[i][j] + scoretable2[i][j-1];
			}
			else if( j == 0)
			{
				scoretable2[i][j] = scoretable[i][j] + scoretable2[i-1][j];
			}
			else
				scoretable2[i][j] = 0;
				
		}
	}
	
	//print 
	for(int i = 0; i < Q.size(); i++)
	{
		for(int j = 0; j < R.size(); j++)
		{
			cout << scoretable2[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
	// end print
	
	
	return 0;
}
