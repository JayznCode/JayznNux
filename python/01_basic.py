
name = "Jayzn"
age = 30
height =175.5
is_student = True

print(name)
print(age)
print(height)
print(is_student)

print(type(name))
print(type(age))
print(type(height))
print(type(is_student))

a = int(input("Enter the first number: "))
b = int(input("Enter the second number: "))


print("Addition:", a + b)
print("Subtraction:", a - b)
print("Multiplication:", a * b)
print("Division:", a / b)
print("Quotient:", a // b)
print("Remainder:", a % b)


a = float(input("Enter the first number: "))
operator = input("Enter an operator (+, -, *, /): ")
b = float(input("Enter the second number: "))

if operator == "+":
    result = a + b
elif operator == "-":
    result = a - b
elif operator == "*":
    result = a * b
elif operator == "/":
    result = a / b
else:
    result = "Invalid Operator"

print("Result:", result)

count = 1
while count <= 5:
    print("Count:", count)
    count += 1

for i in range(5):
    print("i =", i)

fruits = ["apple", "banana", "cherry"]

fruits.append("orange")
print(fruits[0])

for fruit in fruits:
    print(fruit)

    

def greet(name):
    print(f"Hello!, {name}!")


greet("Jay")
greet("Python")


def add(a, b):
    return a + b

result = add(10, 20)
print(sum:", result)



