import matplotlib.pyplot as plt

file = open("output.txt")
inputx = []
inputy = []
inputz = []

discarded_lines = 500
discarded_check = 0
for line in file:
    discarded_check = discarded_check + 1
    if discarded_check - discarded_lines > 0 :
        fields = line.strip().split()
        inputx.append(fields[0])
        inputy.append(fields[1])
        inputz.append(fields[2])

plt.plot(inputx , "bo")
plt.plot(inputy , "ro")
plt.plot(inputz , "yo")

plt.ylabel("testeteste")
plt.show()