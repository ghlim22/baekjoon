import java.util.*;
import java.io.*;

public class Main {
	public static void main(String args[]) throws Exception {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

		int n = Integer.parseInt(reader.readLine());
		var retval = new long[10];
		int curdigit_cnt = 1;
		for (int i = 1; n > 0; i *= 10) {
			int digit = n % 10;
			n /= 10;
			for (int j = 0; j < 10; ++j) {
				if (j < digit) {
					retval[j] += (n + 1) * i;
				} else if (j == digit) {
					retval[j] += n * i + curdigit_cnt;
				} else {
					retval[j] += n * i;
				}
			}
			retval[0] -= i;
			curdigit_cnt += i * digit;
		}

		for (int i = 0; i < 10; ++i) {
			writer.append(Long.toString(retval[i]) + " ");
		}
		writer.flush();
	}
}
