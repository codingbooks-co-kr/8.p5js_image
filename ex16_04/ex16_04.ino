// 아두이노: 가변저항값 2개 송신

#define VARIABLE_R1 A1
#define VARIABLE_R2 A2

void setup() {
  pinMode(VARIABLE_R1, INPUT);
  pinMode(VARIABLE_R2, INPUT);
  Serial.begin(9600);
  while (Serial.available() == 0) {  // 수신 버퍼에 수신값이 없는 동안 반복 실행
    Serial.println('A');      // 시작신호 전송
    delay(300);       // 0.3초 대기
  }
}

void loop( ) { }

void serialEvent() {      // 이벤트함수: 수신값이 있으면 자동 호출
  int signal = Serial.read();   // 수신
  int value1 = analogRead(VARIABLE_R1);
  int value2 = analogRead(VARIABLE_R2);
  Serial.print(value1);
  Serial.print(',');
  Serial.println(value2);     // 송신(→문자열: 'value1,value2\n')
}
