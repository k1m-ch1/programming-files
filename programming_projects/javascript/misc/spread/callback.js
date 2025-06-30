function performOperator(func, ...input){
  let result = func(...input);
  console.log(`The result is ${result}`);
  return result;
}

function add(...input){
  let return_value = 0;
  for(let i = 0, len = input.length; i < len; i+=1){
    return_value += input[i];
  }
  return return_value;
}

function substract(...input){
  let return_value = 0;
  for(let i = 0, len = input.length; i < len; i+=1){
    return_value -= input[i];
  }
  return return_value;
}

function multiply(...input){
  let return_value = 1;
  for(let i = 0, len = input.length; i < len; i+=1){
    return_value = return_value * input[i];
  }
  return return_value;
}

function divide(...input){
  let return_value = input[0] / input[1];
  for(let i = 1, len = input.length; i < len; i+=1){
    return_value = return_value / input[i];
  }
  return return_value;
}

performOperator(divide, 1000000, 10, 10, 10);