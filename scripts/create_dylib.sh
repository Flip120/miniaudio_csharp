#!/bin/bash

rm -rf obj/*
rm -rf libs/osx/*

clang -c platform/audio_api.c -o obj/audio_api.obj  

clang -shared -o libs/osx/libaudio_api.dylib obj/audio_api.obj