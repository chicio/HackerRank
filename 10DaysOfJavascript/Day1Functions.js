//
//  Day1Function.js
//  HackerRank
//
//  Created by Fabrizio Duroni on 21/10/17.
//
//  https://www.hackerrank.com/challenges/js10-function

'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on('end', _ => {
    inputString = inputString.trim().split('\n').map(string => {
        return string.trim();
    });

    main();
});

function factorial(n) {
    if (n === 0 || n === 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

function readLine() {
    return inputString[currentLine++];
}

function main() {
    const n = +(readLine());
    console.log(factorial(n));
}