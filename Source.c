#define _CRT_SECURE_NO_DEPRECATE
#include <locale.h>
#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

#define ROW 9
#define COL 9

int task_1();
int task_1_2();
int task_1_3();
int task_2();
int task_3();

int main()
{
    //task_1();
    //task_1_2();
    //task_1_3();
    //task_2();
    task_3();
}


int task_1()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    int row, col;
    printf("\n");
    for (row = 1; row <= ROW; ++row)
    {
        for (col = 1; col <= COL; col++)
            printf("%5d", col * row);
        printf("\n");
    }
    system("pause");
}

int task_1_2()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    int row, col;
    printf("\n");
    for (row = 1; row <= ROW; ++row)
    {
        for (col = 1; col <= COL; col++)
        {
            if (col <= row)
                printf("%5d", col * row);
            else
                printf("     ");
        }
        printf("\n");
    }
    system("pause");
}

//#define ROW 5
//#define COL 10
int task_1_3()
{
    //8 вариант
    setlocale(LC_ALL, "ru_RU.UTF-8");
    int row, col;
    printf("\n");
    for (row = 1; row <= ROW; ++row)
    {
        for (col = 1; col <= COL; col++)
        {
            if (col <= row)
                printf("%5d", row * 10);
            else
                printf("     ");
        }
        printf("\n");
    }
    system("pause");
}


int task_2()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    char num[100];
    char choice;

    do {
        printf("Введите число: ");
        scanf("%s", num);

        int len = strlen(num);
        int d[100];

        for (int i = 0; i < len; i++)
        {
            d[i] = num[i] - '0';
        }

        int c3 = 0;
        for (int i = 0; i < len; i++)
        {
            if (d[i] == 3) c3++;
        }
        printf("1) Количество цифр 3: %d\n", c3);

        int last = d[len - 1];
        int lastp = 0;
        for (int i = 0; i < len; i++)
        {
            if (d[i] == last) lastp++;
        }
        printf("2) Последняя цифра %d повторяется: %d раз\n", last, lastp);

        int cchet = 0;
        for (int i = 0; i < len; i++)
        {
            if (d[i] % 2 == 0) cchet++;
        }
        printf("3) Количество чётных цифр: %d\n", cchet);

        int c5 = 0;
        for (int i = 0; i < len; i++)
        {
            if (d[i] > 5) c5++;
        }
        printf("4) Количество цифр больше 5: %d\n", c5);

        int sum_n = 0;
        for (int i = 0; i < len; i++)
        {
            if (d[i] % 2 == 1) sum_n += d[i];
        }
        printf("5) Сумма нечётных цифр: %d\n", sum_n);

        int sum7 = 0;
        for (int i = 0; i < len; i++)
        {
            if (d[i] >= 7) sum7 += d[i];
        }
        printf("6) Сумма цифр больше или равно 7: %d\n", sum7);

        int pr = 1;
        for (int i = 0; i < len; i++)
        {
            if (d[i] != 0) pr *= d[i];
        }
        printf("7) Произведение всех цифр, исключая 0: %d\n", pr);

        if (len >= 2)
        {
            int nahalo2 = d[1];
            int konec2 = d[len - 2];
            printf("8) %d * %d = %d\n", nahalo2, konec2, nahalo2 * konec2);
        }
        else
        {
            printf("8) Недостаточно цифр\n");
        }

        int sum_ch = 0;
        for (int i = 0; i < len - 1; i++)
        {
            if (d[i] % 2 == 0) sum_ch += d[i];
        }
        printf("9) Сумма чётных цифр, исключая последнюю: %d\n", sum_ch);

        int odinac = 0;
        for (int i = 0; i < len - 1; i++)
        {
            if (d[i] == d[i + 1]) odinac++;
        }
        printf("10) Количество рядом расположенных одинаковых цифры: %d\n", odinac);

        int pol = len / 2;
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < pol; i++) sum1 += d[i];
        for (int i = len - pol; i < len; i++) sum2 += d[i];
        printf("11) %d и %d - %s\n", sum1, sum2, sum1 == sum2 ? "равны" : "не равны");

        int s_ch = 0, s_nch = 0;
        for (int i = 0; i < len; i++)
        {
            int razrad = len - i;
            if (razrad % 2 == 0) s_ch += d[i];
            else s_nch += d[i];
        }
        printf("12) Чётных(%d) * Нечётных(%d) = %d\n", s_ch, s_nch, s_ch * s_nch);


        printf("Продолжить ? (Да - y, нет - n)");
        while (getchar() != '\n');
        choice = getchar();
    } while (choice == 'y' || choice == 'Y');

    return 0;
}

int task_3()
{
    //8 вариант
    setlocale(LC_ALL, "ru_RU.UTF-8");
    char sim;
    double a;
    int s;
    int choice;

    do {
        printf("Введите символ из которого будет строится фигура: ");
        scanf(" %c", &sim);

        printf("Введите угол a (острый): ");
        scanf("%lf", &a);

        printf("Введите сторону s: ");
        scanf("%d", &s);

        int h = (int)(s * tan(a * 3.14159 / 180) / 2);
        if (h < 2) h = 2;
        printf("\n");

        for (int i = 0; i < h; i++)
        {
            int chir = (i + 1) * s / h;
            int ots = (s - chir) / 2;

            for (int j = 0; j < ots; j++)
                printf(" ");

            for (int j = 0; j < chir; j++)
                printf("%c", sim);

            printf("\n");
        }

        printf("\nПродолжить? (1 - да, 0 - нет): ");
        scanf("%d", &choice);

    } while (choice == 1);

}


