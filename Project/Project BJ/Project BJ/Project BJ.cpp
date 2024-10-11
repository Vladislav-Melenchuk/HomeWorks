#include <iostream>
#include <cstdlib>
#include <locale>
#include <windows.h>
#include <conio.h>
#include <string>
#include <ctime>
#include <iomanip>
#include "libraryHelper.h"

using namespace std;

//Функции меню
void menu();
void authorLobby();
void rulesList();
void questionsLobby(int& balance, int& wins);
void stats(int& balance, int& wins);
void shop(int& balance, int& wins);
void changer(int& balance, int& wins);
void visualMenu();

//BJ
void playGame(int& balance, int& wins);

//Инструменты
void setColor(int color);
void clear();




//=========================================================================================
//Основание

int balance = 5000;
int wins = 1;
bool takenDaily = false;
bool readRules = false;

void main()
{
    SetTitle();
    setlocale(LC_ALL, "russian");
    SetConsoleWindowSize(900, 1700);
    CenterScreen();
    clear();
    menu();
}

//=========================================================================================
//Функции меню
void menu()
{
    clear();
    visualMenu();

    int choice = 0;

    while (choice != 4)
    {
        while (true)
        {
            setColor(9);
            cout << "\n\t\tВыберите опцию -> ";
            setColor(2);
            cin >> choice;
            setColor(8);

            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                setColor(4);
                cout << "\t\tОшибка! Введите именно число.\n";
                setColor(9);
            }
            else {
                break;
            }
        }


        switch (choice)
        {

        case 1:
            if (!readRules)
            {
                questionsLobby(balance, wins);
            }
            else {
                playGame(balance, wins);
            }

            break;

        case 2:
            clear();
            stats(balance, wins);
            break;

        case 3:
            clear();
            rulesList();
            break;

        case 4:
            clear();
            shop(balance, wins);
            break;

        case 5:
            clear();
            authorLobby();
            break;

        case 6:
            setColor(11);
            cout << "\n\t\tУдачи и хорошего дня!\n";
            setColor(8);
            Sleep(5000);
            exit(0);

        default:
            setColor(12);
            cout << "\n\t\tОшибка! Выберите правильную цифру.";
            cout << "\n";
            setColor(8);
            break;
        }
    }
}

void visualMenu()
{

    setColor(3);
    cout << "\t\t=========================================\n";
    cout << "\t\t|                КАЗИНО                 |\n";
    cout << "\t\t=========================================\n";
    setColor(11);

    cout << "\t\t+---------------------------------------+\n";
    cout << "\t\t|                                       |\n";
    cout << "\t\t|      ";
    cout << "1. Играть в Blackjack";
    cout << "            |\n";
    cout << "\t\t|                                       |\n";
    cout << "\t\t|      ";
    cout << "2. Статистика";
    cout << "                    |\n";
    cout << "\t\t|                                       |\n";
    cout << "\t\t|      ";
    cout << "3. Правила игры";
    cout << "                  |\n";
    cout << "\t\t|                                       |\n";
    cout << "\t\t|      ";
    cout << "4. Магазин";
    cout << "                       |\n";
    cout << "\t\t|                                       |\n";
    cout << "\t\t|      ";
    cout << "5. Автор";
    cout << "                         |\n";
    cout << "\t\t|                                       |\n";
    cout << "\t\t|      ";
    cout << "6. Выйти из игры";
    cout << "                 |\n";
    cout << "\t\t|                                       |\n";
    cout << "\t\t+---------------------------------------+\n";
    setColor(8);

}

