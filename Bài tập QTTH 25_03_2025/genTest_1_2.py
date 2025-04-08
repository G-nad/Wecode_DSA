import random

n = int(input())

numbers = random.sample(range(-n, n), n)

numbers.sort()
with open("input.txt", "w") as file:
    file.write(f"{n}\n")
    file.write(" ".join(map(str, numbers)))
    file.write(f"\n{n}")
