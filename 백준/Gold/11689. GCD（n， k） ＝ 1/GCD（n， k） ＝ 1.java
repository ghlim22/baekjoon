import java.util.*;
import java.io.*;

public class Main {
	public static void main(String args[]) throws Exception {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

		long n = Long.parseLong(reader.readLine());
		
		long tmp = n;
		var p = new ArrayList<Long>();
		for (long i = 2; i * i <= tmp; ++i) {
			if (tmp % i == 0) {
				p.add(i);
				while (tmp % i == 0) {
					tmp /= i;
				}
			}
		}
		if (tmp > 1) {
			p.add(tmp);
		}
		long answer = n - f(n, p, 0, 0, 1);
		writer.append(Long.toString(answer)).flush();
	}

	public static long f(long n, ArrayList<Long> p, int start, int cnt, long acc) {
		long retval = 0;
		if (cnt > 0) {
			if (cnt % 2 == 1) {
				retval += n / acc;
			} else {
				retval -= n / acc;
			}
		}

		for (int i = start; i < p.size(); ++i) {
			retval += f(n, p, i + 1, cnt + 1, acc * p.get(i));
		}

		return retval;
	}
}
