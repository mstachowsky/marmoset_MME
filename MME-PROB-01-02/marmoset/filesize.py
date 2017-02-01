#!/usr/bin/env python

import os
import sys

expected_file_name = "missing_semi-colon.cpp"

# print os.listdir(".")
filesize = os.path.getsize(expected_file_name)
if 3440 < filesize and filesize < 3450 :
    print "passed - you found the missing semi-colon!"
    sys.exit(0)
else :
    print "failed - too many changes to the original file were detected"
    print "file size: " + str(filesize)
    sys.exit(1)
