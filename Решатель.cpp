#include <iostream>
#include <Windows.h>
#include <cmath>
#include <utility>
#include <fstream>
#include <string>
#include <cstdio>
#include <map>
#include <set>

using namespace std;

class EqualationABC {//A!=0 B!=0 C!=0
public:
    float a, b, c, d;
    EqualationABC() {}
    EqualationABC(float a1, float b1, float c1) {
        this->a = a1;
        this->b = b1;
        this->c = c1;
        this->d = b * b - 4 * a * c;
    }
    float getD() {
        return this->d;
    }
    auto getX() {
        pair <float, float> p;
        float x1;
        float x2;
        if (this->d > 0) {
            x1 = (-this->b + sqrt(this->d)) / (2 * this->a);
            x2 = (-this->b - sqrt(this->d)) / (2 * this->a);
            p = make_pair(x1, x2);
            return p;
        }
        else if (this->d == 0) {
            x1 = -this->b / (2 * a);
            x2 = x1;
            p = make_pair(x1, x2);
            return p;
        }
    }
    auto Viete() {
        pair <float, float> p;
        cout << "x1+x2=" << -this->b << " x1*x2=" << this->c << endl;
    }
};
class EqualationAorB : EqualationABC { //A=0 B!=0 C=0 || A!=0, B=0, C=0
public:
    EqualationAorB(float b1) {
        this->b = b1;
    }
    auto getX() {
        float x = 0;
        return x;
    }
};

class EqualationC : EqualationABC { //A=0, B=0, C!=0
public:
    EqualationC(float c1) {
        this->c = c1;
    }
    string getX() {
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        string x = "Решений нет";
        return x;
    }
};

class EqualationBC : EqualationABC { //A=0 B!=0 C!=0
public:
    EqualationBC(float b1, float c1) {
        this->a = 0;
        this->b = b1;
        this->c = c1;
    }
    auto getX() {
        float x = -this->c / this->b;
        return x;
    }
};

class EqualationAB : EqualationABC { //A!=0 B!=0 C=0
public:
    EqualationAB(float a1, float b1) {
        this->a = a1;
        this->b = b1;
        this->c = 0;
    }
    auto getX() {
        float x1 = 0;
        float x2 = -this->b / this->a;
        pair <float, float> p;
        p = make_pair(x1, x2);
        return p;
    }
};

class EqualationAC : EqualationABC { //A!=0 B=0 C!=0
public:
    EqualationAC(float a1, float c1) {
        this->a = a1;
        this->b = 0;
        this->c = c1;
        this->d = -this->c / this->a;
    }
    float getD() {
        return this->d;
    }
    auto getX() {
        if (this->d > 0) {
            float x = sqrt(-this->c / this->a);
            return x;
        }
        else if (this->d == 0) {
            float x = 0;
            return x;
        }
    }
};

