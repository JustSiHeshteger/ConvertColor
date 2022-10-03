#pragma once
#include <ctype.h>

class Convert
{
public:
	static int ToInt32(char str[])
	{
		int length = Convert::GetLength(str), index = 0, temp = 0;
		bool isNegative = false;

		if (str[0] == '-')
		{
			isNegative = true;
			index++;
		}

		while (str[index] >= 0x30 && str[index] <= 0x39)
		{
			temp += (str[index] & 0x0F);
			temp *= 10;
			index++;
		}

		temp /= 10;

		if (isNegative)
			temp = -temp;

		return temp;
	}

	static bool CheckNumberOnInt(char str[])
	{
		int length = Convert::GetLength(str), index = 0;
		bool isNegative = false, dot = false;

		if (str[0] == '-')
		{
			isNegative = true;
			index++;
		}

		while (index != length)
		{
			if (str[index] == '-')
			{
				if (isNegative)
					return false;
				else
					isNegative = true;
			}
			else if (str[index] == '.')
			{
				if (!dot)
					dot = true;
				else
					return false;
			}
			else if (!isdigit(str[index]))
			{
				return false;
			}
			else if (dot)
			{
				if (str[index] != '0')
					return false;
			}

			index++;
		}

		return true;
	}

	static int GetLength(char str[])
	{
		int index = 0;

		while (str[index] != 0x00)
			index++;

		return index;
	}
};

