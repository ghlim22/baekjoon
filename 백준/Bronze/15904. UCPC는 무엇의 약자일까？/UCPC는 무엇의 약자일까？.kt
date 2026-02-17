import java.util.*

fun main() = with(Scanner(System.`in`)) {
    val line = nextLine()
    var i = 0
    for (c in line) {
        when (i) {
            0 -> if (c == 'U') i++
            1, 3 -> if (c == 'C') i++
            2 -> if (c == 'P') i++
        }
    }
    
    if (i == 4)
        println("I love UCPC")
    else
        println("I hate UCPC")
}