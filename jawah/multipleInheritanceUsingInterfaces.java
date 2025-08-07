class Vehicle {
    int tires;
    String engine;
    int tankCapacity;

    public Vehicle(int tires, String engine, int tankCapacity) {
        this.tires = tires;
        this.engine = engine;
        this.tankCapacity = tankCapacity;
    }

    public void showSpecs() {
        System.out.println("Tires: " + tires);
        System.out.println("Engine: " + engine);
        System.out.println("Tank Capacity: " + tankCapacity + " liters");
    }
}

class Car extends Vehicle {
    boolean hasAC;

    public Car(int tires, String engine, int tankCapacity, boolean hasAC) {
        super(tires, engine, tankCapacity);
        this.hasAC = hasAC;
    }

    @Override
    public void showSpecs() {
        super.showSpecs();
        System.out.println("AC: " + (hasAC ? "Yes" : "No"));
    }
}

class SportsCar extends Car {

    public SportsCar(int tires, String engine, int tankCapacity) {
        super(tires, engine, tankCapacity, false); // SportsCar has no AC
    }

    @Override
    public void showSpecs() {
        super.showSpecs();
        System.out.println("Note: AC removed for weight reduction.");
    }
}