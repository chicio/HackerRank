//
//  Day6BitwiseOperators.js
//  HackerRank
//
//  Created by Fabrizio Duroni on 31/10/17.
//
//  https://www.hackerrank.com/challenges/js10-date

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

function getDayName(dateString) {
    const days = ['Sunday', 'Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday'];
    const date = new Date(dateString);
    return days[date.getDay()];
}

function main() {
    const d = +(readLine());

    for (let i = 0; i < d; i++) {
        const date = readLine();
        console.log(getDayName(date));
    }
}
