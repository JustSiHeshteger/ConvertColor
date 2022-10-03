#include <iostream>
#include "Convert.h"

int C, M, Y, K; //В процентах от 0 до 100
int _max = 255;

bool CheckNumber(int num)
{
    if (num > 100 || num < 0)
        return false;

    return true;
}

void SetRGB(int index, int number)
{
    switch (index)
    {
    case 0:
        C = number;
        break;

    case 1:
        M = number;
        break;

    case 2:
        Y = number;
        break;

    case 3:
        K = number;
        break;

    default:
        std::cout << "Введены некорректные данные, попробуйте еще раз.\n" << std::endl;
    }
}

int main()
{
    setlocale(LC_ALL, "RUS");
    int countColors = 3, CMYK = 4;
    char cmyk[4] = { 'C', 'M', 'Y', 'K' };
    char str[11];


    for (int i = 0; i < countColors; i++)
    {
        printf("Введите %i цвет: \n", i + 1);
        for (int j = 0; j < CMYK; j++)
        {
            printf("Введите значение %c (целое число): ", cmyk[j]);

            std::cin >> str;
            if (!Convert::CheckNumberOnInt(str))
            {
                printf("Введены некорректные данные, попробуйте снова.\n");
                j--;
                continue;
            }

            int color = Convert::ToInt32(str);
            if (!CheckNumber(color))
            {
                printf("Число должно быть в промежутке [0, 100], попробуйте снова.\n");
                j--;
                continue;
            }

            SetRGB(j, color);
        }

        float k = (1 - K / 100.f);

        int R = (int)round(_max * (1 - C / 100.f) * k);
        int G = (int)round(_max * (1 - M / 100.f) * k);
        int B = (int)round(_max * (1 - Y / 100.f) * k);

        printf("Цвет в RGB модели (%i, %i, %i)\n\n", R, G, B);
    }

    system("pause");
    return 0;
}