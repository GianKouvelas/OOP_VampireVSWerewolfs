// Dependencies.
#include <iostream>
#include "../include/clock.hpp"


///////////////////////////////////////////
//
// The Clock's method implementations.
//
///////////////////////////////////////////

// Creates a Clock object.
Clock::Clock() {
    this->time = 0;
    this->day_night = NIGHT;
}

// Returns true if it's day.
bool Clock::IsDay() {
    return this->day_night == DAY;
}

// Returns the time.
int Clock::GetTime() {
    return this->time;
}

// Updates the clock.
void Clock::UpdateClock(){
    // Updates the time of the day. (One day only has 24 hours)
    if (this->time == 24) {
        this->time = 0;
    } else {
        this->time++;
    }

    // Updates the day_night variable
    if (this->time >= 6 && this->time <= 18) {
        this->day_night = DAY;
    } else {
        this->day_night = NIGHT;
    }
}

// Draws the clock.
void Clock::DrawClock() {
    // Prints the appropriate message depending on the time of the day.
    if (this->IsDay()) {
        std::cout<<"\033[97mTime : "<<this->time<<", "<<"Day\n";
    } else {
        std::cout<<"\033[97mTime : "<<this->time<<", "<<"Night\n";
    }
}

// Only used for debugging purposes.
void Clock::Debug(){
    std::cout<<"The time is : "<<this->time;
    if (this->day_night == DAY){
        std::cout<<" and it's DAY\n";
    } else {
        std::cout<<" and it's Night\n";
    }
}