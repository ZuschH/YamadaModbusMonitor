# 📋 Changelog – Yamada Modbus Monitor

All notable changes to this project will be documented in this file.
This project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

---

## [1.0.0] – 2025-04-08
### Added
- Initial release for Raspberry Pi and embedded Linux
- Real-time Modbus traffic monitoring (TX/RX)
- CRC check with optional invalid frame logging
- TX/RX response time correlation
- CSV and plaintext log formats with log rotation
- Dashboard with runtime metrics (timeouts, CRC errors, RX count)
- `dialog`-based full-screen terminal UI:
  - Live tail view
  - Config editor with `--reconfigure`
  - Dashboard view
- SSH + rsync-based remote log upload (configurable target)
- `systemd` service integration
- DEB packaging support

### Fixed
- N/A

### Changed
- N/A

---

## v1.0.0 – Initial Stable Release
- Modular architecture: INI config, systemd support, dialog UI prepared
- `--menu`, `--version`, `--easteregg` CLI flags
- DEB installation package with persistent service

## [Unreleased]

## v1.1.0 (in progress)

- [x] CSV logging implemented with TX/RX, timestamp, function code, and CRC status
- [x] `log_writer.c/.h` created with `log_csv_frame()` function
- [x] `main.c` extended with `--logtest` command for CSV test output
- [ ] Real Modbus CRC decoder and TX/RX parsing
- [ ] Live config changes via --reconfigure
- [ ] Human/Machine dual log output (ASCII + binary)
- [ ] Easter Egg rotation (optional randomness)
- [ ] Structured logging for diagnostic replay


[planned]

- [ ] CSV log file structure refactor
- [ ] Real Modbus CRC decoder and TX/RX parsing
- [ ] Live config changes via --reconfigure
- [ ] Human/Machine dual log output (ASCII + binary)
- [ ] Easter Egg rotation (optional randomness)

### Planned
- Condition monitoring with alert threshold logic
- Telegram decoding for Toshiba/Daikin/Fuji formats
- Export filtering and CSV tools
- Web dashboard or touchscreen support

