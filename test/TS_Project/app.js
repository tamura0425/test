console.log('Hello TypeScript');
console.log('Hello TypeScript');
console.log('Hello TypeScript');
console.log('Hello TypeScript');
var a = 3;
var b = "hiro";
console.log(10 + 10);
console.log(b);
var Test2 = /** @class */ (function () {
    function Test2(initName) {
        this.name = initName;
        console.log(this.name);
    }
    return Test2;
}());
new Test2("55555555");
function sum(x) {
    return x.toLocaleString() + '円';
}
console.log(sum(1000)); // "1,000円"