void stats(int& balance, int& wins)
{
    clear();
    setColor(3);
    cout << "\t\t=========================================\n";
    cout << "\t\t|              СТАТИСТИКА               |\n";
    cout << "\t\t=========================================\n";
    setColor(11);
    cout << "\t\t+---------------------------------------+\n";
    cout << "\t\t|                                       |\n";

    string balanceStr = to_string(balance);
    string winsStr = to_string(wins);

    if (balanceStr.length() == 4)
        cout << "\t\t|      Баланс: " << balance << " фишек" << "               |\n";
    else if (balanceStr.length() == 5)
        cout << "\t\t|      Баланс: " << balance << " фишек" << "              |\n";
    else
        cout << "\t\t|      Баланс: " << balance << " фишек" << "                |\n";

    if (winsStr.length() == 2)
        cout << "\t\t|      Побед: " << wins << "                        |\n";
    else if (winsStr.length() == 3)
        cout << "\t\t|      Побед: " << wins << "                       |\n";
    else
        cout << "\t\t|      Побед: " << wins << "                         |\n";
    cout << "\t\t|                                       |\n";
    cout << "\t\t+---------------------------------------+\n";
    setColor(8);

    setColor(3);
    cout << "\n\t\tНажмите любую клавишу для возврата в меню...";
    _getch();
    clear();
    menu();
}

void shop(int& balance, int& wins)
{
    clear();


    int choice = 0;
    bool leave = false;

    while (!leave)
    {
        setColor(3);
        cout << "\t\t=========================================\n";
        cout << "\t\t|                Магазин                |\n";
        cout << "\t\t=========================================\n";
        setColor(11);
        cout << "\t\t+---------------------------------------+\n";
        cout << "\t\t|                                       |\n";
        cout << "\t\t|   1. Обменять победы на фишки         |\n";
        cout << "\t\t|                                       |\n";
        cout << "\t\t|   2. Получить фишки (50 фишек)        |\n";
        cout << "\t\t|                                       |\n";
        cout << "\t\t|   3. Выйти из магазина                |\n";
        cout << "\t\t|                                       |\n";
        cout << "\t\t+---------------------------------------+\n";

        while (true)
        {
            setColor(9);
            cout << "\n\t\tВыберите опцию -> ";
            setColor(2);
            cin >> choice;


            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                setColor(4);
                cout << "\n\t\tОшибка! Введите именно число.\n";
                setColor(9);
            }
            else if (choice == 1)
            {

                changer(balance, wins);

            }
            else if (choice == 2)
            {
                if (!takenDaily)
                {
                    takenDaily = true;
                    balance += 50;
                    setColor(7);
                    cout << "\n\t\tВы получили на свой баланс 50 фишек. Удачной игры!\n";
                    Sleep(3000);
                    clear();
                    break;

                }
                else
                {
                    setColor(12);
                    cout << "\n\t\tСегодня вы уже брали дополнительные фишки.\n";
                    Sleep(3000);
                    clear();
                    break;
                }

            }
            else if (choice == 3)
            {
                clear();
                menu();
            }
            else
            {
                setColor(12);
                cout << "\n\t\tОшибка! Введите число из списка предложенных.\n";
                setColor(9);
            }
        }

    }
}

