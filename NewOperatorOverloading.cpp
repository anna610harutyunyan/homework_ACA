#include <iostream>
#include <new>

void* operator new(size_t size)
{
	void* ptr = malloc(size);
	if (ptr == nullptr)
	{
		throw std::bad_alloc();
	}

	std::cout << "Allocated " << size << " bytes\n ";
	return ptr;
}

void operator delete(void* ptr)
{
	std::cout << "Delete operator overloading: ";
	free(ptr);
}

void init_array(int* array, int size)
{
	for (int i = 0; i < size; ++i)
	{
		array[i] = i;
	}
}
void Print(int* array, int size)
{
	for (int i = 0; i < size; ++i)
	{
		std::cout << array[i] << ' ';
	}
}
int main(int argc, char** argv)
{
	int *array = new int[20];
	init_array(array, 20);
	Print(array, 20);
	std::cout << std::endl;
	delete[]array;

	return 0;
}