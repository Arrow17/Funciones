#define XTAL_FREQ 8000000 //8Mhz
void tm_1s();

void tm_1s(){
    int i;
    for(i=0;i<20;i++){
        __delay_ms(50);
    }
}