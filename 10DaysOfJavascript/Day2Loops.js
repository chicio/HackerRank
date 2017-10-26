//
//  Day2Loop.js
//  HackerRank
//
//  Created by Fabrizio Duroni on 26/10/17.
//
//  https://www.hackerrank.com/challenges/js10-loops/problem

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

function vowelsAndConsonants(s) {
    let consonants = "";
    for (let i = 0; i < s.length; i++) {
        let currentChar = s.charAt(i);
        if (currentChar === 'a' ||
            currentChar === 'e' ||
            currentChar === 'i' ||
            currentChar === 'o' ||
            currentChar === 'u') {
            console.log(currentChar);
        } else {
            consonants += currentChar;
        }
    }
    for (let i = 0; i < consonants.length; i++) {
        console.log(consonants.charAt(i))
    }
}

function main() {
    const s = readLine();
    vowelsAndConsonants(s);
}
