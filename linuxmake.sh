#!/bin/bash

exit_error()
{
    exit 1
}

NAME=Boat_Calc

SCRIPT_DIR=$(cd "$(dirname "${BASH_SOURCE[0]}")/." &> /dev/null && pwd -P)
BUILD_DIR="${SCRIPT_DIR}"/build-linux
LINUX_RELEASE_DIR="${SCRIPT_DIR}"/bin/linux

mkdir "${BUILD_DIR}"

cmake -B "${BUILD_DIR}" -DCMAKE_BUILD_TYPE=Release || exit_error

cmake --build "${BUILD_DIR}" -j 8 || exit_error

if [[ -e "${BUILD_DIR}"/${NAME} ]]; then
    mkdir -p "${LINUX_RELEASE_DIR}"
    cp "${BUILD_DIR}"/${NAME} "${LINUX_RELEASE_DIR}"
fi
