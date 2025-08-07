public class ParkingLot {
    private Level[] levels;

    public ParkingLot(int levelCount, int spacesPerLevel) {
        levels = new Level[levelCount];
        for (int i = 0; i < levelCount; i++) {
            levels[i] = new Level(spacesPerLevel);
        }
    }

    public ParkingSpace assignSpace(Vehicle vehicle) {
        for (Level level : levels) {
            ParkingSpace space = level.findAvailableSpace();
            if (space != null && space.parkVehicle(vehicle)) {
                return space;
            }
        }
        return null;
    }
}