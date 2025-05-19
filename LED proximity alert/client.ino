#include <BLEDevice.h>

#define TARGET_NAME "BLE_Server"
const int txPower = -59;
const float n = 2.0;

BLEScan* pBLEScan;

void setup() {
  Serial.begin(115200);
  Serial.println("BLE 거리 측정 클라이언트 시작");

  // GPIO 5번 핀을 출력으로 설정
  pinMode(5, OUTPUT);
  digitalWrite(5, LOW);  // 기본은 꺼짐

  BLEDevice::init("");
  pBLEScan = BLEDevice::getScan();
  pBLEScan->setInterval(100);
  pBLEScan->setWindow(99);
  pBLEScan->setActiveScan(true);
}

void loop() {
  BLEScanResults foundDevices = *pBLEScan->start(3, true);  // BLE 스캔 시작 (3초 동안)

  for (int i = 0; i < foundDevices.getCount(); ++i) {
    BLEAdvertisedDevice device = foundDevices.getDevice(i);

    if (device.getName() == TARGET_NAME) {
      int rssi = device.getRSSI();
      float distance = pow(10.0, ((float)(txPower - rssi)) / (10.0 * n));

      Serial.print("RSSI: ");
      Serial.print(rssi);
      Serial.print(" dBm, 거리: ");
      Serial.print(distance, 3);
      Serial.println(" m");

      // 👉 거리 조건 확인 및 LED 제어
      if (distance <= 0.05) {
        digitalWrite(5, HIGH);  // LED ON
      } else {
        digitalWrite(5, LOW);   // LED OFF
      }

      break;
    }
  }

  pBLEScan->clearResults();  // 다음 스캔을 위해 결과 정리
  delay(100);  // 0.1초 대기
}
