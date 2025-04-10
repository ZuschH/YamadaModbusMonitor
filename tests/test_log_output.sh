#!/bin/bash
set -e

echo "[TEST] CSV logging via --logtest..."

# 1. Bereinigen & Aufruf
rm -f /tmp/testlog.csv
../build/modbus-monitor --logtest

# 2. Zeitstempel ignorieren (ab Spalte 2)
cut -d',' -f2- /tmp/testlog.csv > /tmp/testlog_stripped.csv
cut -d',' -f2- tests/expected_output/testlog.csv > /tmp/testlog_expected_stripped.csv

# 3. Vergleich
echo "[CHECK] Comparing CSV content without timestamps..."
if diff /tmp/testlog_stripped.csv /tmp/testlog_expected_stripped.csv; then
  echo "✅ CSV structure (excluding timestamps) matches expected."
else
  echo "❌ CSV output mismatch!" >&2
  echo "--- Expected (stripped):"
  cat /tmp/testlog_expected_stripped.csv
  echo "--- Got (stripped):"
  cat /tmp/testlog_stripped.csv
  exit 1
fi
