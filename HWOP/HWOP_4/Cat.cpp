#include "Cat.h"
#include <iostream>

void Cat::SetName(string name) { this->name = name; }
void Cat::SetWeight(double weight) { this->weight = weight; }
void Cat::SetEnergy(int energy) { this->energy = energy; }
void Cat::SetBreed(string breed) { this->breed = breed; }
void Cat::SetColor(string color) { this->color = color; }

string Cat::GetName()
{
    cout << "������ ���� -> " << this->name << "\n";
    return this->name; 
}
double& Cat::GetWeight() { return this-> weight; }
int& Cat::GetEnergy() { cout << "-> " << this ->energy << "\n"; return this->energy; }
string Cat::GetBreed() { return this->breed; }
string Cat::GetColor() { return this->color; }

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
}
