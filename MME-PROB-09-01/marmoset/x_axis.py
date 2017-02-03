#!/usr/bin/env python

SOLUTION_ACCURACY = 0.01;

from subprocess import Popen,PIPE
import re
import sys

cproc=Popen("./circle_intersection", stdin=PIPE, stderr=PIPE, stdout=PIPE)
input = "5 0 -5 0 7 7"
out,err=cproc.communicate(input)

numeric_const_pattern = r"""
    \s
    [-+]? # optional sign
    (?:
        (?: \d* \. \d+ ) # .1 .12 .123 etc 9.1 etc 98.1 etc
        |
        (?: \d+ \.? ) # 1. 12. 123. etc 1 12 123 etc
    )
    # followed by optional exponent part if desired
    (?: [Ee] [+-]? \d+ ) ?
    """

numbers = re.findall(numeric_const_pattern, out, re.VERBOSE)

if len(numbers) != 4 :
    print "failed - number of outputs did not match expected results"
    print "input: " + input;
    print "count of number outputs: " + str(len(numbers))
    sys.exit(1)

for i in range(len(numbers)) :
    numbers[i] = float(numbers[i])

solution1 = [0, 4.89898, 0, -4.89898]
solution2 = [0, -4.89898, 0, 4.89898]

match_solution1 = True
match_solution2 = True

for i in range(len(numbers)) :
    if abs(numbers[i] - solution1[i]) > abs(SOLUTION_ACCURACY * solution1[i]) :
        match_solution1 = False
    if abs(numbers[i] - solution2[i]) > abs(SOLUTION_ACCURACY * solution2[i]) :
        match_solution2 = False

if not match_solution1 and not match_solution2 :
    print "failed - output coordinates did not match solution"
    print "input: " + input;
    print "numbers detected: " + str(numbers)
    print match_solution1
    print match_solution2
    sys.exit(1)

print "passed"
print "input: " + input;
sys.exit(0)
