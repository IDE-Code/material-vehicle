#include "pid.h"

int16_t PWM1,PWM2,PWM3;

void M1_Speed_Ctr(int sp)
{
    static float Kp=50.0f,Ki=5.0f,Kd=0.0f;
    static int16_t PWM=0,Error=0,Last_Error=0,Last_Last_Error=0;

    Error=sp-T5_Encoder_Value;
    PWM+= Kp*(Error-Last_Error) + Ki*Error + Kd*(Error-2*Last_Error+Last_Last_Error);
    Last_Last_Error = Last_Error;
    Last_Error = Error;
    if(PWM>8000)PWM=8000;
    if(PWM<-8000)PWM=-8000;
		PWM1=PWM;
    M1_PWM_Set((int16_t)PWM);
}

void M2_Speed_Ctr(int sp)
{
    static float Kp=100.0f,Ki=5.0f,Kd=0.0f;
    static int16_t PWM=0,Error=0,Last_Error=0,Last_Last_Error=0;

    Error=sp-T2_Encoder_Value;
    PWM+= Kp*(Error-Last_Error) + Ki*Error + Kd*(Error-2*Last_Error+Last_Last_Error);
    Last_Last_Error = Last_Error;
    Last_Error = Error;
    if(PWM>8000)PWM=8000;
    if(PWM<-8000)PWM=-8000;
		PWM2=PWM;
    M2_PWM_Set((int16_t)PWM);
}

void M3_Speed_Ctr(int sp)
{
    static float Kp=50.0f,Ki=5.0f,Kd=0.0f;
    static int16_t PWM=0,Error=0,Last_Error=0,Last_Last_Error=0;

    Error=sp-T3_Encoder_Value;
    PWM+= Kp*(Error-Last_Error) + Ki*Error + Kd*(Error-2*Last_Error+Last_Last_Error);
    Last_Last_Error = Last_Error;
    Last_Error = Error;
    if(PWM>8000)PWM=8000;
    if(PWM<-8000)PWM=-8000;
		PWM3=PWM;
    M3_PWM_Set((int16_t)PWM);
}





