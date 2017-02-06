#!/usr/bin/env python

SOLUTION_ACCURACY = 0.01;

from subprocess import Popen,PIPE
import re
import sys

cproc=Popen("./steel_MSDS", stdin=PIPE, stderr=PIPE, stdout=PIPE)
input = "9994 Cold Rolled Sheet Steel 2 2 1 95 2.225 0.65 0.25"
out,err=cproc.communicate(input)

print out
sys.exit(0)
