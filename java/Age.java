public class Age {
    int curage;
    public void setAge(int curage){
        this.curage=curage;
    }
    public void validate() throws InvalidAgeException{
        if(this.curage<18){
            throw new InvalidAgeException();
        }
        else{
            System.out.println("Everything is ok.");
        }
    }
    public static void main(String[] args) {
        Age ag = new Age();
        try {
        ag.setAge(20);
        ag.validate();
            
        } catch (InvalidAgeException e) {
            e.printStackTrace();
        }
    }
}
