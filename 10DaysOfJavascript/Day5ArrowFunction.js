//
//  Day5ArrowFunction.js
//  HackerRank
//
//  Created by Fabrizio Duroni on 30/10/17.
//
//  https://www.hackerrank.com/challenges/js10-arrows

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

function modifyArray(nums) {
    return nums.map(function(number) {
        if (number % 2 === 0) {
            return number * 2;
        } else {
            return number * 3;
        }
    });
}

function main() {
    const n = +(readLine());
    const a = readLine().split(' ').map(Number);

    console.log(modifyArray(a).toString().split(',').join(' '));
}
