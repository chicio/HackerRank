//
//  Day3Arrays.js
//  HackerRank
//
//  Created by Fabrizio Duroni on 27/10/17.
//
//  https://www.hackerrank.com/challenges/js10-arrays/problem

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

function readLine() {
    return inputString[currentLine++];
}

function getSecondLargest(numbers) {
    let uniqueNumbers = numbers.filter(function(item, pos) {
        return numbers.indexOf(item) === pos;
    });
    let numberSorted = uniqueNumbers.sort(function (a, b) {  return a - b;  });
    return numberSorted[uniqueNumbers.length - 2];
}

function main() {
    const n = +(readLine());
    const nums = readLine().split(' ').map(Number);

    console.log(getSecondLargest(nums));
}
