#include <BLEDevice.h>

#define TARGET_NAME "BLE_Server"
const int txPower = -59;
const float n = 2.0;

BLEScan* pBLEScan;

void setup() {
  Serial.begin(115200);
  Serial.println("BLE 거리 측정 클라이언트 시작");

  BLEDevice::init("");
  pBLEScan = BLEDevice::getScan();
  pBLEScan->setInterval(100);
  pBLEScan->setWindow(99);
  pBLEScan->setActiveScan(true);
}

void loop() {
  BLEScanResults foundDevices = *pBLEScan->start(3, true);  // 수정: * 붙여서 역참조

  for (int i = 0; i < foundDevices.getCount(); ++i) {
    BLEAdvertisedDevice device = foundDevices.getDevice(i);

    if (device.getName() == TARGET_NAME) {
      int rssi = device.getRSSI();
      float distance = pow(10.0, ((float)(txPower - rssi)) / (10.0 * n));

      Serial.print("RSSI: ");
      Serial.print(rssi);
      Serial.print(" dBm, 거리: ");
      Serial.print(distance, 2);
      Serial.println(" m");

      break;
    }
  }

  pBLEScan->clearResults();
  delay(100);
}
