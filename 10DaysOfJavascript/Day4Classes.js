//
//  Day4Classes.js
//  HackerRank
//
//  Created by Fabrizio Duroni on 28/10/17.
//
//  https://www.hackerrank.com/challenges/js10-class

class Polygon {
    constructor(sides) {
        this.sides = sides;
    }

    perimeter() {
        return this.sides.reduce((a, b) => { return a + b }, 0);
    }
}

const rectangle = new Polygon([10, 20, 10, 20]);
const square = new Polygon([10, 10, 10, 10]);
const pentagon = new Polygon([10, 20, 30, 40, 43]);

console.log(rectangle.perimeter());
console.log(square.perimeter());
console.log(pentagon.perimeter());
