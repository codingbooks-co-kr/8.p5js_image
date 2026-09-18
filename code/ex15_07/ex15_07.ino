// 서보모터 각도 제어

#include <Servo.h>    // Servo 클래스가 선언된 헤더파일 가져오기
#define SERVO A0
Servo servo;      // Servo 클래스를 이용한 servo 객체의 선언 및 생성

void setup() {
  pinMode(SERVO, OUTPUT);
  servo.attach(SERVO);    // SERVO핀(→A0)을 servo 객체에 연결
}

void loop() {
  servo.write(0);   // 0도 설정
  delay(2000);
  servo.write(90);    // 90도 설정
  delay(2000);
  servo.write(180);   // 180도 설정
  delay(2000);
}
