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

//������������

Cat::Cat() : energy(100), weight(1.5), breed("None"), color("None")
{
    cout << "\n��������� ������ ���� �������.\n";
    counter++;
}

Cat::Cat(int weight, string breed, string color) : weight(weight), breed(breed), color(color)
{
    cout << "\n������ � ���� ���������." << "\n";
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


//������
void Cat::Play()
{
    if (energy <= 20) cout << "����� ����� � �� ����� ������." << "\n";

    this->energy -= 10;
    cout << this->name << " ��������...\n";
}
void Cat::Eat()
{
    this->energy -= 5;
    this->weight += 0.5;
    cout << "������...\n";
}
void Cat::Sleep()
{
    this->energy = 100;
    cout << this->name << " ����...\n";
}
void Cat::MakeSound()
{
    this->energy -= 1;
    cout << "MEOW!!!\n";
}
void Cat::Stats()
{
    cout << "���������� ���� " << this->name << ":\n";
    cout << "���: " << this->weight << " ��\n";
    cout << "�������: " << this->energy << "%\n";
    cout << "����: " << this->color << "\n";
    cout << "������: " << this->breed << "\n";
}


