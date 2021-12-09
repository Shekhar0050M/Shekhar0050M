public class Car implements Vehicle, Fuel{
    @Override
    public void brake() {
        System.out.println("Car Applies Power brake");
    }
    @Override
    public void run(){
        System.out.println("Car is running on 4 wheels");
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