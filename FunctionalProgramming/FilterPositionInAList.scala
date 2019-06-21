def f(arr:List[Int]):List[Int] = {
    return arr
            .zipWithIndex
            .filter(elementWithIndex => elementWithIndex._2 % 2 != 0)
            .map(elementWithIndex => elementWithIndex._1) 
}