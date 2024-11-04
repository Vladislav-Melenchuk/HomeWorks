#include <iostream>
#include <string>

using namespace std;


class Smartphone
{
	string brand;
	string model;
	double memory;
	int battery;
	double screen;

public:

	//сеттеры
	void SetBrand(string br)
	{
		brand = br;
	}

	void SetModel(string mod)
	{
		model = mod;
	}

	void SetBattery(int b)
	{
		battery = b;
	}

	void SetMemory(double m)
	{
		memory = m;
	}

	void SetScreen(double scr)
	{
		screen = scr;
	}


	//геттеры
	string GetBrand()  {
		cout << "\n->" << brand;
		return brand;
	}

	string GetModel()  {
		return model;
	}

	double& GetMemory()
	{
		return memory;
	}

	double& Getscreen()
	{
		return screen;
	}

	int& GetBattery()
	{
		cout << "->" << battery;
		return battery;
	}

	//Методы
	void Call(int number)
	{
		cout << "\nИдет гудок на " << number << "... \n";
	}


	void makePhoto()
	{
		battery -= 2;
		memory -= 0.5;
		cout << "Чикс... ";
		cout << "Фото сохранено в галереи.\n";
	}

	void batteryCheck()
	{
		cout << "\nТелефон заряжен на " << battery << "%\n";
	}

	void playMusic()
	{
		if (battery <= 5)
		{
			cout << "\nНедостаточно заряд. Зарядите телефон.\n";
		}
		else
		{
			battery -= 5;
			cout << "\nВоспроизведение музыки...\n";
		}
	}

	void chargePhone()
	{
		battery = 100;
		cout << "\nТелефон заряжен. Уровень заряда: " << battery << "%\n";
	}

};

class TV {
	string brand;
	string model;
	double screenSize;
	int volume = 10;
	bool isSound;
public:


	//Сеттеры

	void SetBrand(string br)
	{
		brand = br;
	}

	void SetModel(string modl)
	{
		model = modl;
	}

	void SetScreenSize(double scrSize)
	{
		screenSize = scrSize;
	}

	void SetVolume(int v) 
	{
		volume = v;
	}

	void SetSound(bool sound)
	{
		isSound = sound;
	}

	//Геттеры
	string GetBrand()
	{
		return brand;
	}

	string GetModel()
	{
		return model;
	}

	double& GetScreenSize()
	{
		return screenSize;
	}

	int& GetVolume()
	{
		return volume;
	}

	bool GetIsSound()
	{
		return isSound;
	}

	//Методы
	void turnOn() {
		isSound = true;
		cout << "\nВключение\n";
	}

	void turnOff()
	{
		cout << "\nВыключение\n";
	}

	void addVolume() {
		if (volume == 100) {
			cout << "\n Звук на максимум.";
			return;
		}
		volume += 5;
		cout << "\n-->" << volume;
	}

	void delVolume() {
		if (volume <= 0) {
			cout << "\n Звук на минимуме.";
			return;
		}
		volume -= 5;
		cout << "\n-->" << volume;
	}

	void offSound() {
		isSound = false;
		cout << "\nЗвук выключен.";
	}

	void onSound() {
		isSound = true;
		cout << "\nЗвук включен.";
	}
	
};

class CoffeeMachine {
	string brand;
	int water = 0;
	int coffee = 0;
	int milk = 0;
	bool isOn;
	string coffeeType;
public:

	void SetBrand(string br)
	{
		brand = br;
	}

	void SetWater(int w) 
	{ 
		water = w;
	}

	void SetCoffee(int c)
	{
		coffee = c;
	}

	void SetMilk(int m) 
	{
		milk = m;
	}

	void SetOn(bool on)
	{
		isOn = on; 
	}

	void SetCoffeeType(string type)
	{
		coffeeType = type; 
	}



	string GetCoffeeType()
	{
		return coffeeType;
	}
	string GetBrand() 
	{
		return brand;
	}
	bool GetIsOn()
	{
		return isOn;
	}

	int& GetWater()
	{
		return water;
	}

	int& GetCoffee()
	{
		return coffee;
	}

	int& GetMilk()
	{
		return milk;
	}

	//Методы
	void turnOn() {
		isOn = true;
		cout << "\nКофеварка включена.\n";
	}

	void turnOff() {
		isOn = false;
		cout << "\nКофеварка выключена.\n";
	}

