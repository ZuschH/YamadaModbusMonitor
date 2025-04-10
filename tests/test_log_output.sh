#!/bin/bash
set -e

echo "[TEST] CSV logging via --logtest..."

# 1. Lege Datei an
rm -f /tmp/testlog.csv

# 2. Starte die Anwendung im Testmodus
../build/modbus-monitor --logtest

# 3. Vergleich mit der Referenz
if diff /tmp/testlog.csv tests/expected_output/testlog.csv; then
  echo "✅ CSV output matches expected."
else
  echo "❌ CSV output mismatch!" >&2
  exit 1
fi
