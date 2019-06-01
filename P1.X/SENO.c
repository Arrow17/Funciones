/*
 * File:   sin.c
 * Author: francisco
 *
 * Created on 29 de mayo de 2019, 10:59 AM
 */


#include "SENO.h"

void PWM (int canal,int duty){
static bit BIT;   
    int calculos;
        if (_XTAL_FREQ==8000000){
            calculos= 3;
        }   T2CONbits.T2CKPS0=0;
            T2CONbits.T2CKPS1=0;
        PR2= calculos;
        calculos= duty*8;        
        calculos= calculos/100;
                       
        BIT= calculos;
        CCP1CONbits.DC1B0=BIT;
        calculos>>1;
        BIT=calculos;
        CCP1CONbits.DC1B1=BIT;
        CCPR1L=calculos >>1;    
    TRISCbits.RC2=0;    
    CCP1CONbits.CCP1M3=1;
    CCP1CONbits.CCP1M2=1;
    CCP1CONbits.CCP1M1=0;
    CCP1CONbits.CCP1M0=0;
    T2CONbits.TMR2ON=1;
    
}

 void  SENO_GENERAR_1() {
    //configuracion de Frecuencia
    OSCCON= 0b01100111; 
    //delcaracion de entrada y salida
    // PWM a 10khz y 40% de ciclo util
    int calculos;
    int seno [20]= {50,35,21,10, 2, 0, 2,10, 21, 35, 50, 65, 79, 90, 98, 100, 98, 90, 79, 65};
   // int seno [15]= {13,27,40,53,67,80,93,100,93,80,67,53,40,27,13};
    int i,j;
   while(PORTAbits.RA0==1){
        for (i=0;i<20;i++)
        {    
        PWM(1, seno[i]);    
        }
    }
    return;
}
 
  void  SENO_GENERAR_2() {
    //configuracion de Frecuencia
    OSCCON= 0b01100111; 
    //delcaracion de entrada y salida
    // PWM a 10khz y 40% de ciclo util
    int seno [18]= {50,67,82,93,99,99,93,82,67,50,33,18,7,1,1,7,18,33};
   // int seno [15]= {13,27,40,53,67,80,93,100,93,80,67,53,40,27,13};
    int i;
   while(PORTAbits.RA0==1){
        for (i=0;i<18;i++)
        {    
        PWM(1, seno[i]);    
        }
    }
    return;
}
  
 void  SENO_GENERAR_3() {
    //configuracion de Frecuencia
    OSCCON= 0b01100111; 
    //delcaracion de entrada y salida
    // PWM a 10khz y 40% de ciclo util
    int seno [15]={50,70,87,98,100,93,79,60,40,21,7,0,2,13,30};
  
    int i;
    while(PORTAbits.RA0==1){
        for (i=0;i<15;i++)
        {    
        PWM(1, seno[i]);    
        }
    }
    return;
}