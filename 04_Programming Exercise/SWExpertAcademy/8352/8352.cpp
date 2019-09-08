#include <cstdio>
#include <cstring>

bool leapYear(int year)
{
    if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
        return true;
    return false;
}

int monthDay(int d, bool leapyear = false)
{
    if (d == 1 || d == 3 || d == 5 || d == 7 || d == 8 || d == 10 || d == 12)
        return 31;
    else if (d == 2 || d == 4 || d == 6 || d == 9 || d == 11)
        return 30;
    else
        if (!leapyear)
            return 28;
        else
            return 29;
}

void dayOffset(long offset, int &year, int &month, int &day)
{
    if (leapYear(year) && month == 2 && day == 29 && offset > 0)
    {
        offset--;
        month = 3;
        day = 1;
    }

    while (offset >= 365)
    {
        if ((leapYear(year + 1) && month >= 3) || (leapYear(year) && month <= 2))
        {
            offset -= 366;
            year += 1;
        }
        else
        {
            offset -= 365;
            year += 1;
        }
    }

    while (offset > 28)
    {
        offset -= monthDay(month, leapYear(year));
        month += 1;
        if (month == 13)
        {
            year += 1;
            month = 1;
        }
    }

    while (offset > 0)
    {
        offset--;
        day++;
        if (day > monthDay(month, leapYear(year)))
        {
            day = 1;
            month++;
        }
        if (month == 13)
        {
            month = 1;
            year++;
        }
    }
}

void secOffset(long offset, int &year, int &month, int &day, int &hour, int &minute, int &second)
{
    long days = offset / 86400;
    int secOffset = offset % 86400;
    
    dayOffset(days, year, month, day);
    
    int hours = secOffset / 3600;
    int minutes = (secOffset % 3600) / 60;
    int seconds = (secOffset % 3600) % 60;

    hour += hours;
    minute += minutes;
    second += seconds;

    int quot;
    quot = second / 60;
    second %= 60;
    minute += quot;
    quot = minute / 60;
    minute %= 60;
    hour += quot;
    quot = hour / 24;
    hour %= 24;
    dayOffset(quot, year, month, day);
}

int main(void)
{
    freopen("input.txt", "r", stdin);
    int year, month, day, hour, minute, second;
    long offset_;
    char date[40], time[40], offset[40];
    char strbuf[10];
    int tcCnt;
    scanf("%d", &tcCnt);

    for (int tc = 1; tc <= tcCnt; tc++)
    {
        scanf("%d/%02d/%02d %02d:%02d:%02d", &year, &month, &day, &hour, &minute, &second);
        scanf("%s", offset);
        
        offset_ = 1;
        for (int i = 0; i < strlen(offset); i++)
            offset_ <<= 1;
        offset_ -= 1;
        
        secOffset(offset_, year, month, day, hour, minute, second);

        printf("#%d %4d/%02d/%02d %02d:%02d:%02d \n", tc, year, month, day, hour, minute, second);
    }

    return 0;
}