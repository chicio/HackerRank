object Solution extends App {

    def f(num:Int) : List[Int] = {
        val list = List.fill(num)(0)
        return list
    }

    println(f(readInt))
}