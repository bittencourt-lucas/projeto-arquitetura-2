#include <iostream>
#include <atomic>
#include <chrono>
#include <ratio>
#include <fstream>

#define MATRIX_SIZE 513

void prodMatrix(int mat1[][MATRIX_SIZE], int mat2[][MATRIX_SIZE], int count)
{
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count; j++)
		{
			int sum = 0;
			for (int k = 0; k < count; k++)
				sum = sum + mat1[i][k] * mat2[k][j];
			//std::cerr << sum << " ";
		}
		//std::cerr << std::endl;
	}
}

int main()
{
	/**********************************
	// TEST MATRIX: 2x2 sized matrices
	int A[][MATRIX_SIZE] = { {1, 2},
							 {3, 4} };

	int B[][MATRIX_SIZE] = { {-1, 3},
						     {4, 2} };
	**********************************/

	// N sized matrices
    int A[MATRIX_SIZE][MATRIX_SIZE];
    int B[MATRIX_SIZE][MATRIX_SIZE];

    // Open file
    std::ofstream file;
    file.open("Result_NoThread.csv");

    for (int count = 2; count < MATRIX_SIZE; count = count * 2)
    {
	    for (int i = 0; i < count; i++)
	    	for (int j = 0; j < count; j++)
	    	{
	    		A[i][j] = i;
	    		B[i][j] = i * j;
	    	}

		// Starting time
		auto start = std::chrono::high_resolution_clock::now();
		
		prodMatrix(A, B, count);

		// Finishing time
		auto finish = std::chrono::high_resolution_clock::now();

		std::chrono::duration<double, std::milli> total = finish - start;

		// Write results to file
		file << count << ",0," << total.count() << std::endl;

		//std::cout << count << std::endl;
	}

	// Close file
	file.close();

	return 0;
}