	void refuel() {
		water += 1500;
		coffee += 500;
		milk += 1500;
		cout << "\nРезервуары заполнены: вода, кофе и молоко.\n";
	}

	void setCoffeeType(string type) {
		coffeeType = type;
		cout << "\nТип кофе установлен на " << coffeeType << ".\n";
	}

	void brewCoffee() {
		if (water <= 0 || coffee <= 0) {
			cout << "\nНедостаточно воды или кофе.\n";
			return;
		}

		if (coffeeType == "латте" || coffeeType == "капучино" || coffeeType == "флэт") {
			if (milk <= 0) {
				cout << "\nНедостаточно молока для приготовления " << coffeeType << ".\n";
				return;
			}
			milk -= 200; 
		}

		water -= 200;  
		coffee -= 20;  

		cout << "\nВаш " << coffeeType << " готов!\n";
	}

	void stats()
	{
		cout << "\n======\n";
		cout << "\nwater -->" << water;
		cout << "\ncoffee -->" << coffee;
		cout << "\nmilk  -->" << milk;
		cout << "\n======\n";
	}
};

class Cat {
	string name;
	double weight;
	int energy;
	string breed;
	string color;
public:

	void SetName(string n) 
	{
		name = n;
	}

	void SetWeight(double w) 
	{
		weight = w;
	}

	void SetEnergy(int enrg) 
	{
		energy = enrg;
	}

	void SetBreed(string br)
	{
		breed = br;
	}

	void SetColor(string clr)
	{
		color = clr;
	}

	string GetName()
	{
		return name;
	}

	double& GetWeight() 
	{
		return weight;
	}

	int& GetEnergy(){
		return energy;
	}

	string GetBreed()
	{
		return breed;
	}

	string GetColor() 
	{
		return color;
	}

	//--------
	void Play()
	{
		energy -= 10;
		cout << name << " играется ...\n";
	}

	void Eat()
	{
		weight += 0.5;
		cout << "Кушает...\n";
	}

	void Sleep()
	{
		energy = 100;
		cout << name << " спит...\n";
	}

	void MakeSound() {
		cout << "MEOW!!!\n";
	}

	void Stats() 
	{
		cout << "Статистика кота " << name << ":\n";
		cout << "Вес: " << weight << " кг\n";
		cout << "Энергия: " << energy << "%\n";
	}
};

class WashingMachine {
	string brand;
	string model;
	double weight;
	bool soap = false;
	bool isOn = false;
public:

	void SetBrand(string br)
	{
		brand = br;
	}

	void SetModel(const string mod) 
	{
		model = mod;
	}

	void SetWeight(double w)
	{
		weight = w;
	}

	void SetSoap(bool sp) {
		soap = sp;
	}

	void SetIsOn(bool sOn)
	{
		isOn = sOn;
	}

	string GetBrand() 
	{
		return brand;
	}

	string GetModel() {
		return model;
	}

	double& GetWeight()
	{
		return weight;
	}

	bool GetSoap()
	{
		return soap;
	}

	bool GetIsOn()
	{
		return isOn;
	}


	void turnOn()
	{
		isOn = true;
		cout << "\nВключение...";

	}

	void turnOff()
	{
		isOn = false;
		cout << "\nВыключение...";
	}

	void selectMode(int mode)
	{
		if (isOn == false) {
			cout << "\nОшибка, машинка выключена вы не можете выбрать программу.";
		}
		if (soap == true) {
			cout << "\nПрограмма " << mode << " выбрана.";
		}
		else {
			cout << "\nНету мыла, добавьте мыло в отсек.";
		}
	}

	void addSoap()
	{
		if (isOn == false) {
			cout << "\nОшибка, машинка выключена вы не можете выбрать программу.";
		}
		if (soap == true)
		{
			cout << "\nОтсек уже заполнен.";
			return;
		}
		soap = true;
		cout << "\nОтсек с мылом заполнен.";
	}

	void startWash()
	{
		if (isOn == false) {
			cout << "\nОшибка, машинка выключена вы не можете выбрать программу.";
		}

		soap = false;

		cout << "\nМашинка моет...";
	}
};

int main()
{
	setlocale(LC_ALL, "russian");

	Smartphone a;

	a.SetBrand("Iphone");
	a.SetBattery(30);
	a.GetBattery();

	a.GetBrand();
}