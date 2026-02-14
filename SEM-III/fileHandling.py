arr = [23,42,36,4,25]
myFile = open("cars.txt", "w")
lastInd = (len(arr)-1)


for i in range(0,len(arr)):
    if(i == lastInd):
        var = str(arr[i])
        myFile.write(var)
    else:        
        var = str(arr[i]) + ","
        myFile.write(var)


myFile = open("cars.txt", "r")
var = myFile.read().split(",")
print(var)

for i in range (len(var)):
    var[i] = int(var[i])

print(var)