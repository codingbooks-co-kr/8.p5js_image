// 아두이노: 가변저항값 송신

#define VARIABLE_R A1

void setup() {
  pinMode(VARIABLE_R, INPUT);
  Serial.begin(9600);
  while (Serial.available() == 0) {    // 수신 버퍼에 수신값이 없는 동안 반복 실행
    Serial.write('A');        // 시작신호 전송
    delay(300);         // 0.3초 대기
  }
}

void loop( ) { }

void serialEvent() {        // 이벤트함수: 수신값이 있으면 자동 호출
  int signal = Serial.read();     // 값 수신
  int value = analogRead(VARIABLE_R); // 가변저항값 읽기
  value = map(value, 0, 1023, 0, 255);  // 가변저항값 범위를 0∼255로 변환
  Serial.write(value);        // 값(0∼255) 송신
}
