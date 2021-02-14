#pragma once
#include "Romi32U4.h"


class Chassis { 
    public:     
        void driveDistance(float inches);     
        void turnAngle(float degrees);     
        const float wheelDiameter = 2.8;     
        const int CPR = 1440;     
        const float wheelTrack = 5.75; 
        const float errCoeff = 0.05;

    private:     
        Romi32U4Motors motors;     
        Romi32U4Encoders encoders; 
}; 