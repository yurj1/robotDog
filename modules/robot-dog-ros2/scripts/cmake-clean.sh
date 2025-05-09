#!/bin/sh
if [ -d "build" ]; then
  rm build/* -r
else
  mkdir build
fi
