#include <iostream>
#include "TV.h"
#include "Smartphone.h"
#include "Cat.h"
#include "WashingMachine.h"
#include "CoffeeMachine.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "russian");
	TV t;

	t.SetBrand("Samsung");

	//=========

	Smartphone phone;

	phone.SetBrand("Iphone");
	phone.GetBrand();
	phone.chargePhone();
	phone.batteryCheck();

	//=========


}
