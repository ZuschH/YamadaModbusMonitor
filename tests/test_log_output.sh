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

# Zeitstempel rausstrippen und vergleichen
awk -F',' 'NR==1 {for(i=2;i<=NF;i++) printf $i (i<NF?",":"\n")}' /tmp/testlog.csv > /tmp/testlog_stripped.csv
awk -F',' 'NR==1 {for(i=2;i<=NF;i++) printf $i (i<NF?",":"\n")}' tests/expected_output/testlog.csv > /tmp/testlog_expected_stripped.csv

echo "[CHECK] Comparing CSV content without timestamps..."
if diff /tmp/testlog_stripped.csv /tmp/testlog_expected_stripped.csv; then
  echo "✅ CSV structure (excluding timestamps) matches expected."
else
  echo "❌ CSV output mismatch!" >&2
  exit 1
fi

# testlog output check - updated for executable fix

