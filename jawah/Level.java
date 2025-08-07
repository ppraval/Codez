public class Level {
    private ParkingSpace[] spaces;

    public Level(int spaceCount) {
        spaces = new ParkingSpace[spaceCount];
        for (int i = 0; i < spaceCount; i++) {
            spaces[i] = new ParkingSpace();
        }
    }

    public ParkingSpace findAvailableSpace() {
        for (ParkingSpace space : spaces) {
            if (space.isAvailable()) return space;
        }
        return null;
    }
}