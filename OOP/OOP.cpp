
#include <iostream>
using namespace std;

class clockType 
{
public:
    void setTime(int, int, int);
    void getTime(int&, int&, int&) const;
    void printTime() const;
    void incrementSeconds();
    void incrementMinutes();
    void incrementHours();
    bool equalTime(const clockType&) const;

private:
    int hr;
    int min;
    int sec;

};

int main()
{
    clockType myClock;
    clockType yourClock;
 
    return 0;
}

void clockType::setTime(int hours, int minutes, int seconds)
{
    if (0 <= hours && hours < 24)
        hr = hours;
    else hr = 0;

    if (0 <= minutes && minutes < 60)
        min = minutes;
    else min = 0;

    if (0 <= seconds && seconds < 60)
        sec = seconds;
    else sec = 0;
}
 
void clockType::getTime(int& hours, int& minutes, int& seconds) const
{
    hours = hr;
    minutes = min;
    seconds = sec;
}

void clockType::printTime() const
{
    if (hr < 10)
        cout << "0";
    cout << hr << ":";
    if (min < 10)
        cout << "0";
    cout << min << ":";
    if (sec < 10)
        cout << "0";
    cout << sec;
}

void clockType::incrementHours()
{
    hr++;
        if (hr > 23)
            hr = 0;
}

void clockType::incrementMinutes()
{
    min++;
    if (min > 59)
    {
        min = 0;
        incrementHours();
    }
}

void clockType::incrementSeconds()
{
    sec++;
    if (sec > 59)
    {
        sec = 0;
        incrementMinutes();
    }

}

bool clockType::equalTime(const clockType& otherClock) const
{
    return (hr == otherClock.hr 
            && min == otherClock.min 
            && sec == otherClock.sec);
}



