// 버튼값 읽고 시리얼 모니터에 출력

#define BUTTON 2

void setup() {
  pinMode(BUTTON, INPUT);
  Serial.begin(9600);
}

void loop() {
  int value = digitalRead(BUTTON);    // 버튼값 읽기
  Serial.print("Button: ");
  Serial.println(value);        // 버튼값을 시리얼 모니터(PC)로 전송
  delay(100);
}
