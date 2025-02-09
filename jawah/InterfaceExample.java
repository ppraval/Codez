interface Animal {
    void eat();
    void sleep();
}

class Dog implements Animal {
    public void eat(){
        System.out.println("Dog is eating");
    }

    public void sleep(){
        System.out.println("Dog is sleeping");
    }
}

class Cat implements Animal{
    public void eat(){
        System.out.println("Cat is eating");
    }
    public void sleep()
    {
        System.out.println("Cats dont sleep");
    }
}

public class InterfaceExample{
    public static void main(String[] args)
    {
        Animal myDog = new Dog();
        Animal myCat = new Cat();

        myCat.sleep();
        myDog.eat();
    }
}