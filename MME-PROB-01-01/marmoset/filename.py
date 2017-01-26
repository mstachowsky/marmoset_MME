#!/usr/bin/env python

import os
import sys

expected_file_name = "hello_world.cpp"

# print os.listdir(".")
if os.path.isfile(expected_file_name) :
    print "passed - correct file name used: " + expected_file_name
    sys.exit(0)
else :
    print "failed - incorrect file name submitted"
    print "expected file name is " + expected_file_name
    sys.exit(1)
