#pragma once
#include <string>

using namespace std;

class Cat {
    char* name = nullptr;
    double weight;
    int energy = 100;
    string breed;
    string color;

public:

    Cat();
    Cat(int weight, string breed, string color);
    Cat(string name);
    ~Cat();
    

    void SetName(const char* name);
    void SetWeight(double weight);
    void SetEnergy(int energy);
    void SetBreed(string breed);
    void SetColor(string color);

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