void changer(int& balance, int& wins)
{
    int num = 0;
    clear();
    setColor(3);
    cout << "\t\t=========================================\n";
    cout << "\t\t|              Обменник                 |\n";
    cout << "\t\t=========================================\n";
    setColor(11);
    cout << "\n\t\t+---------------------------------------+\n";
    cout << "\t\t|      Список:                          |\n";
    cout << "\t\t|                                       |\n";
    cout << "\t\t|      1. 1 победа = 100 фишек          |\n";
    cout << "\t\t|      2. 5 побед = 500 фишек           |\n";
    cout << "\t\t|      3. 10 побед = 1000 фишек         |\n";
    cout << "\t\t|                                       |\n";
    cout << "\t\t|      4. Вернуться                     |\n";
    cout << "\t\t+---------------------------------------+\n";
    while (true)
    {
        setColor(9);
        cout << "\n\t\tВыберите опцию -> ";
        setColor(2);
        cin >> num;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            setColor(12);
            cout << "\n\t\tОшибка! Введите именно число.\n";
            setColor(9);
        }
        else if (num == 1 && wins >= 1)
        {
            balance += 100;
            wins -= 1;
            setColor(7);
            cout << "\n\t\tВы обменяли 1 победу на 100 фишек. Ваш баланс: " << balance << " фишек.\n";
            Sleep(3000);



        }
        else if (num == 2 && wins >= 5)
        {
            balance += 500;
            wins -= 5;
            setColor(7);
            cout << "\n\t\tВы обменяли 5 побед на 500 фишек. Ваш баланс: " << balance << " фишек.\n";
            Sleep(3000);


        }
        else if (num == 3 && wins >= 10)
        {
            balance += 1000;
            wins -= 10;
            setColor(7);
            cout << "\n\t\tВы обменяли 10 побед на 1000 фишек. Ваш баланс: " << balance << " фишек.\n";
            Sleep(3000);
        }
        else if (num > 4 || num < 1)
        {
            setColor(12);
            cout << "\n\t\tОшибка! Ввели не коректное число. Попробуйте снова.\n";
            setColor(9);
        }
        else if (num == 4)
        {
            clear();
            shop(balance, wins);
        }
        else
        {
            setColor(12);
            cout << "\n\t\t У вас недостаточно побед для обмена.\n";
            setColor(9);
        }
    }
}

void rulesList()
{
    setColor(3);
    cout << "\t\t=========================================\n";
    cout << "\t\t|              Правила игры             |\n";
    cout << "\t\t=========================================\n";
    setColor(11);

    setColor(11);
    cout << "\t\t+---------------------------------------+\n";
    cout << "\t\t|                                       |\n";
    cout << "\t\t|  1. Цель игры - набрать 21 очко.      |\n";
    cout << "\t\t|     Карты с цифрами имеют свое        |\n";
    cout << "\t\t|     номинальное значение.             |\n";
    cout << "\t\t|     Карты с картинками стоят          |\n";
    cout << "\t\t|     по 10 очков.                      |\n";
    cout << "\t\t|     Тузы могут стоить 1 или 11 очков. |\n";
    cout << "\t\t|                                       |\n";
    cout << "\t\t|  2. Игроки соревнуются против дилера. |\n";
    cout << "\t\t|     Ваша задача - получить больше     |\n";
    cout << "\t\t|     очков, чем у дилера, но не больше |\n";
    cout << "\t\t|     21.                               |\n";
    cout << "\t\t|                                       |\n";
    cout << "\t\t|  3. Если сумма ваших очков больше 21, |\n";
    cout << "\t\t|     вы проигрываете (перебор).        |\n";
    cout << "\t\t|                                       |\n";
    cout << "\t\t|  4. Blackjack — это 21 очко из двух   |\n";
    cout << "\t\t|     карт (туз + карта стоимостью 10). |\n";
    cout << "\t\t|                                       |\n";
    cout << "\t\t+---------------------------------------+\n";

    setColor(3);
    cout << "\n\t\tНажмите любую клавишу для возврата в меню...";
    _getch();
    clear();
    menu();
}

void authorLobby()
{
    setColor(3);
    cout << "\t\t=========================================\n";
    cout << "\t\t|              АВТОР ПРОЕКТА            |\n";
    cout << "\t\t=========================================\n";
    setColor(11);

    setColor(11);
    cout << "\t\t+---------------------------------------+\n";
    cout << "\t\t|                                       |\n";
    cout << "\t\t|       ";
    cout << "Владислав Меленчук";
    cout << "              |\n";
    cout << "\t\t|       ";
    cout << "Студент группы ПВ 421";
    cout << "           |\n";
    cout << "\t\t|                                       |\n";
    cout << "\t\t+---------------------------------------+\n";

    setColor(3);
    cout << "\n\t\tНажмите любую клавишу для возврата в меню...";
    _getch();
    clear();
    menu();
}

