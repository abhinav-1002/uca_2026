function* fibonacci(){
    yield 0;
    let n1=0;
    let n2=1;
    yield 1;
    while(true){
        let n3=n1+n2;
        yield n3;
        n1=n2;
        n2=n3;
    }
}

const fibGen=fibonacci();

console.log(fibGen.next().value);
console.log(fibGen.next().value);
console.log(fibGen.next().value);
console.log(fibGen.next().value);
console.log(fibGen.next().value);
console.log(fibGen.next().value);
