public class SingletonExample {
    public static void main(String[] args){
        SingletonClass temp = SingletonClass.getInstance();
        if(temp != null)
        {
            System.out.println("There is a temp");
        }
        SingletonClass temp1 = SingletonClass.getInstance();
    }
}