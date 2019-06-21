object Solution extends App {

  def f(n: Int) = {
      for(a <- 1 to n){
         println( "Hello World" );
      }
  }

  var n = scala.io.StdIn.readInt
  f(n)
}
