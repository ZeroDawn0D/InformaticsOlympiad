import java.util.Arrays;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
class Ans
{
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String args[])throws IOException
    {
        st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int value[] = new int[n];
        for(int i = 0; i< n;i++)
            value[i] = Integer.parseInt(st.nextToken());
        Arrays.sort(value);
        int c = 0;
        for(int i = 0; i < n-1; i ++)
        {
            for(int j = i + 1; j < n; j++)
            {
                if (value[j] - value[i] >= k)
                    {
                        c+= n - j;
                        break;
                    }
            }
        }
        System.out.print(c);
    }
}
