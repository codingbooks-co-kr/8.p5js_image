// 가변저항값 읽고 출력하기

#define VARIABLE_R A1

void setup() {
  pinMode(VARIABLE_R, INPUT);
  Serial.begin(9600);
}

void loop() {
  int value = analogRead(VARIABLE_R);  // 가변저항값 읽기
  Serial.print("Variable Resistor: ");    // 시리얼모니터 상에 출력
  Serial.println(value);        // 시리얼모니터 상에 가변저항값 출력
  delay(100);
}
