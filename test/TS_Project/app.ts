console.log('Hello TypeScript');
console.log('Hello TypeScript');
console.log('Hello TypeScript');
console.log('Hello TypeScript');

const a: number = 3;

const b: string = "hiro";

console.log(10+10);
console.log(b);


class Test2{
    name: string;
    constructor(initName: string){
        this.name = initName;
        console.log(this.name);
    }
}
new Test2("55555555");

function sum(x: number): string {
    return x.toLocaleString() + '円';
}

console.log(sum(1000)); // "1,000円"

console.log('Hello TypeScript');

const flag = false;
const text = flag ? "flagはtrueです" : "flagはfalseです";
console.log(text);


class Person{
    name:string;
    constructor(initName: string){
        this.name = initName;
    }
}
const quill = new Person('quill');

console.log(quill);


function increment(num) {
    return num + 1;
}
console.log(increment(999));

