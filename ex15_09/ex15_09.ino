// 조도센서값 읽고 출력

#define LIGHT A3

void setup() {
  pinMode(LIGHT, INPUT);
  Serial.begin(9600);
}

void loop() {
  int value = analogRead(LIGHT);  // 조도센서값 읽기
  Serial.print("Light: ");      // 시리얼모니터 상에 출력
  Serial.println(value);      // 시리얼모니터 상에 조도센서값 출력
  delay(100);
}
