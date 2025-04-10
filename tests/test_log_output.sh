#!/bin/bash
set -e

echo "[TEST] CSV logging via --logtest..."

# 1. Vorbereitung
rm -f /tmp/testlog.csv

# 2. Aufruf der Anwendung
../build/modbus-monitor --logtest

# 3. Prüfung gegen Referenz
echo "[CHECK] Comparing against expected_output/testlog.csv..."
if diff /tmp/testlog.csv tests/expected_output/testlog.csv; then
  echo "✅ CSV output matches expected."
else
  echo "❌ CSV output mismatch!" >&2
  echo "Expected:"
  cat tests/expected_output/testlog.csv
  echo "Got:"
  cat /tmp/testlog.csv
  exit 1
fi
