#!/usr/bin/env python

SOLUTION_ACCURACY = 0.01;

from subprocess import Popen,PIPE
import re
import sys

cproc=Popen("./steel_MSDS", stdin=PIPE, stderr=PIPE, stdout=PIPE)
input = "9994 Cold Rolled Sheet Steel 2 2 1 95 2.225 0.65 0.25"
out,err=cproc.communicate(input)

fields = ["SDS ID No.:",
          "Product Identifier:",
          "Carcinogenity:",
          "STOT Repeat Exposure:",
          "Composition \(\% weight\)\:",
          "Iron:",
          "Manganese:",
          "Chromium:",
          "Nickel"]

matches = []
for field in fields :
    matches.append(re.search(field, out))

for match_num in range(len(matches)) :
    if not matches[match_num] :
        print "failed - field not found:"
        print fields[match_num]

print out
print "passed - all input fields found"
sys.exit(0)
