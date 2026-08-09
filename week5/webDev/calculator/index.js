function* calculator(initialValue){
    let result = initialValue;

    while (true) {
        const command = yield result;

        if (!command || typeof command.value !== "number") {
            console.log("Invalid input");
            continue;
        }

        switch (command.operation) {
            case "add":
                result += command.value;
                break;

            case "subtract":
                result -= command.value;
                break;

            case "multiply":
                result *= command.value;
                break;

            case "divide":
                result /= command.value;
                break;

            default:
                console.log("Invalid operation");
        }
    }

}

const calc = calculator(50);

console.log(calc.next().value); 
console.log(calc.next({ operation: "add", value: 30 }).value); 
console.log(calc.next({ operation: "multiply", value: 2 }).value); 
console.log(calc.next({ operation: "add", value: "30" }).value); 
console.log(calc.next({ operation: "multiply", value: 0 }).value); 
