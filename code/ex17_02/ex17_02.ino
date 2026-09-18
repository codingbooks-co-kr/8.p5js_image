// 아두이노: 수신된 정수로 RGB LED 제어

#define RedLED 11
#define GreenLED 5
#define BlueLED 3

void setup() {
  pinMode(RedLED, OUTPUT);
  pinMode(GreenLED, OUTPUT);
  pinMode(BlueLED, OUTPUT);
  Serial.begin(9600);
  while (Serial.available() == 0) {  // 수신 버퍼에 수신값이 없는 동안 반복 실행
    Serial.println('A');      // 시작신호 전송
    delay(300);       // 0.3초 대기
  }
}

void loop() { }

void serialEvent() {      // 이벤트함수: 수신값이 있으면 자동 호출
  int value = Serial.read();    // 수신
  if (value == 1) {
    setColor(1, 0, 0);      // Red LED 점등
  } else if (value == 2) {
    setColor(0, 1, 0);      // Green LED 점등
  } else if (value == 3) {
    setColor(0, 0, 1);      // Blue LED 점등
  }
  Serial.write('B');      // 송신
}

void setColor(int Red, int Green, int Blue) {
  digitalWrite(RedLED, Red);
  digitalWrite(GreenLED, Green);
  digitalWrite(BlueLED, Blue);
}
