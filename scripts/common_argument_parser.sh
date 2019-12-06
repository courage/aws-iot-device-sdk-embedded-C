#! /bin/sh

# Common utility for parsing command line arguments to the library test scripts.

set -e

function usage () {
    echo "Run $ tests"
    echo ""
    echo "Usage:"
    echo " $1 [options]"
    echo ""
    echo "Options:"
    echo " -d, --enable-demo-run          enable running demo in addition to tests.  "
    echo " -s, --enable-static-memory     run tests with static memory build in adition."
    echo " -h, --help                     display this help"
    exit 1
}

GETOPT_OUT=`getopt -o hds --long --help,enable-demo-run,enable-static-memory -n "${0##*/}" -- "$@"`
if [ $? != 0 ]
then
    echo "Exiting..." >&2
    exit 1
fi

eval set -- "$GETOPT_OUT"

# Initialize configuration variables (that can re-assigned based on command line argument parsing).
export RUN_DEMO=0
export BUILD_WITH_STATIC_MEMORY=0

while true; do
  case "$1" in
    -h | --help ) usage $0 ;;
    -d | --enable-demo-run ) RUN_DEMO=1; shift ;;
    -s | --enable-static-memory ) BUILD_WITH_STATIC_MEMORY=1; shift ;;
    -- ) shift; break ;;
    * ) break ;;
  esac
done