#!/usr/bin/env python
# select a random sample without replacement
from random import seed
from random import sample
from datetime import datetime
seed(datetime.now())
# seed random number generator
# prepare a sequence
sequence = [i for i in range(501)]
sequence rever
val = input("How much numbers do you want: ")
# select a subset without replacement
subset = sample(sequence, int(val))
res = ""
for i in subset:
	res += str(i) + " "
print(res)
