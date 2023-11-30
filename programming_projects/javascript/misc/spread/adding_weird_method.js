function add(...input){
  if(input.length <= 1){
    return input[0];
  }
  let result = input[0] + input[1];
  input = input.slice(1);
  input[0] = result;
  let return_value = add(...input);
  return return_value;
}

let print_value = add(1,2,3,4,5,6,7,8,9,10);
console.log(print_value);