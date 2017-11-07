//
//  Day8CreateaButton.js
//  HackerRank
//
//  Created by Fabrizio Duroni on 01/11/17.
//
//  https://www.hackerrank.com/challenges/js10-create-a-button

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
    return new RegExp(/\d+/);
}

function main() {
    const re = regexVar();
    const s = readLine();
    console.log(!!s.match(re));
}