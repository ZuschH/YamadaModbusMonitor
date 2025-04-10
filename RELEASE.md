# 🏷 Release: `v1.0.0` – Initial Stable Release

## 🎯 Overview
This is the first stable release of Yamada Modbus Monitor, a high-performance industrial communication monitoring system designed for embedded Linux (Raspberry Pi and compatible platforms).
The monitor captures, interprets, and logs all RS232/RS485 traffic in Modbus environments with a strong focus on real-time fault detection and user accessibility.
GitHub: github.com/ZuschH/YamadaModbusMonitor

🚀 Features
Real-time monitoring of Modbus and raw serial traffic (TX/RX)
CRC validation with logging of corrupted telegrams
TX ↔ RX matching with millisecond-level response time logging
Live GUI via dialog:
Log view
Configuration editor with live --reconfigure
Monitoring dashboard
Structured logging: plaintext & CSV with rotation
Systemd integration (yamada-monitor.service)
SSH/rsync log offloading (configurable)
Robust configuration management via /etc/YamadaDobby/
Modular C/C++ codebase optimized for embedded performance

🧪 Tested On
Raspberry Pi 3 & 4
Debian-based ARMv7/ARM64 systems
dialog, gcc, make, systemd, rsync, ssh

📦 Installation
Via Source
git clone https://github.com/ZuschH/YamadaModbusMonitor.git
cd YamadaModbusMonitor
make
sudo make install
sudo systemctl start yamada-monitor
modbus-monitor --menu

Via DEB Package
Download the .deb file from this release and install:
sudo dpkg -i yamada-modbus-monitor_1.0-1_armhf.deb

🔮 Roadmap (Post-1.0)


📄 License
MIT License © 2024–2025Maintainer: ZuschH
