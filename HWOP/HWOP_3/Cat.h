#pragma once
#include <string>

using namespace std;

class Cat {
    string name;
    double weight;
    int energy;
    string breed;
    string color;

public:
    void SetName(string n);
    void SetWeight(double w);
    void SetEnergy(int enrg);
    void SetBreed(string br);
    void SetColor(string clr);

    string GetName();
    double& GetWeight();
    int& GetEnergy();
    string GetBreed();
    string GetColor();

    void Play();
    void Eat();
    void Sleep();
    void MakeSound();
    void Stats();
};
