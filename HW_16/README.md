#include <iostream>

using namespace std;

struct Car
{
	string brand;
	string model;
	int year;
	string typeEngine;
	int probeg;
};

struct Katana 
{
	string steelType;
	float length;
	float weight;
	bool signature;
	string handleMaterial;
};

struct Rose 
{
	string color;
	float length;
	bool hasThorns;
	string lvlSmell;
	string country;
};


int main() 
{
	setlocale(LC_ALL, "russian");
	
	Car car1 = { "Audi", "RS 7", 2023, "Дизель", 45000 };
	Katana katana1 = { "Тамахаганэ", 72.5, 1.2, true, "Кожа и дерево" };
	Rose rose1 = { "Красный", 60.0, true, "Сильный", "Голландия"};


	cout << "\nМашина\n";
	cout << "Бренд: " << car1.brand << "\n";
	cout << "Модель: " << car1.model << "\n";
	cout << "Год выпуска: " << car1.year << "\n";
	cout << "Тип двигателя: " << car1.typeEngine << "\n";
	cout << "Пробег: " << car1.probeg << " км" << "\n";

	cout << "\n------------------------------------------------\n";

	cout << "\nКатана" << "\n";
	cout << "Тип стали: " << katana1.steelType << "\n";
	cout << "Длина клинка: " << katana1.length << " см" << "\n";
	cout << "Вес: " << katana1.weight << " кг" << "\n";
	cout << "Подпись: " << (katana1.signature ? "Есть" : "Нет") << "\n";
	cout << "Материал рукоятки: " << katana1.handleMaterial << "\n";

	cout << "\n------------------------------------------------\n";

	cout << "\nРоза:" << "\n";
	cout << "Цвет: " << rose1.color << "\n";
	cout << "Длина стебля: " << rose1.length << " см" << "\n";
	cout << "Шипы: " << (rose1.hasThorns ? "Есть" : "Нет") << "\n";
	cout << "Аромат: " << rose1.lvlSmell << "\n";
	cout << "Происхождение: " << rose1.country << "\n";

}
