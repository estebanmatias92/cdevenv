#!/bin/sh


build () {
    mkdir -p ./app/build
    (cd app/build; cmake ..; make)
}

run() {
    ./app/build/src/${PROJECT_NAME}
}

build
run
