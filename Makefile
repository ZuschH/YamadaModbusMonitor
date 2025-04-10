CC=gcc
CFLAGS=-O2 -Wall
SRC=src/main.c src/dialog_ui.c src/config_parser.c src/modbus_config.c src/ini.c src/log_writer.c
OBJ=$(SRC:.c=.o)
BIN=modbus-monitor
PREFIX=/opt/YamadaDobby

all: build/$(BIN)

build/$(BIN): $(OBJ)
	mkdir -p build
	$(CC) -o $@ $(OBJ)

install:
	install -d $(PREFIX)
	install -m 755 build/$(BIN) $(PREFIX)/$(BIN)
	install -d /etc/YamadaDobby
	cp etc/modbus-monitor.conf /etc/YamadaDobby/
	install -d /lib/systemd/system
	cp systemd/yamada-monitor.service /lib/systemd/system/

clean:
	rm -f src/*.o build/$(BIN)

deb:
	mkdir -p build/yamada-modbus-monitor_1.0-1_armhf/DEBIAN
	cp -r debian/control build/yamada-modbus-monitor_1.0-1_armhf/DEBIAN/
	mkdir -p build/yamada-modbus-monitor_1.0-1_armhf/opt/YamadaDobby
	cp build/$(BIN) build/yamada-modbus-monitor_1.0-1_armhf/opt/YamadaDobby/
	dpkg-deb --build build/yamada-modbus-monitor_1.0-1_armhf

.PHONY: all install clean
