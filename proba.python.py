class Employee:
    name = "Ben"
    designation = "Sales executive"
    saleMadeThisWeek = 6
    numberOfworkingHours = 40
    def hasAchivedTarget(self):
        if self.saleMadeThisWeek >= 5:
            print("target has been achived")
        else:
            print("target has not been achived")
    def employeeDetalis(self):
        self.Name = "lol"
        print("name :", self.Name)
        age = 28
        print("age:",age)
    def printEmployeeDetalis(self):
        print("printing ina anothe method")
        print("name:", self.Name)
        print("age: ,age") 
    def employeeDetalis1(self) :
        self.firstName = "ben"

    @staticmethod
    def Welcoomemessage():
        print("welcome")

    def displayEmployeeDetalis(self):
        print(self.firstName)

    def __init__(self, name):
        self.firstName = name      

empployeeOne = Employee()
print(empployeeOne.name)
print(empployeeOne.hasAchivedTarget())
empployeeTwo = Employee()
print(empployeeTwo.name)
print("number of working hours for employe one is")
print(empployeeOne.numberOfworkingHours)
print("number of working hours for employe two is")
print(empployeeTwo.numberOfworkingHours)
Employee.numberOfworkingHours = 45
print("number of working hours for employe one after this funciton:")
print(empployeeOne.numberOfworkingHours)
print("number of working hours for employe two after this funciton:")
print(empployeeTwo.numberOfworkingHours)
empployeeOne.name = "john"
empployeeTwo.name = "mary"
print("emplyee one:")
print(empployeeOne.name)
print("empployee Two:")
print(empployeeTwo.name)
empployeeOne.numberOfworkingHours = 40
print("number of working hours for employee one:")
print(empployeeOne.numberOfworkingHours)
print("number of working hours for employe two after this funciton:")
print(empployeeTwo.numberOfworkingHours)
employee = Employee("mark")
employee.employeeDetalis()
employee.printEmployeeDetalis()
employee.employeeDetalis1()
print(employee.firstName)
employee.Welcoomemessage()
employee.displayEmployeeDetalis()