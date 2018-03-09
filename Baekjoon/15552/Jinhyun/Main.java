package algorithm_15552;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int limit = Integer.parseInt(br.readLine());
		
		for(int i=0; i<limit; i++){
			String  s = br.readLine();
			String split[] = s.split(" ");
			
			int a = Integer.parseInt(split[0]);
			int b = Integer.parseInt(split[1]);
			
			System.out.println(a+b);
			
		}
	}
}
