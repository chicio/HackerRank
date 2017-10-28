//
//  Day4CreateARectangleObject.js
//  HackerRank
//
//  Created by Fabrizio Duroni on 28/10/17.
//
//  https://www.hackerrank.com/challenges/js10-objects

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

function Rectangle(a, b) {
    return {length: a, width: b, perimeter: 2 * (a + b), area: a * b};
}

function main() {
    const a = +(readLine());
    const b = +(readLine());

    const rec = new Rectangle(a, b);

    console.log(rec.length);
    console.log(rec.width);
    console.log(rec.perimeter);
    console.log(rec.area);
}