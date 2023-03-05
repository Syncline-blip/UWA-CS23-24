ps5 = 1500
bose_sbar = 700
ps5_name = "PLAYSTATION 5 GAMING CONSOLE"
bose_sbar_name = "BOSE Soundbar 700"

print("Hey Tom! Check this out! We have " + ps5_name + " and " + bose_sbar_name + "!")







#initialise country_code with 61
country_code = 61
#initialise mobile_phone with value 040102345
mobile_phone = "040102345"

#convert variable country_code from type into to type string
string_code = str(country_code)
#display output
print(string_code + mobile_phone)










name = input("Please enter your name: ")
print("Hello" + name + "! and welcome!")












a_list = [3, 4, 62,27, 83, 956, 26, 58, 3, 78, 168, 64, 78]
print(len(a_list))

string = "Supercalifragilisticexpialidocious"
print(len(string))


a1b2c3 = 1







a = 2
b = 2
print(str(a) + " * " + str(b) + " = " + str(a * b))



def multiply(a, b):
    print(str(a) + " * " + str(b) + " = " + str(a * b))



def timestable(a):
    multiply(a, 1)
    multiply(a, 2)
    multiply(a, 3)
    multiply(a, 4)
    multiply(a, 5)
    multiply(a, 6)
    multiply(a, 7)
    multiply(a, 8)
    multiply(a, 9)










def get_nums1():
    x = int(input("What is your first number?"))
    y = int(input("What is your second number?"))
    print(x, y)


def get_nums2():
    x = int(input("What is your first number?"))
    y = int(input("What is your second number?"))
    return (x, y)

def multiply(a, b):
    # print(str(a) + " * " + str(b) + " = " + str(a * b))
    return a * b

x, y = get_nums2()
#print(str(x) + " times " + str(y) + " is " + str(multiply(x, y)))
