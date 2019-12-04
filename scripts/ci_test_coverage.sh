#!/bin/sh

# Travis CI uses this script to build an submit code coverage results.
# It does not run tests that require the network.

# Exit on any nonzero return code.
set -ev

# Overwrite the value of the COMPILER_OPTIONS varirable to remove any thread sanitizer flags, and replace with coverage flags.
export COMPILER_OPTIONS="-DIOT_TEST_COVERAGE=1 --coverage"

SCRIPTS_FOLDER_PATH=../scripts

# Run common tests with code coverage.
$SCRIPTS_FOLDER_PATH/ci_test_common.sh

# Run MQTT tests against AWS IoT with code coverage.
$SCRIPTS_FOLDER_PATH/ci_test_mqtt.sh

# Run Shadow tests with code coverage.
$SCRIPTS_FOLDER_PATH/ci_test_shadow.sh

# Run Jobs tests with code coverage.
$SCRIPTS_FOLDER_PATH/ci_test_jobs.sh

# Generate code coverage results, but only for files in libraries/.
lcov --directory . --capture --output-file coverage.info
lcov --remove coverage.info '*demo*' --output-file coverage.info
lcov --remove coverage.info '*ports*' --output-file coverage.info
lcov --remove coverage.info '*tests*' --output-file coverage.info
lcov --remove coverage.info '*third_party*' --output-file coverage.info

# Submit the code coverage results. Must be submitted from SDK root directory so
# Coveralls displays the correct paths.
cd ..
coveralls --lcov-file build/coverage.info
