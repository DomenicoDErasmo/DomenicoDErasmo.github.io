import DErasmoDomenico_Lab4 as test

x = test.Vector(6, {1:0.1, 5:-2.0, 3:20.0, 4:0})
y = test.Vector(6, {2:5.0, 3:-5.5, 1: 10.0, 5:2.0})
print(x.proj(y))
