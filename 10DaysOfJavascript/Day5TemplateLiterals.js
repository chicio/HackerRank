//
//  Day5TemplateLiterals.js
//  HackerRank
//
//  Created by Fabrizio Duroni on 28/10/17.
//
//  https://www.hackerrank.com/challenges/js10-template-literals

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

function sides(literals, ...expressions) {
    const area = expressions[0];
    const perimeter = expressions[1];
    const s1 = (perimeter + Math.sqrt(Math.pow(perimeter, 2) - (16 * area))) / 4;
    const s2 = (perimeter - Math.sqrt(Math.pow(perimeter, 2) - (16 * area))) / 4;
    return [s1, s2].sort();
}

function main() {
    let s1 = +(readLine());
    let s2 = +(readLine());

    [s1, s2] = [s1, s2].sort();

    const [x, y] = sides`The area is: ${s1 * s2}.\nThe perimeter is: ${2 * (s1 + s2)}.`;

    console.log((s1 === x) ? s1 : -1);
    console.log((s2 === y) ? s2 : -1);
}
