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
    cout << "������� ������������ ������: ";
    cin >> check.productName;

    cout << "������� ���������� ������: ";
    cin >> check.kolichestvo;

    cout << "������� ���� �� ������� ������: ";
    cin >> check.price;

    cout << "������� ������ �� ����� (� ���������): ";
    cin >> check.discount;
}

void printCheck(const Check* checks, int count) {
    setlocale(LC_ALL, "Russian");
    cout << "\n========== ��� ==========\n";
    float totalAmount = 0.0;
    for (int i = 0; i < count; ++i) {
        const Check& check = checks[i];
        cout << "\n����� " << i + 1 << ":\n";
        cout << "������������: " << check.productName << "\n";
        cout << "����������: " << check.kolichestvo << "\n";
        cout << "���� �� �������: " << check.price << " ���\n";
        cout << "������: " << check.discount << "%\n";

        float itemTotal = check.kolichestvo * check.price;
        float discountAmount = itemTotal * check.discount / 100;
        float finalPrice = itemTotal - discountAmount;

        cout << "-----------------------\n";
        cout << "��������� � ������ ������: " << finalPrice << " ���\n";
        totalAmount += finalPrice;
    }
    cout << "\n����� ��������� ���� �������: " << totalAmount << " ���\n";
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
            cout << "���������� ������������ ���������� �������!\n";
            break;
        }

        cout << "\n���������� ������ " << productCount + 1 << ":\n";
        addProduct(checks[productCount]);
        productCount++;

        cout << "������ �������� ��� �����? (��� ����������� - 1): ";
        cin >> choice;
    } while (choice == 1 );


    printCheck(checks, productCount);

}
