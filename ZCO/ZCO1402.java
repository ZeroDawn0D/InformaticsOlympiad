import java.util.Scanner;
class Supw
{
	static int[][] cache;
	static int[] arr;
	static Scanner sc = new Scanner(System.in);
	public static void main(String args[])
	{
		int n = sc.nextInt();
		System.out.println();
		arr = new int[n];
		cache = new int[n][2];
		for(int i = 0; i < n; i++)
		{
			if(sc.hasNextInt())
				arr[i] = sc.nextInt();
		}
		System.out.println();
		System.out.print(calc(0,0));
	}
	static int calc(int day, int rest)
	{
		if(day == arr.length)
			return 0;
		else if(rest == 2)
			return arr[day] + calc(day+1,0);
		else
		{
			if(cache[day][rest] == 0)
				cache[day][rest] = Math.min(arr[day] + calc(day +1,0), calc(day + 1, rest + 1));
			return cache[day][rest];
		}	
	}
}
