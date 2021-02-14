#include "Chassis.h"

/*
 * Assume the robot drives about 12 inches / second* 
 * Take the number of inches, divide by 12 and drive that long 
 * 
 * */ 

void Chassis::driveDistance(float inches) 
{     
    encoders.getCountsAndResetLeft();
    encoders.getCountsAndResetRight();

    while(encoders.getCountsRight() <  CPR * inches)
    {
        int rightCount = encoders.getCountsRight();
        int leftCount = encoders.getCountsLeft();
        int err = rightCount - leftCount;
        motors.setEfforts(100 - (err * errCoeff), 100 + (err * errCoeff));     
    }
    motors.setEfforts(0,0);

}

/** 
 * * Assume the robot turns at about 180 degrees per second 
 * */ 

void Chassis::turnAngle(float degrees) 
{     
    encoders.getCountsAndResetLeft();
    encoders.getCountsAndResetRight();

    while (encoders.getCountsLeft() < ((CPR / 360) * degrees))
    {
        int rightCount = encoders.getCountsRight();
        int leftCount = encoders.getCountsLeft();
        int err = rightCount - leftCount;
        motors.setEfforts(100 - (err * errCoeff), -100 + (err * errCoeff)); 
    }
    motors.setEfforts(0,0);
         
} 