void solve(int lang) {
    float A, B, C;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    (lang == 1) ? cout << "Введите коэффициенты A, B, C вашего квадратного уравнения: Ax^2+Bx+C=0" << endl : cout << "Enter the coefficients A, B, C of your quadratic equation: Ax^2+Bx+c=0" << endl;

    cout << "A=";
    while (!(cin >> A)) {
        cin.clear(); // сбрасываем флаг ошибки ввода
        cin.ignore(1000000, '\n'); // очищаем ввод
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        (lang == 1) ? cerr << "Ошибка! Пожалуйста, введите целое число или дробное через запятую. A=" : cerr << "Error! Please enter an integer or fractional number separated by comma! A=";
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }

    cout << "B=";
    while (!(cin >> B)) {
        cin.clear(); // сбрасываем флаг ошибки ввода
        cin.ignore(1000000, '\n'); // очищаем ввод
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        (lang == 1) ? cerr << "Ошибка! Пожалуйста, введите целое число или дробное через запятую. B=" : cerr << "Error! Please enter an integer or fractional number separated by comma! B=";
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }

    cout << "C=";
    while (!(cin >> C)) {
        cin.clear(); // сбрасываем флаг ошибки ввода
        cin.ignore(1000000, '\n'); // очищаем ввод
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        (lang == 1) ? cerr << "Ошибка! Пожалуйста, введите целое число или дробное через запятую. С=" : cerr << "Error! Please enter an integer or fractional number separated by comma! C=";
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }
    if (A != 0 && B != 0 && C != 0) {
        int choice1 = 0;
        if (A == 1 && lang == 1) {
            cout << "Если хотите решить уравнение с помощью теоремы Виета, введите 1, если через дискриминант, введите 0:" << endl;
            while (true) {
                if (cin >> choice1) {
                    if (choice1 == 1 || choice1 == 0) {
                        break; // Выход из цикла, если введено корректное значение
                    }
                    else {
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                        (lang == 1) ? cerr << "Ошибка! Если хотите решить уравнение с помощью теоремы Виета, введите 1, если через дискриминант, введите 0:" << endl : cerr << "Error! If you want to solve the equation using Viete's theorem, enter 1. If through the discriminant, enter 0:";
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    }
                }
                else {
                    cin.clear();
                    cin.ignore(1000000000, '\n');
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                    (lang == 1) ? cerr << "Ошибка! Если хотите решить уравнение с помощью теоремы Виета, введите 1, если через дискриминант, введите 0:" << endl : cerr << "Error! If you want to solve the equation using Viete's theorem, enter 1. If through the discriminant, enter 0:";
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                }
            }
        }
        if (A == 1 && lang != 1) {
            cout << "If you want to solve the equation using Viete's theorem, enter 1. If through the discriminant, enter 0:" << endl;
            while (true) {
                if (cin >> choice1) {
                    if (choice1 == 1 || choice1 == 0) {
                        break; // Выход из цикла, если введено корректное значение
                    }
                    else {
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                        (lang == 1) ? cerr << "Ошибка! Если хотите решить уравнение с помощью теоремы Виета, введите 1, если через дискриминант, введите 0:" << endl : cerr << "Error! If you want to solve the equation using Viete's theorem, enter 1. If through the discriminant, enter 0:";
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    }
                }
                else {
                    cin.clear();
                    cin.ignore(1000000000, '\n');
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                    (lang == 1) ? cerr << "Ошибка! Если хотите решить уравнение с помощью теоремы Виета, введите 1, если через дискриминант, введите 0:" << endl : cerr << "Error! If you want to solve the equation using Viete's theorem, enter 1. If through the discriminant, enter 0:";
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                }
            }
        }

        EqualationABC f(A, B, C);
        if (choice1 == 0) {
            if (f.getD() >= 0) {
                cout << "x1=" << f.getX().first << " x2=" << f.getX().second << endl;
            }
            else {
                (lang == 1) ? cout << "Решений нет" << endl : cout << "No solutions" << endl;
            }
        }
        else {
            f.Viete();
            cout << "x1=" << f.getX().first << " x2=" << f.getX().second << endl;
        }
    }
    else if (A == 0 && B != 0 && C == 0) {
        EqualationAorB f(B);
        cout << "x1=x2=" << f.getX() << endl;
    }
    else if (A != 0 && B == 0 && C == 0) {
        EqualationAorB f(A);
        cout << "x1=x2=" << f.getX() << endl;
    }
    else if (A == 0 && B == 0 && C != 0) {
        EqualationC f(C);
        (lang == 1) ? cout << "Решений нет" << endl : cout << "No solutions" << endl;
    }
    else if (A == 0 && B != 0 && C != 0) {
        EqualationBC f(B, C);
        cout << "x1=x2=" << f.getX() << endl;
    }
    else if (A != 0 && B != 0 && C == 0) {
        EqualationAB f(A, B);
        cout << "x1=" << f.getX().first << " x2=" << f.getX().second << endl;
    }
    else if (A != 0 && B == 0 && C != 0) {
        EqualationAC f(A, C);
        if (f.getD() >= 0) {
            cout << "x1=x2=" << f.getX() << endl;
        }
        else {
            (lang == 1) ? cout << "Решений нет" << endl : cout << "No solutions" << endl;
        }
    }
    else {
        (lang == 1) ? cout << "Решений нет" << endl : cout << "No solutions" << endl;
    }
    (lang == 1) ? cout << "Введите '1', чтобы решить еще одно уравнение. Чтобы вернуться в меню, введите '2':" << endl : cout << "Enter '1' to solve anouther eqation. Enter '2' to return to the menu:" << endl;
    int choose;
    while (true) {
        if (cin >> choose) {
            if (choose == 1 || choose == 2) {
                break; // Выход из цикла, если введено корректное значение
            }
            else {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                (lang == 1) ? cerr << "Ошибка! Введите '1', чтобы решить еще одно уравнение. Чтобы вернуться в меню, введите '2':" << endl : cerr << "Error! Enter '1' to solve anouther eqation. Enter '2' to return to the menu:";
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }
        }
        else {
            cin.clear();
            cin.ignore(1000000000, '\n');
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            (lang == 1) ? cerr << "Ошибка! Введите '1', чтобы решить еще одно уравнение. Чтобы вернуться в меню, введите '2':" << endl : cerr << "Error! Enter '1' to solve anouther eqation. Enter '2' to return to the menu:";
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }
    }
    if (choose == 1) {
        solve(lang);
    }
    else {
        (lang == 1) ? cout << "Выберите один из пунктов меню:" << endl : cout << "Enter one of the menu items:" << endl;
    }
}

