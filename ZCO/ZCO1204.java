import java.util.Arrays;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
class Ans
{
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int[]cache;
    static int[] chair;
    
    public static void main(String args[])throws IOException
    {
        int n = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        chair = new int[n];
        cache = new int[n];
        for(int i = 0; i < n; i++)
            chair[i] = Integer.parseInt(st.nextToken());
        
        System.out.print(Math.min(calc(chair),calc(reverse(chair))));
    }
    static int calc(int arr[])
    {
        cache[0]  = arr[0];
        cache[1] = arr[1];
        for(int i = 2; i < arr.length;i++)
        {
            cache[i] = arr[i] + Math.min(cache[i-1],cache[i-2]);
        }
        return cache[arr.length-1];
    }
    static int[] reverse(int[] arr)
    {
        int x = arr.length;
        int[] r = new int[x];
        for(int i = 0;i< x;i++)
            r[i] = arr[x-i-1];
        return r;
    }
}
