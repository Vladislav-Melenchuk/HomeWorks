#pragma once
#include <string>

using namespace std;

class TV {
    char* brand = nullptr;
    char* model = nullptr;
    double screenSize;
    int volume = 10;
    bool isSound;

public:

    TV();
    TV(string brand, string model, double screenSize);
    TV(string brand, string model);

    ~TV();
    TV(TV& original);

    void SetBrand(const char* brand);
    void SetModel(const char* model);
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