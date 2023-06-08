#include <iostream>

class Matrix
{
	
private:
	int** array;
	int rows;
	int columns;

	public:
		Matrix() {
			std::cout << "2D Matrix is created: " << std::endl;
		}
		Matrix(int rows, int columns)
		{
			this->rows = rows;
			this->columns = columns;
			
			array = new int* [rows];
			for (int i = 0; i < rows; ++i)
			{
				array[i] = new int[columns];
				{
					for (int j = 0; j < columns; ++j)
					{
						array[i][j] = 20 + rand() % 310;
					}
				}
			}
		}
		void set_size(int rows, int columns)
		{
			
			if (rows <= 0 || columns <=0 )
			{
				std::cout <<std::endl << "The size of the rows and columns can't be under 0!!!!";
				exit(1);
			}
			
		}
		void Print_array(int rows, int columns)
		{
			if (array == nullptr)
			{
				std::cout << "The array is empty!!! ";
				return;
			}
			for (int i = 0; i < rows; ++i)
			{
				for (int j = 0; j < columns; ++j)
				{
					std::cout << array[i][j] << ' ';
				}
				std::cout << std::endl;
			}
		}
		void swap_rows(int rows, int size, int sw1, int sw2)
		{
			if (sw1 >= rows || sw2 >= rows)
			{
				std::cout << std::endl << "You have crossed the boundaries of the matrix !!! ";
				exit(1);
			}
			else if(sw1<0 || sw2< 0)
			{
				std::cout << std::endl << "You have crossed the boundaries of the matrix !!! ";
				exit(1);
			}
			std::cout << "New matrix with swappes rows is:_ " << std::endl;

			for (int j = 0; j < columns; ++j)
			{
				int temp = array[sw1][j];
				array[sw1][j] = array[sw2][j];
				array[sw2][j] = temp;
			}
			Print_array(rows, columns);

		}

		void swap_columns(int rows, int size, int sw1, int sw2)
		{
			
			if (sw1 >= columns || sw2 >= columns)
			{
				std::cout << std::endl << "You have crossed the boundaries of the matrix !!! ";
				exit(1);
			}
			else if (sw1 < 0 || sw2 < 0)
			{
				std::cout << std::endl << "You have crossed the boundaries of the matrix !!! ";
				exit(1);
			}
			std::cout << "New matrix with swappes columns is:_ " << std::endl;

			for (int i = 0; i < rows; ++i)
			{
				int temp = array[i][sw1];
				array[i][sw1] = array[i][sw2];
				array[i][sw2] = temp;
			}
			Print_array(rows, columns);
		}

		void Delete(int rows, int columns)
		{
			for (int i = 0; i < rows; ++i)
			{
				delete[] array[i];
			}
			delete[] array;
			array = nullptr;
		}
		~Matrix()
		{
			std::cout << "Destructor is called:_ ";
			Delete(rows, columns);
		}
};
int main(int argc, char** argv)
{
	int rows = 0;
	int columns = 0;
	int sw1 = 0;
	int sw2;
	std::cout << "Please enter the size of the rows:_ ";
	std::cin >> rows;
	std::cout << "Please enter the size of the columns:_ ";
	std::cin >> columns;
	Matrix twoD(rows, columns);

	twoD.set_size(rows,columns);
	std::cout << "We have generated the following matrix_\n";
	twoD.Print_array (rows, columns);
	std::cout << "Please enter the columns which need to be swapped:_ ";
	std::cin >> sw1;
	std::cout << " _";
	std::cin >> sw2;
	twoD.swap_columns(rows, columns, sw1, sw2);
	std::cout << "Please enter the rows which need to be swapped:_ ";
	std::cin >> sw1;
	std::cout << " _";
	std::cin >> sw2;
	twoD.swap_rows( rows, columns, sw1, sw2);
	

	return 0;
}