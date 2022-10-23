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