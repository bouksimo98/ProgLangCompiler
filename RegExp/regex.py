import sys
import re

sys.stdout.writelines(filter(re.compile(sys.argv[1]).match, sys.stdin))

#foo = re.compile(sys.argv[1])
#line = "foo"
#if foo.match(line):
#    print(line)


# python3 regex.py 'foo'