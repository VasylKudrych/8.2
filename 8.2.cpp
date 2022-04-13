﻿#define _CRT_SECURE_NO_WARNINGS 
#include <iostream> 

using namespace std;

string Rebuild(string str, string znaky)
{
    string rightPart = str;
    string result = "";
    int index = 0;
    int i = 1;

    while ((index = rightPart.find_first_of(znaky)) != -1)
    {
        while (isspace(rightPart[index - i]))
        {
            i++;
        }

        for (int j = 0; j < index - i + 1; j++)
        {
            result += rightPart[j];
        }
        result += rightPart[index];
        string c = "";
        c += rightPart[index + 1];
        while ((c.find_first_of(znaky)) == c[0])
        {
            result += rightPart[index++];
        }

        rightPart.erase(0, index + 1);
        i = 1;
    }

    result += rightPart;
    return result;
}

int main()
{
    char s[51];
    cout << "Enter String: ";
    cin.getline(s, 50);
    cout << endl;
    char znaky[] = ",.:;!?";

    string result = Rebuild(s, znaky);

    cout << result << endl;

    return 0;
}
