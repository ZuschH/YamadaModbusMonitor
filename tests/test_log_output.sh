#!/bin/bash
set -e

# Sicherstellen, dass das Binary existiert
if [ ! -f ./build/modbus-monitor ]; then
  echo "[INFO] Binary not found – running make..."
  make
fi

echo "[TEST] CSV logging via --logtest..."
rm -f /tmp/testlog.csv
./build/modbus-monitor --logtest

echo "[CHECK] Comparing entire CSV content (incl. timestamp)..."
if diff /tmp/testlog.csv tests/expected_output/testlog.csv; then
  echo "✅ Full CSV content matches expected."
else
  echo "❌ CSV mismatch!" >&2
  echo "--- Expected:"
  cat tests/expected_output/testlog.csv
  echo "--- Got:"
  cat /tmp/testlog.csv
  exit 1
fi
