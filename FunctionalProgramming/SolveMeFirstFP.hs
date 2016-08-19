{- 

SolveMeFirstFP.hs
HackerRank

Created by Fabrizio Duroni on 19/08/16.

https://www.hackerrank.com/challenges/fp-solve-me-first

-}

solveMeFirst a b = a + b

main = do
    val1 <- readLn
    val2 <- readLn
    let sum = solveMeFirst val1 val2
    print sum
