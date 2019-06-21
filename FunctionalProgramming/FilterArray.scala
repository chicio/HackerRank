def f(delim:Int,arr:List[Int]):List[Int] = {
    var x: List[Int] = List()
    arr.foreach(element => {
        if(element < delim) {
            x = x :+ element
        }
    })
    return x
}