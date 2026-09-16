// 아두이노: RGB 픽셀값 수신 후 RGB LED 제어

#define RedLED 11
#define GreenLED 5
#define BlueLED 3

void setup() {
  pinMode(RedLED, OUTPUT);
  pinMode(GreenLED, OUTPUT);
  pinMode(BlueLED, OUTPUT);
  Serial.begin(9600);
  while (Serial.available() == 0) {  // 수신 버퍼에 수신값이 없는 동안 반복 실행
    Serial.write('A');      // 시작신호 전송
    delay(300);       // 0.3초 대기
  }
}

void loop( ) { }

void serialEvent() {        // 이벤트함수: 수신값이 있으면 자동 호출
  int r = Serial.readStringUntil(',').toInt();  // 첫 번째 콤마까지의 문자열을 정수로 변환
  int g = Serial.readStringUntil(',').toInt();  // 그다음 콤마까지의 문자열을 정수로 변환
  int b = Serial.readStringUntil('\n').toInt(); // 개행까지의 문자열을 정수로 변환
  analogWrite(RedLED, r);
  analogWrite(GreenLED, g);
  analogWrite(BlueLED, b);
  Serial.write('B');        // 송신
}
