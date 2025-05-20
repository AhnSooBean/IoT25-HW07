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

![HW07 table](https://github.com/user-attachments/assets/a3baf2e4-527a-4660-a20c-adebd5ce2ab8)
![HW07 bar chart (regression)](https://github.com/user-attachments/assets/23b86129-5413-45a9-a375-97b11a4b1169)
