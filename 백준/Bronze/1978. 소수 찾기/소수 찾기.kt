import java.util.*

fun main() = with(Scanner(System.`in`)) {
    val N = 1000
    val primes = mutableListOf<Int>()
    val spf = Array<Int>(N + 1) { 0 }
    for (i in 2..N) {
        if (spf[i] == 0) {
            primes.add(i)
            spf[i] = i
        }
        for (p in primes) {
            val x = p * i
            if (x > N) 
                break
            spf[x] = p
            if (i % p == 0)
                break
        }
    }

    var cnt = 0
    repeat (nextInt()) {
        val n = nextInt()
        if (spf[n] == n) {
            cnt++
        }
    }
    println(cnt)
}