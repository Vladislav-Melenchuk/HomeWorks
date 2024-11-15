#include <iostream>
#include <Windows.h>

using namespace std;


struct Check {
    string productName; 
    int kolichestvo;       
    float price;       
    int discount;       
};


void addProduct(Check& check) {
    cout << "Введите наименование товара: ";
    cin >> check.productName;

    cout << "Введите количество товара: ";
    cin >> check.kolichestvo;

    cout << "Введите цену за единицу товара: ";
    cin >> check.price;

    cout << "Введите скидку на товар (в процентах): ";
    cin >> check.discount;
}

void printCheck(const Check* checks, int count) {
    setlocale(LC_ALL, "Russian");
    cout << "\n========== ЧЕК ==========\n";
    float totalAmount = 0.0;
    for (int i = 0; i < count; ++i) {
        const Check& check = checks[i];
        cout << "\nТовар " << i + 1 << ":\n";
        cout << "Наименование: " << check.productName << "\n";
        cout << "Количество: " << check.kolichestvo << "\n";
        cout << "Цена за единицу: " << check.price << " грн\n";
        cout << "Скидка: " << check.discount << "%\n";

        float itemTotal = check.kolichestvo * check.price;
        float discountAmount = itemTotal * check.discount / 100;
        float finalPrice = itemTotal - discountAmount;

        cout << "-----------------------\n";
        cout << "Стоимость с учетом скидки: " << finalPrice << " грн\n";
        totalAmount += finalPrice;
    }
    cout << "\nОбщая стоимость всех товаров: " << totalAmount << " грн\n";
    cout << "=========================\n";
}

int main() {
    const int maxProducts = 50; 
    Check checks[maxProducts];   
    int productCount = 0;        
    int choice;

    setlocale(LC_ALL, "Russian"); 

    do {
        if (productCount >= maxProducts) {
            cout << "Достигнуто максимальное количество товаров!\n";
            break;
        }

        cout << "\nДобавление товара " << productCount + 1 << ":\n";
        addProduct(checks[productCount]);
        productCount++;

        cout << "Хотите добавить еще товар? (Для продолжения - 1): ";
        cin >> choice;
    } while (choice == 1 );


    printCheck(checks, productCount);

}