void questionsLobby(int& balance, int& wins)
{
    setlocale(LC_ALL, "russian");
    int age;
    int rulesAgreement;
    string name;

    while (true) {
        setColor(9);
        cout << "\n\t\tСколько вам лет? -> ";
        setColor(2);
        cin >> age;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            setColor(12);
            cout << "\n\t\tПожалуйста, введите корректное числовое значение.\n";
        }
        else if (age < 18)
        {
            setColor(12);
            cout << "\n\tИзвините, вам должно быть больше 18 лет для участия в игре.\n";
            Sleep(3000);
            menu();
        }
        else {
            break;
        }
    }


    while (true)
    {
        setColor(9);
        cout << "\n\t\tОзнакомились с правилами игры?\n\n\t\t 1 - да \n\t\t 2 - нет\n\t\t -> ";
        setColor(2);
        cin >> rulesAgreement;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            setColor(4);
            cout << "\n\t\tПожалуйста, введите корректное числовое значение.\n";
        }
        else if (rulesAgreement == 2)
        {
            setColor(4);
            cout << "\n\t\tИзвините, вам надо ознакомиться с правилами игры.\n\t\tСейчас отроются правила игры.\n\n";
            Sleep(4500);
            clear();
            rulesList();
        }
        else if (rulesAgreement == 1)
        {
            break;
        }


    }

    setColor(10);
    cout << "\n\t\tУдачной игры!\n";
    Sleep(2000);

    //Запускает игру
    readRules = true;
    playGame(balance, wins);


}

//=========================================================================================
//BJ код

const int coloda_SIZE = 52;
const int BLACKJACK = 21;
const int Deal_Stop = 17;

string suits[] = { "S", "H", "D", "C" };
string ranks[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };
int values[] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11 };

int coloda[coloda_SIZE];
bool Used_Card[coloda_SIZE] = { false };

void shuffleColoda(int coloda[]) {
    for (int i = 0; i < coloda_SIZE; i++) {
        coloda[i] = i;
        Used_Card[i] = false;
    }

    for (int i = 0; i < coloda_SIZE; i++) {
        int randomIndex = rand() % coloda_SIZE;
        swap(coloda[i], coloda[randomIndex]);
    }
}

int drawCard(int coloda[]) {
    int cardIndex;
    do {
        cardIndex = rand() % coloda_SIZE;
    } while (Used_Card[cardIndex]);

    Used_Card[cardIndex] = true;
    return coloda[cardIndex];
}

int cardValue(int cardIndex) {
    return values[cardIndex % 13];
}

int handValue(int hand[], int handSize) {
    int value = 0;
    int aces = 0;

    for (int i = 0; i < handSize; i++) {
        int cardVal = cardValue(hand[i]);
        value += cardVal;
        if (cardVal == 11) aces++;
    }

    while (value > BLACKJACK && aces > 0) {
        value -= 10;
        aces--;
    }

    return value;
}

void showCard(int cardIndex) {
    int rankIndex = cardIndex % 13;
    int suitIndex = cardIndex / 13;

    string rank = ranks[rankIndex];
    string suit = suits[suitIndex];

    cout << "+-----+\n";
    cout << "|" << rank;
    if (rank.length() == 1) cout << "    |\n";
    else if (rank.length() == 2) cout << "   |\n";
    cout << "|     |\n";
    cout << "|  " << suit << "  |\n";
    cout << "|     |\n";
    cout << "|    " << rank << "|\n";
    cout << "+-----+\n";
}

