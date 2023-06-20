void dichuyen (int d1 , int d2 , int d3 , int d4 ,int xungA, int xungB , int xungC , int xungD) {
  digitalWrite(DIR1, d1);analogWrite(PWM1, pwm(xungA));
  digitalWrite(DIR2, d2);analogWrite(PWM2, pwm(xungB));
  digitalWrite(DIR3, d3);analogWrite(PWM3, pwm(xungC));
  digitalWrite(DIR4, d4);analogWrite(PWM4, pwm(xungD));}
//dichuyen**************************************************************************************************
void tien (int x){if(up    && !down  && !right && !left  && !pink &&  !red  && !green && !blue && !R1) {  ShowLCD("Di Tien ");dichuyen( HIGH , LOW  , LOW  , HIGH ,x,x,x,x);}}
void lui  (int x){if(down  && !up    && !right && !left  && !pink &&  !red  && !green && !blue && !R1) {  ShowLCD("di lui  ");dichuyen (  LOW , HIGH , HIGH , LOW  ,x,x,x,x);}}
void phai (int x){if(right && !up    && !down  && !left  && !pink &&  !red  && !green && !blue && !R1) {  ShowLCD("rephai  ");dichuyen ( HIGH , HIGH , LOW  , LOW  ,x,x,x,x);}}
void trai (int x){if(left  && !up    && !down  && !right && !pink &&  !red  && !green && !blue && !R1) {  ShowLCD("retrai  ");dichuyen ( LOW  , LOW  , HIGH, HIGH  ,x,x,x,x);}}
void dung ()     {if(!up   && !down  && !right && !left  && !pink && !red   && !green && !blue && !R1 && !L1) { ShowLCD("stop    ");  dichuyen ( HIGH , LOW  , LOW  , HIGH ,0,0,0,0);}}
void xoayl(int x){if(L1    && !up    && !down  && !right && !left && !pink  &&  !red  && !green && !blue && !R1){ShowLCD("xoaytrai");dichuyen (LOW ,LOW , LOW , LOW  ,x,x,x,x);}}
void xoayr(int x){if(R1    && !up    && !down  && !right && !left && !pink  &&  !red  && !green && !blue && !L1){ShowLCD("xoayphai");dichuyen ( HIGH,HIGH, HIGH, HIGH  ,x,x,x,x);}}
//**************************************************************************************************************
void  Speed(){int j = 40;            tien(j);lui(j);trai(j);phai(j);dung();}
void  Move(){int q = 18 ;int a = 10; tien(q);lui(q);trai(q);phai(q);xoayl(a);xoayr(a);dung();}
