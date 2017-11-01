//
//  Day7RegularExpressionsII.js
//  HackerRank
//
//  Created by Fabrizio Duroni on 31/10/17.
//
//  https://www.hackerrank.com/challenges/js10-regexp-2

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

function regexVar() {
    return new RegExp(/^(Mr|Mrs|Ms|Dr|Er)\.[a-zA-Z]*$/);
}

function main() {
    const re = regexVar();
    const s = readLine();
    console.log(!!s.match(re));
}