import java.util.StringTokenizer;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.IOException;
class CL
{
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static boolean[] brack;
    public static void main(String args[])throws IOException
    {
        int n = Integer.parseInt(br.readLine());
        brack = new boolean[n+1];
        st = new StringTokenizer(br.readLine());
        for(int i = 1; i <= n;i++)
            brack[i] = Integer.parseInt(st.nextToken())==1?true:false;
        int max_dist = 0;
        int max_nest_depth = 0;
        int max_nest_depth_pos = 0;
        int max_dist_pos = 0;
        int c= 0;
        int j; int i;
        for(i = 1; i < n;)
        {
            j = i;
            for(; j <= n;j++)
            {
                c = brack[j]?c+1:c-1;
                if(c==0)
                {
                    break;
                }
                if(c>max_nest_depth)
                {
                    max_nest_depth = c;
                    max_nest_depth_pos = j;
                }
            }
            if(j-i > max_dist)
            {
                max_dist = j - i + 1;
                max_dist_pos = i;
            }
            
            i = j + 1;
        } 
        System.out.println(max_nest_depth + " " + max_nest_depth_pos + " " + max_dist + " " + max_dist_pos);
    }
}
