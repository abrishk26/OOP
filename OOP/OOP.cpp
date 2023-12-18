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
    clockType(int = 0, int = 0, int = 0); //Constructor with parameter
    //clockType(); //Default constructor

private:
    int hr;
    int min;
    int sec;

};

int main()
{
    clockType myClock(5, 12, 40); //class object 1 with constructor
    clockType yourClock(2, 59, 59); //class object 2

    int hours;
    int minutes;
    int seconds;

    myClock.setTime(5, 4, 30);

    cout << "myClock: ";
    myClock.printTime();
    cout << endl;

    cout << "yourClock: ";
    yourClock.printTime();
    cout << endl;

    yourClock.setTime(5, 45, 16);

    cout << "After setting, yourClock: ";
    yourClock.printTime();
    cout << endl;

    if (myClock.equalTime(yourClock))
        cout << "Both times are equal." << endl;
    else
        cout << "The two times are not equal" << endl;

    cout << "Enter the hours, minutes, and seconds: ";
    cin >> hours >> minutes >> seconds;
    cout << endl;

    //Set the time of myClock using the value of the variables hours, minutes, and seconds
    
    myClock.setTime(hours, minutes, seconds);

    cout << "New myClock: ";
    myClock.printTime();
    cout << endl;

    //Increment the time of myClock by one second
    myClock.incrementSeconds();

    cout << "After incrementing myclock by one second, myclock: ";
    myClock.printTime();
    cout << endl;

    //Retrieve the hours, minutes, and seconds of the object myClock.
    myClock.getTime(hours, minutes, seconds);

    //Output the vallue of hours, minutes, and seconds
    cout << "hours = " << hours << ", minutes = " 
            << minutes << ", seconds = "    
            << seconds << endl;
    return 0;
}

void clockType::setTime(int hours, int minutes, int seconds) //Mutator function
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
 
void clockType::getTime(int& hours, int& minutes, int& seconds) const //Accessor function
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

clockType::clockType(int hours, int minutes, int seconds)
{
    setTime(hours, minutes, seconds);
}








