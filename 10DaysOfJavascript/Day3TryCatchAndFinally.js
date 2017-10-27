//
//  Day3TryCatchAndFinally.js
//  HackerRank
//
//  Created by Fabrizio Duroni on 27/10/17.
//
//  https://www.hackerrank.com/challenges/js10-try-catch-and-finally

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

function reverseString(s) {
    try {
        const splitString = s.split("");
        const reverseArray = splitString.reverse();
        const reversedString = reverseArray.join("");
        console.log(reversedString);
    } catch (exception) {
        console.log(exception.message);
        console.log(s);
    }
}

function main() {
    const s = eval(readLine());
    reverseString(s);
}