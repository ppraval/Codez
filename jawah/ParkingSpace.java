public class ParkingSpace {
    private boolean isAvailable;
    private Vehicle parkedVehicle;

    public ParkingSpace() {
        this.isAvailable = true;
    }

    public boolean parkVehicle(Vehicle vehicle) {
        if (!isAvailable) return false;
        this.parkedVehicle = vehicle;
        this.isAvailable = false;
        return true;
    }

    public void removeVehicle() {
        this.parkedVehicle = null;
        this.isAvailable = true;
    }

    public boolean isAvailable() {
        return isAvailable;
    }
}