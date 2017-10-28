//
//  Day4CountObjects.js
//  HackerRank
//
//  Created by Fabrizio Duroni on 28/10/17.
//
//  https://www.hackerrank.com/challenges/js10-count-objects

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

function getCount(objects) {
    let count = 0;
    for (let current of objects) {
        if (current.x === current.y) {
            count++;
        }
    }
    return count;
}

function main() {
    const n = +(readLine());
    let objects = [];

    for (let i = 0; i < n; i++) {
        const [a, b] = readLine().split(' ');

        objects.push({x: +(a), y: +(b)});
    }

    console.log(getCount(objects));
}