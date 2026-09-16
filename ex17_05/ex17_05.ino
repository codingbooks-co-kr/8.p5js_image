write// 아두이노: 수신된 정수로 부저음 제어

#define BUZZER 13

void setup() {
  pinMode(BUZZER, OUTPUT);
  Serial.begin(9600);
  while (Serial.available() == 0) {  // 수신 버퍼에 수신값이 없는 동안 반복 실행
    Serial.write('A');      // 시작신호 전송
    delay(300);           // 0.3초 대기
  }
}

void loop() { }

void serialEvent() {          // 이벤트함수: 수신값이 있으면 자동 호출
  int value = Serial.read();    // 수신
  if (value == 1) tone(BUZZER, 330);  // 수신값이 1이면 330Hz 주파수음
  else noTone(BUZZER);    // 수신값이 0이면 무음
  Serial.write('B');              // 송신
}
