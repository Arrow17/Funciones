/*
 * File:   trian.c
 * Author: francisco
 *
 * Created on 29 de mayo de 2019, 12:19 PM
 */
#include "TRIANGULAR.h"

void PWM_1 (int canal,int duty){
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

 void  TRIAN_GENERAR_1() {
    //configuracion de Frecuencia
    OSCCON= 0b01100111; 
    //delcaracion de entrada y salida
    // PWM a 10khz y 40% de ciclo util
    int calculos;
    int seno [20]= {10,20,30,40,50,60,70,80,90,100,90,80,70,60,50,40,30,20,10,0};
    int i,j;
   while(PORTAbits.RA0==1){
        for (i=0;i<20;i++)
        {    
        PWM_1(1, seno[i]);    
        }
    }
    return;
}
 
  void  TRIAN_GENERAR_2() {
    //configuracion de Frecuencia
    OSCCON= 0b01100111; 
    //delcaracion de entrada y salida
    // PWM a 10khz y 40% de ciclo util
    int seno [18]= {11,22,33,44,56,67,78,89,100,89,78,67,56,44,33,22,11,0};
    int i;
   while(PORTAbits.RA0==1){
        for (i=0;i<18;i++)
        {    
        PWM_1(1, seno[i]);    
        }
    }
    return;
}
  
 void TRIAN_GENERAR_3() {
    //configuracion de Frecuencia
    OSCCON= 0b01100111; 
    //delcaracion de entrada y salida
    // PWM a 10khz y 40% de ciclo util
    int seno [15]={13,27,40,53,67,80,93,100,93,80,67,53,40,27,13};
  
    int i;
    while(PORTAbits.RA0==1){
        for (i=0;i<15;i++)
        {    
        PWM_1(1, seno[i]);    
        }
    }
    return;
}
