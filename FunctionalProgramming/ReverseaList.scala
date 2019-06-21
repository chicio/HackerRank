def f(arr:List[Int]):List[Int] = {
    var reversedList: List[Int] = List.fill(arr.length)(0)
    arr.zipWithIndex
       .map { case (element, index) => 
           reversedList = reversedList.updated(arr.length - index - 1, element)
       }
    return reversedList
}