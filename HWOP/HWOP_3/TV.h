#pragma once
#include <string>

using namespace std;

class TV {
    string brand;
    string model;
    double screenSize;
    int volume = 10;
    bool isSound;

public:
    void SetBrand(string br);
    void SetModel(string mod);
    void SetScreenSize(double scrSize);
    void SetVolume(int v);
    void SetSound(bool sound);

    string GetBrand();
    string GetModel();
    double& GetScreenSize();
    int& GetVolume();
    bool GetIsSound();

    void turnOn();
    void turnOff();
    void addVolume();
    void delVolume();
    void offSound();
    void onSound();
};