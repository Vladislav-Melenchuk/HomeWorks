#include <iostream>
#include <string>

using namespace std;

// надо написать 5 классов чтобы у них были публичные поля и еще придумать к этим классам методы. 

class Smartphone {
public:
	string brand;
	string model;
	double memory;
	int battery;
	double screen; 

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
public:
	string brand;
	string model;
	double screenSize;
	int volume = 10;
	bool isSound;

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
public:
	string brand;
	int water = 0;
	int coffee  = 0;
	int milk = 0;
	bool isOn;
	string coffeeType;

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
public:
	string name;
	double weight;
	int energy;
	string breed;
	string color;


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
public:
	string brand;
	string model;
	double weight;
	bool soap = false;
	bool isOn = false;

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
	cout << "\n---------------------\n";
	cout << "\nClass Cat\n";

	Cat cat;

	cat.name = "Marc";
	cat.weight = 5;
	cat.energy = 100;

	cat.Stats();
	cout << "\n";
	cat.Play();

	cout << "\n---------------------\n";
	cout << "\nClass Smartphone\n";

	Smartphone phone;
	phone.brand = "Samsung";
	phone.model = "S24 ULTRA";
	phone.battery = 100;
	phone.memory = 256;

	phone.Call(965482643);
	phone.makePhoto();
	phone.batteryCheck();
	phone.chargePhone();

	cout << "\n---------------------\n";
	cout << "\nClass WashingMachine\n";
	
	WashingMachine wash;

	wash.brand = "DreamMachine";
	wash.model = "SPP-24";

	wash.turnOn();
	wash.addSoap();
	wash.selectMode(4);
	wash.startWash();

	cout << "\n---------------------\n";
	cout << "\nClass TV\n";

	TV control;

	control.brand = "Samsung";
	control.model = "d55-23";

	control.turnOn();
	control.addVolume();
	control.offSound();

	cout << "\n---------------------\n";
	cout << "\nClass CoffeeMachine\n";

	CoffeeMachine coffee;

	coffee.brand = "philips";

	coffee.turnOn();
	coffee.refuel();
	coffee.stats();
	coffee.setCoffeeType("флэт");
	coffee.brewCoffee();
	
	cout << "\n---------------------\n";
}