#!/bin/bash
set -e

echo "[TEST] CSV logging via --logtest..."
../build/modbus-monitor --logtest
diff /tmp/testlog.csv tests/expected_output/testlog.csv
echo "✅ CSV output matches expected."
