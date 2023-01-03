#!/usr/bin/env bash
set -e


venv_python=../venv-global/bin/python

$venv_python setup.py build_ext --inplace
$venv_python server.py&
$venv_python client.py
