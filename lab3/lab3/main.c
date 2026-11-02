#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <locale.h>

// 1. 66
void task_1() {
    printf("\n 1 \n");
    double A, B, X, Y, Z;
    printf("Введіть розміри отвору (A та B): ");
    scanf("%lf %lf", &A, &B);
    printf("Введіть розміри цегли (X, Y, Z): ");
    scanf("%lf %lf %lf", &X, &Y, &Z);

    int fits = 0;

    if ((X <= A && Y <= B) || (Y <= A && X <= B)) fits = 1;
    if ((X <= A && Z <= B) || (Z <= A && X <= B)) fits = 1;
    if ((Y <= A && Z <= B) || (Z <= A && Y <= B)) fits = 1;

    if (fits)
        printf("Результат: Цегла ПРОЙДЕ через отвір.\n");
    else
        printf("Результат: Цегла НЕ ПРОЙДЕ через отвір.\n");
}

// 2. 73
void task_2() {
    int password;
    printf("Введіть 4-значний пароль працівника: ");
    scanf("%d", &password);

    if (password == 9583 || password == 1747) {
        printf("Результат: Доступні модулі баз A, B, C (Повний доступ).\n");
    }
    else if (password == 3331 || password == 7922) {
        printf("Результат: Доступні модулі баз B, C (Середній доступ).\n");
    }
    else if (password == 9455 || password == 8997) {
        printf("Результат: Доступний модуль бази C (Обмежений доступ).\n");
    }
    else {
        printf("Результат: Невірний пароль! Доступ заборонено.\n");
    }
}

// 3. 92
void task_3() {
    int n;
    printf("Введіть натуральне число n (n <= 9999): ");
    scanf("%d", &n);

    if (n < 0 || n > 9999) {
        printf("Помилка: число поза діапазоном [0, 9999].\n");
        return;
    }

    int d3 = n / 1000;
    int d2 = (n / 100) % 10;
    int d1 = (n / 10) % 10;
    int d0 = n % 10;

    int count = 0;
    if (d3 == d2 || d3 == d1 || d3 == d0) {
    }
    int found = 0;
    for (int digit = 0; digit <= 9; digit++) {
        int c = (d3 == digit) + (d2 == digit) + (d1 == digit) + (d0 == digit);
        if (c >= 3) {
            found = 1;
            break;
        }
    }

    if (found)
        printf("Результат: Число містить принаймні три однакові цифри.\n");
    else
        printf("Результат: Число НЕ містить трьох однакових цифр.\n");
}

// 4.16
void task_4() {
    int num;
    printf("Введіть тризначне число: ");
    scanf("%d", &num);

    if (num < 100 || num > 999) {
        printf("Помилка: число не є тризначним.\n");
        return;
    }

    int hundreds = num / 100;
    int units = num % 10;

    if (hundreds == units)
        printf("Результат: Число %d є паліндромом.\n", num);
    else
        printf("Результат: Число %d НЕ є паліндромом.\n", num);
}

// 5.77
void task_5() {
    double x[4], y[4];
    printf("Введіть координати (x y) для 4 вершин послідовно в обході:\n");
    for (int i = 0; i < 4; i++) {
        printf("Вершина %d: ", i + 1);
        scanf("%lf %lf", &x[i], &y[i]);
    }

    int pos = 0, neg = 0;
    for (int i = 0; i < 4; i++) {
        double x1 = x[i], y1 = y[i];
        double x2 = x[(i + 1) % 4], y2 = y[(i + 1) % 4];
        double x3 = x[(i + 2) % 4], y3 = y[(i + 2) % 4];

        double cross_product = (x2 - x1) * (y3 - y2) - (y2 - y1) * (x3 - x2);
        if (cross_product > 0) pos = 1;
        else if (cross_product < 0) neg = 1;
    }

    if (pos && neg)
        printf("Результат: Чотирикутник НЕ є опуклим.\n");
    else
        printf("Результат: Чотирикутник є ОПУКЛИМ.\n");
}

// 6. 55
void task_6() {
    double a, b, c, d;
    printf("Введіть чотири числа (a, b, c, d): ");
    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);

    double min1 = (a < b) ? a : b;
    double min2 = (c < d) ? c : d;
    double result = (min1 > min2) ? min1 : min2;

    printf("Результат: max(min(%.2f, %.2f), min(%.2f, %.2f)) = %.2f\n", a, b, c, d, result);
}

