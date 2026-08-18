class Solution {
    fun solution(message: String, spoiler_ranges: Array<IntArray>): Int {
        val spoilerRanges = BooleanArray(message.length).apply {
            spoiler_ranges.forEach { (s, e) ->
                (s..e).forEach { ind -> this[ind] = true }
            }
        }
        var cur = 0
        val words = message.split(' ').map { word ->
            val startIndex = cur
            val endIndex = startIndex + word.length - 1
            cur += word.length + 1
            word to (startIndex..endIndex)
        }
        val (spoiler, notSpoiler) = words.partition { (_, r) ->
            r.any { spoilerRanges[it] }
        }
        val swords = spoiler.map { it.first }.toSortedSet()
        val nswords = notSpoiler.map { it.first }.toSortedSet()
        val answer = (swords - nswords).size
        return answer
    }
}