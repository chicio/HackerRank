//
//  Day0HelloWorld.js
//  HackerRank
//
//  Created by Fabrizio Duroni on 21/10/17.
//
//  https://www.hackerrank.com/challenges/js10-hello-world

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

function greeting(parameterVariable) {
    console.log('Hello, World!');
    console.log(parameterVariable)
}

function main() {
    const parameterVariable = readLine();
    greeting(parameterVariable);
}