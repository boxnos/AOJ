import random
import sys

size = int(sys.argv[1])
print(size)
for _ in range(size):
    print(" ".join([str(random.randint(0,100)) for _ in range(6)]))
