import java.time.LocalDateTime;

public class Ticket {
    private Vehicle vehicle;
    private LocalDateTime entryTime;

    public Ticket(Vehicle vehicle) {
        this.vehicle = vehicle;
        this.entryTime = LocalDateTime.now();
    }

    public String getDetails() {
        return "Vehicle: " + vehicle.getPlateNumber() + ", Entry Time: " + entryTime;
    }
}