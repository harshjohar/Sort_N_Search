class ComplexNumber:
    real=0
    img=0
    
    def __init__(self, real, img):
        self.real = real
        self.img = img
    
    def display(self):
        print(f"{self.real} + {self.img}i")

    def modulo(self):
        return (self.real**2 + self.img**2)**0.5
    
    def add(self, c):
        return ComplexNumber(self.real+c.real, self.img+c.img)

    def multiply(self, c):
        return ComplexNumber(self.real*c.real - self.img*c.img, self.real*c.img + self.img*c.real)

c1 = ComplexNumber(6, 9)
c2 = ComplexNumber(4, 3)
print(c1.real)
c1.display()
print(c1.modulo())

c3 = c1.add(c2)
c3.display()

c4 = c1.multiply(c2)
c4.display()

# class MyList: