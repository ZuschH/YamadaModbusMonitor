# Yamada Modbus Monitor

**High-performance serial communication monitor** for industrial RS232/RS485 Modbus networks. Designed for Raspberry Pi and Linux environments, Yamada Modbus Monitor enables live protocol analysis, error tracking, and remote log management.

---

## 🔧 Features
- Real-time monitoring of all serial traffic (Modbus + raw)
- CRC validation and error reporting
- Timestamp-based TX ↔ RX matching with millisecond precision
- Configurable log format (plaintext / CSV / both)
- Automatic log rotation
- Remote sync via SSH + rsync
- Interactive system-wide UI with `dialog`
- Live dashboard view
- `systemd` daemon support

---

## 📦 Requirements
- Raspberry Pi (v1 or newer)
- Linux with:
  - `dialog`
  - `gcc`, `make`
  - `systemd`

---

## 📂 Installation
```bash
git clone https://github.com/your-org/yamada-modbus-monitor.git
cd yamada-modbus-monitor
make
sudo make install
```

### File Structure
| Path                        | Purpose                      |
|-----------------------------|------------------------------|
| `/opt/YamadaDobby`         | Executables + service files  |
| `/etc/YamadaDobby`         | Configuration files          |
| `/var/log/YamadaDobby`     | All logs (.log + .csv)       |

---

## ⚙️ Configuration
Edit `/etc/YamadaDobby/modbus-monitor.conf`

```ini
[serial]
port = /dev/ttyUSB0
baudrate = 9600
parity = none
databits = 8
stopbits = 1

[modbus]
poll_interval_ms = 50
timeout_ms = 300
log_invalid_crc = false

[logging]
log_dir = /var/log/YamadaDobby
log_format = both
max_file_size_kb = 1024
rotate = true

[network]
ssh_target = zusch.zapto.org
ssh_port = 1974
ssh_user = gpio-mon
```

---

## 🚀 Usage

### Start the Monitor Service
```bash
sudo systemctl start yamada-monitor.service
```

### Launch UI
```bash
modbus-monitor --menu
```

### Reconfigure Settings Live
```bash
modbus-monitor --reconfigure modbus.poll_interval_ms 100
```

---

## 📑 Logs
- Plaintext: `modbus.log`
- CSV: `modbus.log.csv`

### CSV Columns
```csv
timestamp,direction,slave,function,ascii,hex,crc_ok,response_time_ms
```

---

## 🔐 Remote Log Sync
Use cron or systemd timers with `rsync`:
```bash
rsync -avz -e "ssh -p 1974" /var/log/YamadaDobby/*.csv gpio-mon@zusch.zapto.org:/backup
```

---

## 📈 Roadmap
- [ ] Condition Monitoring & Alerting (V1.1+)
- [ ] Telegram visual decoder (HMI-style)
- [ ] Multi-device correlation (TX/RX across devices)

---

## 🧾 License
MIT License © 2024–2025 – Your Name / Your Company

