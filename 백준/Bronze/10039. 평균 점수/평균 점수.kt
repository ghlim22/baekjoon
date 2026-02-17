import java.util.*

fun main() = with(Scanner(System.`in`)) {
    val arr = Array<Int>(5) {
        nextInt()
    }.map {
        if (it < 40) 40 else it
    }
    println(arr.sum() / 5)
}