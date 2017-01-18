#!/usr/bin/env python

import os
import sys

expected_file_name = "hello_world2.cpp"

print os.listdir(".")
if os.path.isfile(expected_file_name) :
    print "passed"
    sys.exit(0)
else :
    print "failed - incorrect file name submitted"
    print "expected file name is " + expected_file_name
    sys.exit(1)
