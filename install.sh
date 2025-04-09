#!/bin/bash
make clean && make && sudo make install
sudo systemctl daemon-reexec
sudo systemctl enable yamada-monitor
sudo systemctl start yamada-monitor
modbus-monitor --menu
