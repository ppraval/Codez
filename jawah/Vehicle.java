public abstract class Vehicle {
    private String plateNumber;

    public Vehicle(String plateNumber) {
        this.plateNumber = plateNumber;
    }

    public String getPlateNumber() {
        return plateNumber;
    }
}


public class Car extends Vehicle {
    public Car(String plateNumber) {
        super(plateNumber);
    }
}