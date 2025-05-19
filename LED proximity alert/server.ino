#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

void setup() {
  Serial.begin(115200);

  // BLE 초기화
  BLEDevice::init("BLE_Server");

  // 서버와 서비스 생성 (사용하지 않지만 필요)
  BLEServer *pServer = BLEDevice::createServer();
  BLEService *pService = pServer->createService("12345678-1234-1234-1234-123456789abc");
  pService->start();

  // 광고 시작
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->setScanResponse(false); // 광고만 수행
  pAdvertising->setMinPreferred(0x06);  // 기본 설정
  pAdvertising->setMinPreferred(0x12);

  pAdvertising->start();

  Serial.println("BLE 광고 시작됨 (서버)");
}

void loop() {
  // 아무 작업 없음 – 광고만 지속
  delay(1000);
}