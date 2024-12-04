#include "Cat.h"
#include <iostream>


int Cat::counter = 0;

void Cat::SetName(const char* name)
{ 
    if (this->name != nullptr)
    {
        delete[] this->name;
    }
    this->name = new char[100];
    strcpy_s(this->name, 99, name);
}
void Cat::SetWeight(double weight) { this->weight = weight; }
void Cat::SetEnergy(int energy) { this->energy = energy; }
void Cat::SetBreed(string breed) { this->breed = breed; }
void Cat::SetColor(string color) { this->color = color; }

string Cat::GetName()
{
    return string(name); 
}
double& Cat::GetWeight() { return this-> weight; }
int& Cat::GetEnergy() { cout << "-> " << this ->energy << "\n"; return this->energy; }
string Cat::GetBreed() { return this->breed; }
string Cat::GetColor() { return this->color; }
int Cat::GetCount()
{
    return counter;
}

//Конструкторы

Cat::Cat() : energy(100), weight(1.5), breed("None"), color("None")
{
    cout << "\nНачальная версия кота создана.\n";
    counter++;
}

Cat::Cat(int weight, string breed, string color) : weight(weight), breed(breed), color(color)
{
    cout << "\nДанные о коте добавлены." << "\n";
}

Cat::Cat(string name) : Cat()
{
    SetName(name.c_str());
}

Cat::~Cat()
{
    if (name != nullptr)
    {
        delete[] name;
        name = nullptr;
    }

    counter--;
}

//K-K
Cat::Cat(Cat& original)
{
    cout << "\nCopy C=tor";
    SetName(original.name);
    breed = original.breed;
    color = original.color;

    counter++;
}


//Методы
void Cat::Play()
{
    if (energy <= 20) cout << "Котик устал и не хочет играть." << "\n";

    this->energy -= 10;
    cout << this->name << " играется...\n";
}
void Cat::Eat()
{
    this->energy -= 5;
    this->weight += 0.5;
    cout << "Кушает...\n";
}
void Cat::Sleep()
{
    this->energy = 100;
    cout << this->name << " спит...\n";
}
void Cat::MakeSound()
{
    this->energy -= 1;
    cout << "MEOW!!!\n";
}
void Cat::Stats()
{
    cout << "Статистика кота " << this->name << ":\n";
    cout << "Вес: " << this->weight << " кг\n";
    cout << "Энергия: " << this->energy << "%\n";
    cout << "Цвет: " << this->color << "\n";
    cout << "Порода: " << this->breed << "\n";
}


