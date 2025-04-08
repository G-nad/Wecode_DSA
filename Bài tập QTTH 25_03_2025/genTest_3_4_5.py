n = int(input());

with open("input2.txt", "w") as file:
    file.write(f"{n}\n")
    for i in range(0, n):
        file.write(f"{i} ")
    file.write(f"\n{n}")
