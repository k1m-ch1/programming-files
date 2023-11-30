/*increasingButton decreasingButton
resetButton counterLabel*/

let counter = 0;

function increment(increment_value){
  increment_value? counter += 1: counter -= 1;
  document.getElementById("counterLabel").innerHTML = counter;
}

function increment_true(){
  increment(true);
}

function increment_false(){
  increment(false);
}

document.getElementById("increasingButton").onclick = increment_true;
document.getElementById("decreasingButton").onclick = increment_false;

document.getElementById("resetButton").onclick = function(){
  counter = 0; 
  document.getElementById("counterLabel").innerHTML = 0;
}