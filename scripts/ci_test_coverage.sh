#!/bin/sh

# Travis CI uses this script to build an submit code coverage results.
# It does not run tests that require the network.

# Exit on any nonzero return code.
set -ev

generate_coverage(){
    # Generate code coverage results, but only for files in libraries/.
    lcov --directory . --capture --output-file $1
    lcov --remove $1 '*demo*' --output-file $1
    lcov --remove $1 '*ports*' --output-file $1
    lcov --remove $1 '*tests*' --output-file $1
    lcov --remove $1 '*third_party*' --output-file $1
}

# Overwrite the value of the COMPILER_OPTIONS varirable to remove any thread sanitizer flags, and replace with coverage flags.
export COMPILER_OPTIONS="-DIOT_TEST_COVERAGE=1 --coverage"

SCRIPTS_FOLDER_PATH=../scripts

# Run common tests with code coverage.
$SCRIPTS_FOLDER_PATH/ci_test_common.sh
generate_coverage common.info

# Run MQTT tests against AWS IoT with code coverage.
$SCRIPTS_FOLDER_PATH/ci_test_mqtt.sh
generate_coverage mqtt.info

# Run Shadow tests with code coverage.
$SCRIPTS_FOLDER_PATH/ci_test_shadow.sh
generate_coverage shadow.info

# Run Jobs tests with code coverage.
$SCRIPTS_FOLDER_PATH/ci_test_jobs.sh
generate_coverage jobs.info

# Run Provisioning tests with code coverage.
# $SCRIPTS_FOLDER_PATH/ci_test_provisioning.sh
# generate_coverage provisioning.info

# Combine all the coverage reports of all libraries into a single file.
lcov -a common.info -a mqtt.info -a shadow.info -a jobs.info -o coverage.info  

# Submit the code coverage results. Must be submitted from SDK root directory so
# Coveralls displays the correct paths.
cd ..
coveralls --lcov-file build/coverage.info
