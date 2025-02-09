public class FinallyExample {
    public static void main(String[] args)
    {
        try {
            int[] nums = {1, 2, 3, 4, 5};
            System.out.println(nums[8]);
        }
        catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("AIDS paitent check your indexes");
        }
        finally 
        {
            System.out.println("I love geetha meenakshi");
        }
    }
}