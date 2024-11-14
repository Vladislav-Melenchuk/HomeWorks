#include "Cat.h"
#include <iostream>

void Cat::SetName(string n) { name = n; }
void Cat::SetWeight(double w) { weight = w; }
void Cat::SetEnergy(int enrg) { energy = enrg; }
void Cat::SetBreed(string br) { breed = br; }
void Cat::SetColor(string clr) { color = clr; }

string Cat::GetName() { return name; }
double& Cat::GetWeight() { return weight; }
int& Cat::GetEnergy() { return energy; }
string Cat::GetBreed() { return breed; }
string Cat::GetColor() { return color; }

void Cat::Play() 
{
    energy -= 10;
    cout << name << " играется...\n";
}
void Cat::Eat() 
{
    weight += 0.5;
    cout << "Кушает...\n";
}
void Cat::Sleep() 
{
    energy = 100;
    cout << name << " спит...\n";
}
void Cat::MakeSound()
{
    cout << "MEOW!!!\n";
}
void Cat::Stats() 
{
   cout << "Статистика кота " << name << ":\n";
   cout << "Вес: " << weight << " кг\n";
   cout << "Энергия: " << energy << "%\n";
}
