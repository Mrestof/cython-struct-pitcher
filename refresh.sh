#!/usr/bin/env bash
set -e

venv_python=../venv-global/bin/python

echo === new refresh record === |tee --append log-client |tee --append log-server
gcc server.c -o server &>> log-server
$venv_python setup.py build_ext --inplace &>> log-client
