#include "Movement.h"

namespace Movement
{
    static const int rightFront_Forward = 26;
    static const int rightBack_Forward = 5;
    static const int leftFront_Forward = 16;
    static const int leftBack_Forward = 12;
    
    static const int rightFront_Backward = 20;
    static const int rightBack_Backward = 13;
    static const int leftFront_Backward = 19;
    static const int leftBack_Backward = 6;
    
    static const int enable = 21;

    void setup()
    {
        gpioInitialise();

        gpioSetMode(rightFront_Forward, PI_OUTPUT);
        gpioSetMode(rightBack_Forward, PI_OUTPUT);
        gpioSetMode(leftFront_Forward, PI_OUTPUT);
        gpioSetMode(leftBack_Forward, PI_OUTPUT);

        gpioSetMode(rightFront_Backward, PI_OUTPUT);
        gpioSetMode(rightBack_Backward, PI_OUTPUT);
        gpioSetMode(leftFront_Backward, PI_OUTPUT);
        gpioSetMode(leftBack_Backward, PI_OUTPUT);
        gpioSetMode(enable, PI_OUTPUT);

        offMotors();
        gpioSetPWMrange(enable, 100)
        gpioPWM(enable, 100);
    }

    void cleanup()
    {
        gpioTerminate();
    }

    void offMotors()
    {
        gpioWrite(rightFront_Forward, 0);
        gpioWrite(rightBack_Forward, 0);
        gpioWrite(leftFront_Forward, 0);
        gpioWrite(leftBack_Forward, 0);

        gpioWrite(rightFront_Backward, 0);
        gpioWrite(rightBack_Backward, 0);
        gpioWrite(leftFront_Backward, 0);
        gpioWrite(leftBack_Backward, 0);
    }

    void movementTest()
    {
        moveForward(runTime);
        wait(waitTime);
        moveBackward(runTime);
        wait(waitTime);
        turnRight(turnTime);
        wait(waitTime);
        turnLeft(turnTime);
        wait(waitTime);
        moveRight(runTime);
        wait(waitTime);
        moveLeft(runTime);
    }

    void PWMtest()
    {
        gpioPWM(enable, 0);

        for(int i = 1; i <= 10; i ++)
        {
            gpioPWM(enable, i * 10);
            moveForward(1);
        }
    }

    void moveForward(int inputRunTime)
    {
        gpioWrite(rightFront_Forward, 1);
        gpioWrite(leftFront_Forward, 1);
        gpioWrite(leftBack_Forward, 1);
        gpioWrite(rightBack_Forward, 1);

        printf("Moving Forward");
        gpioDelay(inputRunTime);
        offMotors();
    }

    void moveBackward(int inputRunTime)
    {
        gpioWrite(rightFront_Backward, 1);
        gpioWrite(leftFront_Backward, 1);
        gpioWrite(rightBack_Backward, 1);
        gpioWrite(leftBack_Backward, 1);
        
        printf("Moving Backward");
        gpioDelay(inputRunTime);
        offMotors();
    }
        
    void turnRight(int inputTurnTime)
    {
        gpioWrite(leftFront_Forward, 1);
        gpioWrite(leftBack_Forward, 1);
        gpioWrite(rightFront_Backward, 1);
        gpioWrite(rightBack_Backward, 1);
        
        printf("Turning Right");
        gpioDelay(inputTurnTime);
        offMotors();
    }

    void turnLeft(int inputTurnTime)
    {
        gpioWrite(rightFront_Forward, 1);
        gpioWrite(rightBack_Forward, 1);
        gpioWrite(leftFront_Backward, 1);
        gpioWrite(leftBack_Backward, 1);
        
        printf("Turning Left");
        gpioDelay(inputTurnTime);
        offMotors();
    }

    void moveRight (int inputTurnTime)
    {
        gpioWrite(rightBack_Forward, 1);
        gpioWrite(leftFront_Forward, 1);
        gpioWrite(rightFront_Backward, 1);
        gpioWrite(leftBack_Backward, 1);
        
        printf("Moving Right");
        gpioDelay(inputTurnTime);
        offMotors();
    }

    void moveLeft(int inputTurnTime)
    {
        gpioWrite(rightFront_Forward, 1);
        gpioWrite(leftBack_Forward, 1);
        gpioWrite(rightBack_Backward, 1);
        gpioWrite(leftFront_Backward, 1);
        
        printf("Moving Left");
        gpioDelay(inputTurnTime);
        offMotors();
    }

    void wait(int inputWaitTime)
    {
        printf("Waiting");
        gpioDelay(inputWaitTime);
    }
}