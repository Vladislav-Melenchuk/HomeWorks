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
    void SetBrand(string brand);
    void SetModel(string model);
    void SetScreenSize(double screenSize);
    void SetVolume(int volume);
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