 def f(arr:List[Int]):Int = arr.filter(element => element % 2 != 0)
                               .fold(0)((sum, element) => sum + element)
