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

# Timestamp (Spalte 1) entfernen – robust auf beiden Seiten
tail -n 1 /tmp/testlog.csv | cut -d',' -f2- > /tmp/testlog_stripped.csv
cut -d',' -f2- tests/expected_output/testlog.csv > /tmp/testlog_expected_stripped.csv

echo "[CHECK] Comparing CSV content (timestamp-agnostic)..."
if diff /tmp/testlog_stripped.csv /tmp/testlog_expected_stripped.csv; then
  echo "✅ CSV content matches expected (ignoring timestamp)."
else
  echo "❌ CSV mismatch!" >&2
  echo "--- Expected:"
  cat /tmp/testlog_expected_stripped.csv
  echo "--- Got:"
  cat /tmp/testlog_stripped.csv
  exit 1
fi
