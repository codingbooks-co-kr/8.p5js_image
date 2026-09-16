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

void serialEvent() {    // 이벤트함수: 수신값이 있으면 자동 호출
  int r = Serial.parseInt();  // 수신 문자열의 첫 번째 숫자문자 추출 후 정수로 저장
  int g = Serial.parseInt();  // 수신 문자열의 두 번째 숫자문자 추출 후 정수로 저장
  int b = Serial.parseInt();  // 수신 문자열의 세 번째 숫자문자 추출 후 정수로 저장

  analogWrite(RedLED, r);
  analogWrite(GreenLED, g);
  analogWrite(BlueLED, b);
  Serial.write('B');    // 송신
}
