/* package codechef; // don't place package name! */

import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Codechef
{
    static int[] V,W;
    static int[][] N;
    static StringTokenizer st;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
     static void mergeSort(int[] arr , int l ,int r)
    {
        if(l<r)
        {
            int m = (l+r)/2;
            mergeSort(arr,l,m);
            mergeSort(arr,m+1,r);
            merge(arr,l,m,r);
        }
        
    }
    static void merge(int[] arr, int l, int m, int r)
    {
        int n1 = m+1-l;
        int n2 = r-m;
        int[] L = new int[n1];
        int[] R = new int[n2];
        for(int i = 0; i< n1;i++)
        {
            L[i] = arr[l+i];
        }
        for(int j =0;j < n2;j++)
        {
            R[j] = arr[m+1+j];
        }
        int i = 0, j = 0, k = l;
        while(i<n1 && j<n2)
        {
            if(L[i] <= R[j])
            {
                arr[k] = L[i];
                i++;
            }
            else
            {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
        while(i<n1)
        {
            arr[k] = L[i];
            i++;
            k++;
        }
        while(j<n2)
        {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
    public static void main (String[] args)throws IOException
    {
        st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int x = Integer.parseInt(st.nextToken());
        int y = Integer.parseInt(st.nextToken());
        N = new int[n][2];
        V = new int[x];
        W = new int[y];
        for(int i = 0 ; i< n;i++)
        {
            st = new StringTokenizer(br.readLine());
            N[i][0] = Integer.parseInt(st.nextToken());
            N[i][1] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        for(int i= 0; i<x;i++)
        {
            V[i] = Integer.parseInt(st.nextToken());
        }
        
        st = new StringTokenizer(br.readLine());
        for(int i =0; i<y;i++)
        {
            W[i] = Integer.parseInt(st.nextToken());
        }
        mergeSort(V,0,x-1);
        mergeSort(W,0,y-1);
        int dif = 100000;int s,e,vs,we,time;
        for(int i = 0; i<n;i++)
        {
            s = N[i][0];
            e = N[i][1];
           if(V[0] <= s && W[W.length-1] >= e) 
           {
            vs = bNextSmall(V,s,0,x-1);
            we = bNextBig(W,e,0,y-1);
            time = we-vs+1;
            dif = time<dif?time:dif;
           }
        }
        System.out.println(dif);
    }
   
    static int bNextBig(int[] arr, int n, int l, int r)
    {
        if(l==r)
            return arr[l];
        else if(r-l ==1)
        {
            if(n<=arr[l])
                return arr[l];
            else
                return arr[r];
        }
        else
        {
            int m = (l+r)/2;
            if(n<=arr[m])
                return bNextBig(arr,n,l,m);
            return bNextBig(arr,n,m+1,r);
        }
            
    }
    static int bNextSmall(int[] arr, int n, int l, int r)
    {
        if(l==r)
            return arr[l];
        else if(r-l==1)
        {
            if(n>=arr[r])
                return arr[r];
            else
                return arr[l];
                
        }
        else
        {
            int m = (l+r)/2;
            if(arr[m+1] > n)
                return bNextSmall(arr,n,l,m);
            return bNextSmall(arr,n,m+1,r);
        }
    }
    

}
