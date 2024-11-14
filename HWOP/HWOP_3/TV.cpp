#include "TV.h"
#include <iostream>

void TV::SetBrand(string br) { brand = br; }
void TV::SetModel(string mod) { model = mod; }
void TV::SetScreenSize(double scrSize) { screenSize = scrSize; }
void TV::SetVolume(int v) { volume = v; }
void TV::SetSound(bool sound) { isSound = sound; }

string TV::GetBrand() { return brand; }
string TV::GetModel() { return model; }
double& TV::GetScreenSize() { return screenSize; }
int& TV::GetVolume() { return volume; }
bool TV::GetIsSound() { return isSound; }

void TV::turnOn() 
{
    isSound = true;
    cout << "\n���������\n";
}
void TV::turnOff()
{
    cout << "\n����������\n"; 
}
void TV::addVolume() 
{
    if (volume == 100) {
        cout << "\n ���� �� ��������.";
        return;
    }
    volume += 5;
    cout << "\n-->" << volume;
}
void TV::delVolume() 
{
    if (volume <= 0) {
        cout << "\n ���� �� ��������.";
        return;
    }
    volume -= 5;
    cout << "\n-->" << volume;
}
void TV::offSound() 
{
    isSound = false;
    cout << "\n���� ��������.";
}
void TV::onSound() 
{
    isSound = true;
    cout << "\n���� �������.";
}
