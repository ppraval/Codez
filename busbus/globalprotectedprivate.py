global_pain = "pain"

def print_global():
    # global global_pain
    global_pain = "New pain"
    print(global_pain)

class Parent:
    def __init__(self):
        self._protected = "Pain"

class Child(Parent):
    def show_protected(self):
        print(self._protected)

class Private_Parent:
    def __init__(self):
        self.__private = "Private Pain"
    
    def show_private(self):
        print(self.__private)

print_global()

c = Child()
c.show_protected()

p = Private_Parent()
p.show_private()