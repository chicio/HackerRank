//
//  Day0HelloWorld.js
//  HackerRank
//
//  Created by Fabrizio Duroni on 21/10/17.
//
//  https://www.hackerrank.com/challenges/js10-data-types

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

function performOperation(secondInteger, secondDecimal, secondString) {
    const firstInteger = 4;
    const firstDecimal = 4.0;
    const firstString = 'HackerRank ';
    console.log(Number(firstInteger) + Number(secondInteger))
    console.log(Number(firstDecimal) + Number(secondDecimal))
    console.log(firstString + secondString)
}

function main() {
    const secondInteger = readLine();
    const secondDecimal = readLine();
    const secondString = readLine();

    performOperation(secondInteger, secondDecimal, secondString);
}