// 7.69
void task_7() {
    int N, M;
    printf("Введіть загальну кількість поверхів хмарочоса (N): ");
    scanf("%d", &N);
    printf("Введіть номер потрібної квартири (M): ");
    scanf("%d", &M);

    if (M <= 0 || N <= 0) {
        printf("Помилка: невірні дані.\n");
        return;
    }

    int floor_calc = (M - 1) / 3 + 1;
    if (floor_calc > N) {
        printf("Помилка: такої квартири не існує у цьому хмарочосі.\n");
        return;
    }

    int target_floor = floor_calc;
    if (floor_calc % 2 == 0) {
        if (floor_calc - 1 >= 1) {
            target_floor = floor_calc - 1;
        }
        else if (floor_calc + 1 <= N) {
            target_floor = floor_calc + 1;
        }
    }

    printf("Квартира %d знаходиться на %d поверсі.\n", M, floor_calc);
    printf("Результат: Ліфт доставит пасажира на %d поверх.\n", target_floor);
}

// 8.12
void task_8() {
    int num;
    printf("Введіть двозначне число: ");
    scanf("%d", &num);

    if (num < 10 || num > 99) {
        printf("Помилка: число не є двозначним.\n");
        return;
    }

    int tens = num / 10;
    int units = num % 10;

    long long square = (long long)num * num;
    long long sum_cubes = (long long)(tens * tens * tens) + (units * units * units);

    printf("Квадрат числа %d^2 = %lld\n", num, square);
    printf("Вчетвірніша сума кубів цифр: 4 * (%d^3 + %d^3) = %lld\n", tens, units, 4 * sum_cubes);

    if (square == 4 * sum_cubes)
        printf("Результат: ПОЗИТИВНА відповідь.\n");
    else
        printf("Результат: НЕГАТИВНА відповідь.\n");
}

// 9.3
void task_9() {
    int num;
    printf("Введіть ціле число: ");
    scanf("%d", &num);

    int is_even = (num % 2 == 0);
    int ends_with_7 = (abs(num) % 10 == 7);
    int last_digit = abs(num) % 10;
    int ends_with_even = (last_digit == 0 || last_digit == 2 || last_digit == 4 || last_digit == 6 || last_digit == 8);

    printf("Результати аналізу:\n");
    printf(" а) Чи число парне? -> %s\n", is_even ? "Так" : "Ні");
    printf(" б) Чи закінчується цифрою 7? -> %s\n", ends_with_7 ? "Так" : "Ні");
    printf(" в) Чи закінчується парною цифрою? -> %s\n", ends_with_even ? "Так" : "Ні");
}

// 10.48
void task_10() {
    printf("\n--- Підзадача 10 (Варіант 48): Прямокутний трикутник ---\n");
    double a, b, c;
    printf("Введіть три сторони трикутника (a, b, c): ");
    scanf("%lf %lf %lf", &a, &b, &c);

    if (a <= 0 || b <= 0 || c <= 0 || (a + b <= c) || (a + c <= b) || (b + c <= a)) {
        printf("Помилка: трикутник з такими сторонами не існує.\n");
        return;
    }

    int is_right = 0;
    char* hypotenuse = "";

    double eps = 1e-6;
    if (fabs(a * a + b * b - c * c) < eps) {
        is_right = 1;
        hypotenuse = "сторона c";
    }
    else if (fabs(a * a + c * c - b * b) < eps) {
        is_right = 1;
        hypotenuse = "сторона b";
    }
    else if (fabs(b * b + c * c - a * a) < eps) {
        is_right = 1;
        hypotenuse = "сторона a";
    }

    if (is_right)
        printf("Результат: Трикутник є ПРЯМОКУТНИМ, гіпотенуза — %s.\n", hypotenuse);
    else
        printf("Результат: Трикутник НЕ є прямокутним.\n");
}
int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    setlocale(LC_ALL, ".UTF8");

    int choice;
    do {
        printf(" 1.\n");
        printf(" 2.\n");
        printf(" 3.\n");
        printf(" 4.\n");
        printf(" 5.\n");
        printf(" 6.\n");
        printf(" 7.\n");
        printf(" 8.\n");
        printf(" 9.\n");
        printf("10.\n");
        printf(" 0. Вихід з програми\n");
        printf("Оберіть номер завдання (0-10): ");

        if (scanf("%d", &choice) != 1) {
            printf("Помилка введення! Спробуйте ще раз.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
        case 1: task_1(); break;
        case 2: task_2(); break;
        case 3: task_3(); break;
        case 4: task_4(); break;
        case 5: task_5(); break;
        case 6: task_6(); break;
        case 7: task_7(); break;
        case 8: task_8(); break;
        case 9: task_9(); break;
        case 10: task_10(); break;
        case 0: printf("Вихід з програми. До побачення!\n"); break;
        default: printf("Невірний вибір! Оберіть число від 0 до 10.\n");
        }
    } while (choice != 0);

    return 0;
}