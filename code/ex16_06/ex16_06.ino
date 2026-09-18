// 아두이노: 픽셀값 수신하여 RGB LED 제어, 가변저항값 및 버튼값 송신

#define VARIABLE_R A1
#define BUTTON 2
#define RedLED 11
#define GreenLED 5
#define BlueLED 3

void setup() {
  pinMode(VARIABLE_R, INPUT);
  pinMode(BUTTON, INPUT);
  pinMode(RedLED, OUTPUT);
  pinMode(GreenLED, OUTPUT);
  pinMode(BlueLED, OUTPUT);
  Serial.begin(9600);
  while (Serial.available() == 0) {  // 수신 버퍼에 수신값이 없는 동안 반복 실행
    Serial.println('A');      // 시작신호 전송
    delay(300);             // 0.3초 대기
  }
}

void loop() { }

void serialEvent() {          // 이벤트함수: 수신값이 있으면 자동 호출
  int r = Serial.parseInt();  // 수신 문자열 중 첫 번째 숫자문자 추출 후 정수로 저장
  int g = Serial.parseInt();  // 수신 문자열 중 두 번째 숫자문자 추출 후 정수로 저장
  int b = Serial.parseInt();  // 수신 문자열 중 세 번째 숫자문자 추출 후 정수로 저장
  analogWrite(RedLED, r);
  analogWrite(GreenLED, g);
  analogWrite(BlueLED, b);

  int value1 = analogRead(VARIABLE_R);
  int value2 = digitalRead(BUTTON);
  Serial.print(value1);
  Serial.print(',');
  Serial.println(value2);   // 송신(→문자열: 'value1,value2\n')
}
