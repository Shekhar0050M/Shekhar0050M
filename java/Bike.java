public class Bike implements Vehicle, Fuel{
    @Override
    public void brake() {
        System.out.println("Bike Applies hand brake");
    }
    @Override
    public void run() {
        System.out.println("Bike is running on 2 wheels");
    }
    @Override
    public void fill(String type, int quantity) {
        System.out.println(quantity + " litres of " + type);
    }
    @Override
    public void pay(int quantity, int price) {
        System.out.println("Pay Rs. " + price);
    }
}