#include "Arduino.h"
#include "HardwareSerial.h"
void HanhTrinhGapVong() {
  //DemHT1
  while (b3 == 0) {
    while (b3 == 0) {
      GoiLaiBien();  //DemHT2
      if (b3 == 0 && !(b4 == 0) && DemHT1 == 0) {
        analogWrite(PWM5, pwm(0));
        Serial.println("Dung dong co 5");
      }
      while (b4 == 0) {
        DemHT1++;
        DemHT2++;
        while (b4 == 0) {
          GoiLaiBien();
          digitalWrite(DIR5, HIGH);  //reset động cơ lồng trái
          analogWrite(PWM5, pwm(55));
          digitalWrite(DIR7, HIGH);  //reset động cơ lồng trái
          analogWrite(PWM7, pwm(55));
          Serial.println("Xuong");
          lcd.setCursor(13, 3);
          lcd.print("NO RING");
        }
      }
    }
  }

  // Serial.print("DemHt1 = ");
  // Serial.println(DemHT1);
  // Serial.print("DemHt2 = ");
  // Serial.println(DemHT2);
  if (b4 == 0 && !(b3 == 0) && DemHT1 == 0) {
    analogWrite(PWM7, pwm(0));
    Serial.println("Dung dong co 7");
  }
  GoiLaiBien();
  Serial.println(DemL1);
  if ((DemL1 == 0 && b1 == 1 && b2 == 1 && b5 == 1) || (b6 == 1 && DemL1 == 0)) {
    digitalWrite(DIR5, HIGH);  //reset động cơ lồng trái
    analogWrite(PWM5, pwm(50));
    digitalWrite(DIR7, HIGH);  //reset động cơ lồng phải
    analogWrite(PWM7, pwm(50));
    digitalWrite(DIR6, LOW);  //reset động cơ kẹp vòng
    analogWrite(PWM6, pwm(50));
    lcd.setCursor(13, 3);
    lcd.print("RSETDC ");
  }

  if (b1 == 0) {
    analogWrite(PWM7, pwm(0));
    //Serial.println("dung MT7");
  }
  if (b2 == 0) {
    analogWrite(PWM5, pwm(0));
    //Serial.println("dung MT5");
  }
  if ((b5 == 0)) {
    analogWrite(PWM6, pwm(0));
    //Serial.println("dung MT6");
  }
  if (b6 == 0) {
    digitalWrite(xilanhkep, LOW);
    digitalWrite(DIR6, LOW);
    analogWrite(PWM6, pwm(20));
  }
  if (DemL1 == 1) {
    digitalWrite(xilanhnangcocau, HIGH);  //hạ cơ cấu
    // lcd.setCursor(13, 3);
    // lcd.print("STEP1    ");
  } else if (DemL1 == 2) {
    digitalWrite(xilanhnangcocau, LOW);  // nâng cơ cấu
    // lcd.setCursor(13, 3);
    // lcd.print("STEP2    ");
    if ((cambien1 == 1 && cambien2 == 1 && b5 == 0 && DemHT1 == 0 && b4 == 1 && b3 == 1)) {
      digitalWrite(DIR5, LOW);  //nâng động cơ lồng trái
      analogWrite(PWM5, pwm(60));
      digitalWrite(DIR7, LOW);  //nâng động cơ lồng phải
      analogWrite(PWM7, pwm(50));
      delay(50);
      Serial.println("Len lien tuc");
      lcd.setCursor(13, 3);
      lcd.print("LIFT    ");
    }
    if (cambien1 == 0) {  //Doi lai;
      analogWrite(PWM7, pwm(0));
      Serial.println("Dung tai cam bien");
    }
    if( cambien2 == 0){
      analogWrite(PWM5, pwm(0));
    }
  }
    if(cambien1 == 0){
      lcd.setCursor(13, 2);
      lcd.print("TC1");
    }else
      {lcd.setCursor(13, 2);
      lcd.print("   ");}
    if(cambien2 == 0){
      lcd.setCursor(17, 2);
      lcd.print("TC2");
    }else {
      lcd.setCursor(17, 2);
      lcd.print("   ");
    }
}
//napvong
void Napvong(int nutnap) {
  if (nutnap && !red && !blue && !green) {
    digitalWrite(xilanhnapvong, LOW);
  } else {
    digitalWrite(xilanhnapvong, HIGH);
  }
}
//kepvong
void kep() {
  GoiLaiBien();
  if (start) {
    delay(50);
    if (start) {
      Serial.println("kepvong");
      if (b5 == 0) {
        digitalWrite(xilanhkep, HIGH);
        delay(50);
        digitalWrite(DIR6, HIGH);  //reset động cơ kẹp vòng
        analogWrite(PWM6, pwm(20));
      }
    }
    while (start) {
      GoiLaiBien();
      Serial.print(start);
    }
  }
}
//vỗ vòng
void vovo(int nutnhan) {
  if (nutnhan) {
    delay(50);
    if (nutnhan) {
      if (vovong == true) vovong = false;
      else vovong = true;
      digitalWrite(xilanhkepvong, vovong);
    }
    while (red) {
      GoiLaiBien();Serial.print("vovong");
Serial.println(vovong);
      Serial.print(nutnhan);
    }
  }
}

//Xilanh điện
void Xilanhdien(int nang, int ha) {
  if (nang) {
    digitalWrite(RELAY9, HIGH);
    digitalWrite(RELAY10, LOW);
  } else if (ha) {
    digitalWrite(RELAY9, LOW);
    digitalWrite(RELAY10, HIGH);
  } else {
    digitalWrite(RELAY9, HIGH);
    digitalWrite(RELAY10, HIGH);
  }
}
 
