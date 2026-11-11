#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

// Перевірка наявності хоча б однієї з пар "no" або "on"
bool Include(const char* str)
{
    if (strlen(str) < 2)
        return false;

    for (size_t i = 0; str[i + 1] != '\0'; i++)
    {
        if ((str[i] == 'n' && str[i + 1] == 'o') ||
            (str[i] == 'o' && str[i + 1] == 'n'))
        {
            return true;
        }
    }
    return false;
}

// Заміна кожної пари "no" на "***"
char* Change(char* str)
{
    size_t len = strlen(str);
    if (len < 2)
        return str;

    // Виділяємо пам'ять із запасом, оскільки 2 символи "no" замінюються на 3 зірочки "***"
    char* tmp = new char[(int)(len * 1.5) + 1];
    char* t = tmp;
    *t = '\0';

    size_t i = 0;
    while (i < len && str[i + 1] != '\0')
    {
        if (str[i] == 'n' && str[i + 1] == 'o')
        {
            strcat(t, "***");
            t += 3;
            i += 2;
        }
        else
        {
            *t++ = str[i++];
            *t = '\0';
        }
    }

    // Дописуємо залишок рядка, якщо останній символ не був частиною "no"
    while (i < len)
    {
        *t++ = str[i++];
    }
    *t = '\0';

    strcpy(str, tmp);
    return tmp;
}

int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    if (Include(str))
        cout << "String contains 'no' or 'on'" << endl;
    else
        cout << "String DOES NOT contain 'no' or 'on'" << endl;

    char* dest = Change(str);
    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;

    return 0;
}