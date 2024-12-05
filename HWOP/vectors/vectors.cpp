#include <iostream>
#include <windows.h>
using namespace std;

class Vector {
	unsigned int size = 0; // количество действительно присутствующих элементов в контейнере
	unsigned int capacity = 10; // ёмкость (вместительность, запас памяти)
	int* data = nullptr; // указатель на динамический массив целых чисел

	// метод приватный, потому что это внутрення логика класса, о которой клиент думать не должен
	void EnsureCapacity() {
		// если весь резерв памяти исчерпан
		if (size == capacity) {
			capacity *= 2; // собираемся увеличить резерв памяти в 2 раза
			int* temp = new int[capacity];
			for (int i = 0; i < size; ++i) { // memcpy_s
				temp[i] = data[i];
			}
			delete[] data;
			data = temp;
		}
	}

public:
	Vector() : Vector(10) {
		// cout << "C-TOR WITHOUT PARAMS!\n";
	}

	Vector(unsigned int capacity) {
		if (capacity < 10)
			capacity = 10;

		this->capacity = capacity;
		data = new int[capacity];
		// cout << "C-TOR WITH PARAMS!\n";
	}

	~Vector() {
		// cout << "DESTRUCTOR!\n";
		if (data != nullptr) {
			delete[] data;
			data = nullptr;
		}
	}

	//K-K
	Vector(const Vector& newOne)
	{
		size = newOne.size;
		capacity = newOne.capacity;
		data = new int[capacity];

		for (int i = 0; i < size; i++) {
			data[i] = newOne.data[i];
		}
	}

	//перегрузки

	Vector* operator =(const Vector& newOne)
	{
		delete[] data;

		size = newOne.size;
		capacity = newOne.capacity;
		data = new int[capacity];

		for (int i = 0; i < size; i++) {
			data[i] = newOne.data[i];
		}

		return this;
	}

	bool operator ==(const Vector& newOne) 
	{
		for (unsigned int i = 0; i < size; ++i) {
			if (data[i] != newOne.data[i]) {
				return false;
			}
		}

		return true;
	}

	friend ostream& operator <<(ostream& os, const Vector& newOne)
	{
		for (int i = 0; i < newOne.size; ++i)
			cout << newOne.data[i] << " ";

		cout << "\n";

		return os;
	}

	friend istream& operator >>(istream& is, Vector& newOne) 
	{
		int num;
		cout << "\nВведите число ->";
		is >> num;
		newOne.PushBack(num);
		
		return is;
	}

	unsigned int GetSize() const {
		return size;
	}

	unsigned int GetCapacity() const {
		return capacity;
	}

	void PushBack(int value) {
		EnsureCapacity(); // проверка, хватит ли места для нового элемента
		data[size++] = value;
	}

	void PushFront(int value) {
		EnsureCapacity();
		for (int i = size; i > 0; --i) // i = 1
			data[i] = data[i - 1]; // data[1] = data[0]

		data[0] = value;
		size++;
	}

	void Clear() {
		// if (data != nullptr) delete[] data;
		// capacity = 0;
		size = 0;
	}

	bool IsEmpty() const {
		return size == 0;
	}

	void Print() const {
		if (IsEmpty()) {
			cout << "Vector is empty.\n";
			return;
		}

		for (int i = 0; i < size; ++i)
			cout << data[i] << " ";

		cout << "\n";
	}

	// ...остальные методы...

	void Insert(int value, unsigned int index)
	{
		if (index > size)
		{
			cout << "\nError!\n";
			return;
		}

		EnsureCapacity();
		for (unsigned int i = size; i > index; i--)
		{
			data[i] = data[i - 1];
		}
		data[index] = value;
		size++;
	}

	void RemoveAt(unsigned int index)
	{
		if (index > size)
		{
			cout << "\nError!\n";
			return;
		}

		for (unsigned int i = index; i < size - 1; i++)
		{
			data[i] = data[i + 1];
		}

		size--;
	}

	void RemoveByValue(int value)
	{
		for (int i = 0; i < size;)
		{
			if (data[i] == value)
			{
				for (int j = i; j < size - 1; ++j)
				{
					data[j] = data[j + 1];
				}

				--size;
			}
			else
			{
				++i;
			}
		}
	}

	void PopFront()
	{
		for (unsigned int i = 0; i < size - 1; i++)
		{
			data[i] = data[i + 1];
		}

		size--;
	}

	void PopBack()
	{
		size--;
	}

	void Reverse()
	{
		int left = 0;
		unsigned int right = size - 1;

		while (left < right)
		{
			int temp = data[left];
			data[left] = data[right];
			data[right] = temp;

			++left;
			--right;
		}
	}

	void SortAsc()
	{
		for (int i = 0; i < size - 1; ++i) 
		{
			for (int j = 0; j < size - 1 - i; ++j) 
			{
				if (data[j] > data[j + 1]) 
				{
					int temp = data[j];
					data[j] = data[j + 1];
					data[j + 1] = temp;
				}
			}
		}
	}

	void SortDesc()
	{
		for (int i = 0; i < size - 1; ++i) 
		{
			for (int j = 0; j < size - 1 - i; ++j) 
			{
				if (data[j] < data[j + 1]) 
				{
					int temp = data[j];
					data[j] = data[j + 1];
					data[j + 1] = temp;
				}
			}
		}
	}

	void Shuffle()
	{
		srand(time(0));

		for (int i = 0; i < size; ++i)
		{
			int randIndex = rand() % size;

			int temp = data[i];
			data[i] = data[randIndex];
			data[randIndex] = temp;
		}
	}

	void RandomFill()
	{
		srand(time(0));

		for (int i = 0; i < size; ++i)
		{
			data[i] = rand() % 100;
		}
	}

};

int main()
{
	setlocale(LC_ALL, "ukrainian");
	Vector ar;

	/*for (int i = 0; i < 10; i++) {
		ar.PushBack(1);
		ar.RandomFill();
	}*/

	ar.PushBack(54);
	ar.PushBack(22);
	ar.PushBack(24);

	/*cout << ar;

	cin >> ar;

	cout << ar;*/

	/*Vector ar2;

	ar2.Print();

	ar2 = ar;

	ar2.Print();*/

	

	
}