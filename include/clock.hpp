// Include once
#pragma once

// A class representing the game's clock.
class Clock{
    private:
        // An enum holding values for the Day and Night
        typedef enum {DAY, NIGHT} DayNight;

        // Holds either Day or Night.
        DayNight day_night;

        // The time.
        int time;

    public:
        // Creates a Clock object.
        Clock();

        // Returns true if it's day.
        bool IsDay();

        // Returns the time.
        int GetTime();

        // Updates the clock.
        void UpdateClock();

        // Draws the clock.
        void DrawClock();
        
        // Only used for debugging purposes.
        void Debug();
};