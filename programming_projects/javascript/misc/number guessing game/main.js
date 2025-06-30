// submitButton giveUpButton inputNumber
let counter = 0;
let number = Math.floor((Math.random() * 100) + 1);

document.getElementById("submitButton").onclick = function(){
  counter += 1;
  let inputted = document.getElementById("inputNumber").value;
  if(inputted == ""){
    window.alert("please input a number!");
  }
  else{
    inputted = Number(inputted);
    if(inputted < 1){
      window.alert("please input a bigger number");
    }
    else if(inputted > 100){
      window.alert("please input a smaller number");
    }
    else if(inputted == number){
      let guess;
      switch(counter){
        case 1:
          guess = "guess";
          break;
        case counter:
          guess = "guesses";
          break;
      }
      window.alert("You got the number, the number is "+ number + "\nIt took you " + counter +" " + guess);
      counter = 0;
      number = Math.floor((Math.random() * 100) + 1);
    }
    else if(inputted < number){
      window.alert("The number is bigger than " + inputted);
    }
    else if(inputted > number){
      window.alert("The number is smaller than "+ inputted);
    }
  }
}

document.getElementById("giveUpButton").onclick = function(){
  window.alert("Sadge :(\nThe number is " + number);
  number = Math.floor((Math.random() * 100) + 1);
}