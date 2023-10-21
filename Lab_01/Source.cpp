//Tigran Manukyan
#include <iostream>
using namespace std;

class clockType
{
    public:
        void setTime(int, int, int);
        void printTime() const;
    private:
        int hr;
        int min;
        int sec;
};

void clockType::setTime(int hours, int minutes, int seconds){
    if(0 <= hours && hours <24)
        hr = hours;
    else
        hr = 0;
    if(0 <= minutes && minutes <60)
        min = minutes;
    else
        min = 0;
    if(0 <= seconds && seconds <60)
        sec = seconds;
    else
        sec = 0;
        
}

void clockType::printTime() const{
    if(hr< 10)
        cout << "0";
    cout << hr << ":";
    if(min< 10)
        cout << "0";
    cout << min << ":";
    if(sec<10)
        cout << "0";
    cout << sec;
    
    cout << endl;
}

int main(){
    clockType myClock;
    clockType yourClock;
    
    myClock.setTime(5, 4, 30);
    myClock.printTime();
    
    yourClock.printTime();
    
    yourClock.setTime(5, 45, 15);
    yourClock.printTime();
    
    system("pause");
    return 0;
}