class player {
private:
    string name, password;
    int statistics;
public:
    player() {};
    void getLeague(int lang) {
        set <pair<int, string>, greater<pair<int, string>>> leaders;
        ifstream f("League.txt");
        string s = "";
        while (!f.eof()) {
            getline(f, s);
            pair <int, string> p;
            p.first = getStatistics(s);
            p.second = s;
            leaders.insert(p);
        }
        (lang == 1) ? cout << "Турнирная таблица:" << endl : cout << "League table:" << endl;
        int c = 1;
        for (const auto& element : leaders) {
            if (element.first <= 100 && element.first >= 0 && element.second != "") {
                cout << c << ". " << element.second << " - " << element.first << "%" << endl;
                c++;
            }
        }
    }
    double getStatistics(string name) {
        ifstream f(name + ".txt");
        string s = "";
        int k = 0;
        int c = 0;
        int w = 0;
        if (f.is_open()) {
            while (!f.eof()) {
                getline(f, s);
                if (s == "") {
                    break;
                }
                if (c != 0) {
                    if (stoi(s) == 0) {
                        k++;
                    }
                    else {
                        k++;
                        w++;
                    }
                }
                c++;
            }
            f.close();
        }
        return round(100.0 * w / k);
    }
    void registration(int lang) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        (lang == 1) ? cout << "Начнём регистрацию: пожалуйста, введите своё имя:" : cout << "Let's start the registration: enter your name, please:";
        while (!(cin >> this->name)) {
            cin.clear(); // сбрасываем флаг ошибки ввода
            cin.ignore(1000000, '\n'); // очищаем ввод
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            (lang == 1) ? cerr << "Ошибка! Пожалуйста, введите имя, используя только буквы:" : cerr << "Error! Please enter your name using only letters:";
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }
        (lang == 1) ? cout << "Пожалуйста, придумайте свой пароль:" : cout << "Create a password, please:";
        while (!(cin >> this->password)) {
            cin.clear(); // сбрасываем флаг ошибки ввода
            cin.ignore(1000000, '\n'); // очищаем ввод
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            (lang == 1) ? cerr << "Ошибка! Пожалуйста, введите пароль, используя только буквы:" : cerr << "Error! Please enter your password using only letters:";
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }
        ofstream PlayerFile;
        PlayerFile.open(this->name + ".txt");
        PlayerFile << this->password << endl;
        (lang == 1) ? cout << "Вы успешно зарегистрированны! Давайте начнём игру!" << endl : cout << "You have successfully registered! Let's start the game!" << endl;
        ofstream L("League.txt", ios::app);
        L << this->name << endl;
        game(lang);
    }

    void enter(int lang) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        (lang == 1) ? cout << "Пожалуйста, введите своё имя:" : cout << "Enter your name, please:";
        cin >> this->name;
        fstream PFile;
        PFile.open(this->name + ".txt");
        if (!(PFile)) {
            (lang == 1) ? cout << "Упс, вы не зарегистрированны!" << endl : cout << "Oops, you're not registered!" << endl;
            registration(lang);
        }
        else {
            (lang == 1) ? cout << "Пожалуйста, введите свой пароль:" : cout << "Enter your password, please:";
            cin >> this->password;
            string pswd;
            fstream File(this->name + ".txt");
            getline(File, pswd);
            File.close();
            if (pswd == this->password) {
                (lang == 1) ? cout << "Ну что ж, " + this->name + ", давайте поиграем!" << endl : cout << "Well, " + this->name + ", let's play the game!" << endl;
                try
                {
                    game(lang);
                }
                catch (...)
                {
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                    (lang == 1) ? cout << "Ошибка! Что-то пошло не так..." : cout << "Error! Something went wrong...";
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                }
            }
            else {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                (lang == 1) ? cout << "Упс, пароль неверный! Введите '1', чтобы зарегистрироваться или '2', чтобы попробовать войти еще раз:" << endl : cout << "Oops, the password is not correct! Enter '1' to register or '2' to try logging in again:" << endl;
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                int choicee;
                while (true) {
                    if (cin >> choicee) {
                        if (choicee == 1 || choicee == 2) {
                            break; // Выход из цикла, если введено корректное значение
                        }
                        else {
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                            (lang == 1) ? cerr << "Ошибка! Введите '1', чтобы зарегистрироваться или '2', чтобы попробовать войти еще раз:" << endl : cerr << "Error! Enter '1' to register or '2' to try logging in again:" << endl;
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        }
                    }
                    else {
                        cin.clear();
                        cin.ignore(1000000000, '\n');
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                        (lang == 1) ? cerr << "Ошибка! Введите '1', чтобы зарегистрироваться или '2', чтобы попробовать войти еще раз:" << endl : cerr << "Error! Enter '1' to register or '2' to try logging in again:" << endl;
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    }
                }
                if (choicee == 1) { registration(lang); }
                else { enter(lang); };
            }
        }
    }
    void game(int lang) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        string r;
        ofstream file(this->name + ".txt", ios::app);
        if (lang == 1) {
            string player;
            string m[] = { "камень", "ножницы", "бумага" };
            cout << "Выберите своё оружие: введите 'камень', 'ножницы' или 'бумага'." << endl;
            while (true) {
                if (cin >> player) {
                    if (player == "камень" || player == "ножницы" || player == "бумага") {
                        break; // Выход из цикла, если введено корректное значение
                    }
                    else {
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                        cout << "Ошибка! Введите 'камень', 'ножницы' или 'бумага': ";
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    }
                }
            }
            srand(time(0));
            string bot = m[rand() % 3];
            cout << "Вы: " + player << "\nПРОТИВ" << "\nКомпьютер: " + bot << endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
            (bot == player) ? cout << "Ничья!" : (bot == "камень" && player == "ножницы" || bot == "бумага" && player == "камень" || bot == "ножницы" && player == "бумага") ? cout << "Вы проиграли!" : cout << "Вы выиграли!";
            r = (bot == player) ? "Ничья!" : (bot == "камень" && player == "ножницы" || bot == "бумага" && player == "камень" || bot == "ножницы" && player == "бумага") ? "Вы проиграли!" : "Вы выиграли!";
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }
        if (lang == 2) {
            string player;
            string m1[] = { "rock", "scissors", "paper" };
            cout << "Choose your weapon: enter 'rock', 'scissors' or 'paper'." << endl;
            while (true) {
                if (cin >> player) {
                    if (player == "rock" || player == "paper" || player == "scissors") {
                        break; // Выход из цикла, если введено корректное значение
                    }
                    else {
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                        cout << "Error: Please enter 'rock', 'paper', or 'scissors': ";
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    }
                }
            }
            srand(time(0));
            string bot = m1[rand() % 3];
            cout << "You: " + player << "\nVS " << "\nBot: " + bot << endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
            (bot == player) ? cout << "Draw!" : ((bot == "rock" && player == "scissors") || (bot == "paper" && player == "rock") || (bot == "scissors" && player == "paper")) ? cout << "You lost!" : cout << "You won!";
            r = (bot == player) ? "Draw!" : ((bot == "rock" && player == "scissors") || (bot == "paper" && player == "rock") || (bot == "scissors" && player == "paper")) ? "You lost!" : "You won!";
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }
        if (r == "You won!" || r == "Вы выиграли!") {
            file << "1" << endl;
        }
        if (r == "Вы проиграли!" || r == "You lost!") {
            file << "0" << endl;
        }
        if (r == "Draw!" || r == "Ничья!") {
            file << "0" << endl;
        }
        (lang == 1) ? cout << "\nВы выиграли " << getStatistics(this->name) << "% из всех сыгранных конов." << endl : cout << "\nYou won " << getStatistics(this->name) << "% of games." << endl;
        getLeague(lang);
        (lang == 1) ? cout << "Введите '1', чтобы сыграть еще раз. Чтобы вернуться в меню, введите '2':" << endl : cout << "Enter '1' to play again. Enter '2' to return to the menu:" << endl;
        int choose;
        while (true) {
            if (cin >> choose) {
                if (choose == 1 || choose == 2) {
                    break; // Выход из цикла, если введено корректное значение
                }
                else {
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                    (lang == 1) ? cerr << "Ошибка! Введите '1', чтобы сыграть еще раз. Чтобы вернуться в меню, введите '2': " << endl : cerr << "Error! Enter '1' to play again. Enter '2' to return to the menu: ";
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                }
            }
            else {
                cin.clear();
                cin.ignore(1000000000, '\n');
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                (lang == 1) ? cerr << "Ошибка! Введите '1', чтобы сыграть еще раз. Чтобы вернуться в меню, введите '2': " << endl : cerr << "Error! Enter '1' to play again. Enter '2' to return to the menu: ";
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }
        }
        if (choose == 1) {
            game(lang);
        }
        else {
            (lang == 1) ? cout << "Выберите один из пунктов меню:" << endl : cout << "Enter one of the menu items:" << endl;
        }
    }
};

