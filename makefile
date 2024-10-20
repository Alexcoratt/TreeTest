PROJECT_NAME=TreeTest

SOURCE_DIR?=src
BUILD_DIR?=build

CXX?=clang++
CXXFLAGS+=-Wall -std=c++17 -Iinclude

# basic targets
main: mkBuildDir
	${CXX} ${CXXFLAGS} -o ${BUILD_DIR}/${PROJECT_NAME} ${SOURCE_DIR}/main.cpp

mkBuildDir:
	if [ ! -d ${BUILD_DIR} ]; then mkdir ${BUILD_DIR}; fi