#!/usr/bin/env python
# select a random sample without replacement
from random import seed
from random import sample
from datetime import datetime
seed(datetime.now())
# seed random number generator
# prepare a sequence
sequence = [i for i in range(501)]
sequence = sequence[::-1]
# select a subset without replacement
res = ""
for i in sequence:
	res += str(i) + " "
print(res)
