#! /bin/bash
# this script helps you istall brew package manager and readline at the same time in goin fre

mkdir ~/goinfre/homebrew > /dev/null 2>&1

curl --silent -L https://github.com/Homebrew/brew/tarball/master | tar xz --strip 1 -C ~/goinfre/homebrew > /dev/null 2>&1

cd ~/goinfre/homebrew/bin && ./brew install readline
