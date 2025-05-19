# BLE-based Distance Estimation System 




https://github.com/user-attachments/assets/ff9c0a24-af9b-47f3-9c08-330c988cb1e8

- RSSI-based measurement of distance between BLE devices
- Linear regression model by comparing measured and actual distances

1. BLE server <br>
: Send BLE ads with name "BLE_Server" <br>
: Broadcast to get signals from around
2. BLE client <br>
: Scan BLE device, and find "BLE_Server" <br>
: Calculate distance with RSSI

![HW07 test finding](https://github.com/user-attachments/assets/d81c3998-2659-4c95-b9e7-9cd0a991d32c)