void const menu(int lang) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    (lang == 1) ? cout << "\nМеню:\n 1 - Решить уравнение\n 2 - Сыграть в игру\n 3 - Завершить работу" << endl : cout << "\nMenu:\n 1 - Solve an equation\n 2 - Play the game\n 3 - Finish the work" << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    (lang == 1) ? cout << "Выберите один из пунктов меню:" << endl : cout << "Select one of the menu items:" << endl;
    while (true) {
        int choice;
        while (true) {
            if (cin >> choice) {
                if (choice == 1 || choice == 2 || choice == 3) {
                    break; // Выход из цикла, если введено корректное значение
                }
                else {
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                    (lang == 1) ? cerr << "Ошибка! Введите '1', чтобы решить квадратное уравнение, '2', чтобы сыграть в игру или '3' чтобы завершить работу программы:" << endl : cerr << "Error! Enter '1' to solve the quadratic equation, '2' to play the game, or '3' to terminate the program:" << endl;
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                }
            }
            else {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                cin.clear();
                cin.ignore(1000000000, '\n');
                (lang == 1) ? cerr << "Ошибка! Введите '1', чтобы решить квадратное уравнение, '2', чтобы сыграть в игру или '3' чтобы завершить работу программы:" << endl : cerr << "Error! Enter '1' to solve the quadratic equation, '2' to play the game, or '3' to terminate the program:" << endl;
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }
        }
        if (choice == 1) {
            try
            {
                solve(lang);
            }
            catch (...)
            {
                (lang == 1) ? cout << "Ошибка! Что-то пошло не так..." : cout << "Error! Something went wrong...";
                break;
            }
        }

        if (choice == 2) {
            player x;
            int choiseee;
            bool flag = true;
            if (flag == true) {
                (lang == 1) ? cout << "Если вы уже зарегистрированы в игре, введите '1', иначе введите '2':" << endl : cout << "If you are already registered in the game, enter '1', otherwise enter '2':" << endl;
                while (true) {
                    if (cin >> choiseee) {
                        if (choiseee == 1 || choiseee == 2) {
                            break; // Выход из цикла, если введено корректное значение
                        }
                        else {
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                            (lang == 1) ? cerr << "Ошибка! Если вы уже зарегистрированы в игре, введите '1', иначе введите '2':" : cerr << "Error! If you are already registered in the game, enter '1', otherwise enter '2': ";
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        }
                    }
                    else {
                        cin.clear();
                        cin.ignore(1000000000, '\n');
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                        (lang == 1) ? cerr << "Ошибка! Если вы уже зарегистрированы в игре, введите '1', иначе введите '2':" : cerr << "Error! If you are already registered in the game, enter '1', otherwise enter '2': ";
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    }
                }
                (choiseee == 1) ? x.enter(lang) : x.registration(lang);
            }
        }

        if (choice == 3) {
            (lang == 1) ? cout << "Работа завершена." : cout << "Work is finished.";
            break;
        }
    }
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int lang;
    cout << "Выберите язык / Choose the language:" << "\n 1 - RU " << "\n 2 - ENG" << endl;
    while (true) {
        if (cin >> lang) {
            if (lang == 1 || lang == 2) {
                break; // Выход из цикла, если введено корректное значение
            }
            else {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                cerr << "Ошибка! Введите '1' для использования Русского языка или '2' для Английского. / Error! Enter '1' for working in Russian or '2' for working in English: ";
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }
        }
        else {
            cin.clear();
            cin.ignore(1000000000, '\n');
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            cerr << "Ошибка! Введите '1' 'для использования Русского языка или '2' для Английского. / Error! Enter '1' for working in Russian or '2' for working in English: ";
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }
    }

    if (lang == 1) {
        cout << "Инструкция по эксплуатации:" << endl << "1. Запустите программу." << endl << "2. Выбрав язык, на котором вы можете работать, следуйте указанием на экране." << endl << "3. Старайтесь делать корректные вводы информации в консоль, чтобы избежать ошибок в работе программы." << endl << "4. Не ставьте лишних пробелов и кавычек при вводе информации. Вводите дробные числа через точку." << endl << "5. По завершении работы закройте консоль." << endl << "6. Для предложений, отзывов или сообщения об ошибках обратитесь к разработчику приложения по указанным контактам:" << endl << "gnshibanov@mail.ru" << endl;
    }
    else {
        cout << "Operating instructions:" << endl << "1. Run the program." << endl << "2. After selecting the your language, follow the instructions on the screen. " << endl << "3. To avoid errors in the program, try to enter information correctly into the console." << endl << "4. Do not put extra spaces and quotation marks while entering information. Use dot to enter fractional numbers." << endl << "5. When work is finished, close the console." << endl << "6. For suggestions, feedback, or bug reports, contact the application developer at the specified contacts:" << endl << "gnshibanov@mail.ru " << endl;
    }

    try
    {
        menu(lang);
    }
    catch (...)
    {
        (lang == 1) ? cout << "Ошибка! Что-то пошло не так..." : cout << "Error! Something went wrong...";
    }

}