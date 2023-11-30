function addition(...numbers){
  let result = 0;
  for(let i in numbers){
    result += numbers[i];
  }
  return result;
}

let array = [1,2,3,4,5,6,7,8,9,10];
let output = addition(...array);
console.log(output);
