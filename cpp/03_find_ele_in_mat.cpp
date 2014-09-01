/*
Problem 03
Find element in a two-dim sorted array
*/

#include <iostream>
using namespace std;

bool find( const int * mat, const int rows, const int cols,  const int target )
{
	bool found = false;
	int row = 0;
	int col = cols-1;
	while( row < rows && col >= 0 )
	{
		if ( mat[row * cols + col] == target )
		{
			found = true;
			break;
		}
		else if( mat[row * cols + col] > target )
			col--;
		else
			row++;
	}
	return found;
}

int main()
{
	int mat_arr[4][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << mat_arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << find( (int *)mat_arr, 4, 4, 7 ) << endl;
	return 0;
}