void showHand(int hand[], int handSize, const string& player, bool SecondDealerCard = true) {
    setColor(11);
    cout << "\n";
    cout << "    " << player << ": " << "\n\n";
    setColor(8);
    for (int i = 0; i < handSize; i++) {
        cout << "    +-----+  ";
    }
    cout << "\n";

    for (int i = 0; i < handSize; i++) {
        if (player == "Дилер" && i == 1 && !SecondDealerCard) {
            cout << "    |?    |  ";
        }
        else {
            int rankIndex = hand[i] % 13;
            cout << "    |" << ranks[rankIndex];
            if (ranks[rankIndex].length() == 1) cout << "    |  ";
            else if (ranks[rankIndex].length() == 2) cout << "   |  ";
        }
    }
    cout << "\n";

    for (int i = 0; i < handSize; i++) {
        cout << "    |     |  ";
    }
    cout << "\n";

    for (int i = 0; i < handSize; i++) {
        if (player == "Дилер" && i == 1 && !SecondDealerCard) {
            cout << "    |  ?  |  ";
        }
        else {
            int suitIndex = hand[i] / 13;
            cout << "    |  " << suits[suitIndex] << "  |  ";
        }
    }
    cout << "\n";

    for (int i = 0; i < handSize; i++) {
        cout << "    |     |  ";
    }
    cout << "\n";

    for (int i = 0; i < handSize; i++) {
        if (player == "Дилер" && i == 1 && !SecondDealerCard) {
            cout << "    |    ?|  ";
        }
        else {
            int rankIndex = hand[i] % 13;
            if (ranks[rankIndex].length() == 1)
                cout << "    |    " << ranks[rankIndex] << "|  ";
            else if (ranks[rankIndex].length() == 2)
                cout << "    |   " << ranks[rankIndex] << "|  ";
        }
    }
    cout << "\n";

    for (int i = 0; i < handSize; i++) {
        cout << "    +-----+  ";
    }
    cout << "\n";
}

