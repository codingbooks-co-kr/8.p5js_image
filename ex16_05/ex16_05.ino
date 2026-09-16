// 아두이노: 이진화 픽셀값(→흑백) 수신하여 LED 점멸 제어, 가변저항값 송신

#define VARIABLE_R A1
#define LED 6

void setup() {
  pinMode(VARIABLE_R, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  while (Serial.available() == 0) {  // 수신 버퍼에 수신값이 없는 동안 반복 실행
    Serial.write('A');      // 시작신호 전송
    delay(300);           // 0.3초 대기
  }
}

void loop() { }

void serialEvent() {          // 이벤트함수: 수신값이 있으면 자동 호출
  int value1 = Serial.read();     // 이진화 픽셀값 수신
  analogWrite(LED, value1);     // 수신값으로 LED 밝기 제어
  int value2 = analogRead(VARIABLE_R);  // 가변저항값 읽기
  value2 = map(value2, 0, 1023, 0, 255);  // 가변저항값 범위를 0∼255로 변환
  Serial.write(value2);       // 가변저항값 송신
}
