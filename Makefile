CC=gcc
CFLAGS=-O2 -Wall
SRC=$(wildcard src/*.c)
OBJ=$(SRC:.c=.o)
BIN=modbus-monitor
PREFIX=/opt/YamadaDobby

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) -o build/$(BIN) $(OBJ)

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
