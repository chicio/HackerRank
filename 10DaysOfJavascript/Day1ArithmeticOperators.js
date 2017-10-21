//
//  Day1ArithmeticOperators.js
//  HackerRank
//
//  Created by Fabrizio Duroni on 21/10/17.
//
//  https://www.hackerrank.com/challenges/js10-arithmetic-operators

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

function getArea(length, width) {
    return length * width;
}

function getPerimeter(length, width) {
    return length * 2 + width * 2;
}

function main() {
    const length = +(readLine());
    const width = +(readLine());

    console.log(getArea(length, width));
    console.log(getPerimeter(length, width));
}