void playGame(int& balance, int& wins)
{
    clear();
    srand(time(0));

    int continueGame = 1;
    int bet;

    while (continueGame == 1)
    {
        if (balance <= 0)
        {
            clear();
            setColor(12);
            cout << "\n\t+================+\n";
            cout << "\n\tУ вас на балансе 0 фишек, вы не можете играть.\n";
            cout << "\tЗайдите в магазин чтобы получить дополнительные фишки.\n";
            cout << "\n\t+================+\n";
            Sleep(4000);
            menu();
            break;
        }
        while (true) {
            clear();
            setColor(3);
            cout << "\n\t+================+\n";
            setColor(7);
            cout << "\n\t Баланс: " << balance << " фишек" << "\n";
            setColor(3);
            cout << "\n\t+================+\n";
            setColor(9);
            cout << "\n\tВаша ставка -> ";
            setColor(2);
            cin >> bet;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                setColor(3);
                cout << "\n\t+================+\n";
                setColor(12);
                cout << "\n\tНеверный ввод. Повторите ввод.\n";
                Sleep(2000);
                continue;
            }

            if (bet > balance) {
                clear();
                setColor(3);
                cout << "\n\t+================+\n";
                setColor(12);
                cout << "\n\tУ вас нет столько фишек\n";
            }
            else {
                break;
            }
        }

        clear();
        setColor(8);

        int playerHand[10], dealerHand[10];
        int playerHandSize = 2, dealerHandSize = 2;

        shuffleColoda(coloda);
        playerHand[0] = drawCard(coloda);
        playerHand[1] = drawCard(coloda);
        dealerHand[0] = drawCard(coloda);
        dealerHand[1] = drawCard(coloda);

        clear();
        cout << "    Дилер раздает карты...\n";
        Sleep(1000);
        showHand(dealerHand, 1, "Дилер", false);
        Sleep(1000);
        showHand(playerHand, playerHandSize, "Игрок");
        Sleep(1000);

        bool playerTurn = true;


        if (handValue(playerHand, playerHandSize) == BLACKJACK && handValue(dealerHand, dealerHandSize) == BLACKJACK)
        {
            setColor(7);
            cout << "\n    Оба получили Blackjack! Ничья.\n";
            continueGame = 2;
            continue;
        }


        if (handValue(playerHand, playerHandSize) == BLACKJACK && playerHandSize == 2)
        {
            setColor(2);
            cout << "\n    Blackjack! Вы победили.\n";
            balance += bet * 1.5;
            wins++;
            playerTurn = false;
        }


        while (playerTurn) {
            clear();
            showHand(dealerHand, dealerHandSize, "Дилер", false);
            showHand(playerHand, playerHandSize, "Игрок");
            setColor(15);
            cout << "    Значение руки игрока: " << handValue(playerHand, playerHandSize) << "\n";

            if (handValue(playerHand, playerHandSize) > 21)
            {
                setColor(12);
                cout << "\n    Перебор! Вы проиграли!\n";
                balance -= bet;
                showHand(dealerHand, dealerHandSize, "Дилер");
                playerTurn = false;
                break;
            }

            int choice;

            do {
                setColor(9);
                cout << "\n    Взять карту (1) или остановиться (2)? -> ";
                setColor(2);
                cin >> choice;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    setColor(12);
                    cout << "\n    Неверный ввод. Повторите ввод.\n";
                    continue;
                }

                if (choice == 1) {
                    playerHand[playerHandSize++] = drawCard(coloda);
                    clear();
                    showHand(dealerHand, dealerHandSize, "Дилер", false);
                    setColor(8);
                    cout << "\n    Дилер дает еще 1 карту...\n";
                    Sleep(1000);
                    showHand(playerHand, playerHandSize, "Игрок");
                    setColor(15);
                    cout << "    Значение руки игрока: " << handValue(playerHand, playerHandSize) << "\n";

                    if (handValue(playerHand, playerHandSize) > 21) {
                        balance -= bet;
                        clear();
                        showHand(dealerHand, dealerHandSize, "Дилер");
                        showHand(playerHand, playerHandSize, "Игрок");
                        setColor(15);
                        cout << "    Значение руки игрока: " << handValue(playerHand, playerHandSize) << "\n";
                        setColor(12);
                        cout << "\n    Перебор! Вы проиграли!\n";
                        playerTurn = false;
                        break;
                    }
                }
                else if (choice == 2) {
                    playerTurn = false;
                }
                else
                {
                    setColor(12);
                    cout << "\n    Неверный выбор. Повторите ввод.\n";
                }
            } while (choice != 2 && playerTurn);
        }


        if (handValue(playerHand, playerHandSize) <= 21) {
            while (handValue(dealerHand, dealerHandSize) < Deal_Stop) {
                dealerHand[dealerHandSize++] = drawCard(coloda);
                Sleep(1000);
                clear();
                showHand(dealerHand, dealerHandSize, "Дилер");
            }

            clear();
            showHand(dealerHand, dealerHandSize, "Дилер");
            setColor(15);
            cout << "    Значение руки дилера: " << handValue(dealerHand, dealerHandSize) << "\n";
            showHand(playerHand, playerHandSize, "Игрок");
            setColor(15);
            cout << "    Значение руки игрока: " << handValue(playerHand, playerHandSize) << "\n";

            if (handValue(dealerHand, dealerHandSize) > 21)
            {
                setColor(2);
                cout << "\n    У Дилера перебор! Вы победили!\n";
                balance += bet;
                wins++;
            }
            else if (handValue(playerHand, playerHandSize) > handValue(dealerHand, dealerHandSize))
            {
                setColor(2);
                cout << "\n    Вы победили!\n";
                balance += bet;
                wins++;
            }
            else if (handValue(playerHand, playerHandSize) < handValue(dealerHand, dealerHandSize))
            {
                setColor(12);
                cout << "\n    Вы проиграли!\n";
                balance -= bet;
            }
            else
            {
                setColor(7);
                cout << "\n    Ничья! Ставка возвращена.\n";
            }
        }

        do {
            setColor(9);
            cout << "\n    Продолжить играть (1) или выйти (2)? -> ";
            setColor(2);
            cin >> continueGame;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                setColor(12);
                cout << "\n    Неверный ввод. Повторите ввод.\n";
                continue;
            }

            if (continueGame == 2) {
                menu();
                return;
            }
        } while (continueGame != 1 && continueGame != 2);
    }
}

//=========================================================================================
//Инструменты

void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void clear()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
