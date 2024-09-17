#define PIN_LED 13
unsigned int count, toggle;

void setup() {
  pinMode(PIN_LED, OUTPUT);     // LED 핀을 출력 모드로 설정
  Serial.begin(115200);         // 시리얼 포트 초기화
  while (!Serial) {
    ; // 시리얼 포트 연결 대기
  }
  Serial.println("Hello World!");
  count = toggle = 0;
  digitalWrite(PIN_LED, toggle); // LED를 꺼둠
}

void loop() {
  Serial.println(++count);
  toggle = toggle_state(toggle); // LED 상태를 토글
  digitalWrite(PIN_LED, toggle); // LED 상태 업데이트
  delay(1000);                   // 1초 대기
}

int toggle_state(int toggle) {
  return !toggle; // LED 상태를 반전시킴 (0 -> 1, 1 -> 0)
}
