import java.util.Scanner;
class IPL
{
    static int[][] cache;
    static Scanner sc = new Scanner(System.in);
    static int[] days;
    public static void main(String args[])
    {
        int n = sc.nextInt();
        cache = new int[n][2];
        days = new int[n];
        for(int i = 0; i< n;i++)
        {
            if(sc.hasNextInt())
                days[i] = sc.nextInt();
        }
        System.out.println(maxincome(0,0));
    }
    static int maxincome(int iday, int streak)
    {
        if(iday == days.length)
            return 0;
        else if(streak == 2)
            return maxincome(iday + 1,0);
        else
        {
            if(cache[iday][streak] == 0)
                cache[iday][streak] = Math.max(days[iday] + maxincome(iday + 1,streak + 1),maxincome(iday + 1,0));
            return cache[iday][streak];
        }
    }
}
