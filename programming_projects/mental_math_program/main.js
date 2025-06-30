number_of_operators = ['+', '-', '*']

first_number = Math.floor(Math.random()*9 + 1)
second_number = Math.floor(Math.random()*9 + 1)
operator = number_of_operators[Math.floor(Math.random()*3)]
document.getElementById("cool").innerHTML = first_number +" "+ operator + " "+ second_number + " = ";

document.getElementById("btn").onclick = function(){
  prev_question = document.getElementById("cool").innerHTML
  prev_first_number = Number(prev_question[0])
  operator = prev_question[2]
  prev_second_number = Number(prev_question[4])
  let result
  if (operator == '+'){
    result = prev_first_number + prev_second_number;
  }
  else if (operator == '-'){
    result = prev_first_number - prev_second_number;
  }
  else{
    result = prev_second_number * prev_first_number;
  }
  answer = document.getElementById("answer_box").value
  if (result == Number(answer)){
    document.getElementById("correctanot").innerHTML = 'CORRECT! ' + prev_question + ' is equals to ' + result
  }
  else{
    document.getElementById("correctanot").innerHTML = 'WRONG! ' + prev_question + ' is equals to ' + result + ' not ' + answer
  }

  first_number = Math.floor(Math.random()*9 + 1)
  second_number = Math.floor(Math.random()*9 + 1)
  operator = number_of_operators[Math.floor(Math.random()*3)]
  document.getElementById("cool").innerHTML = first_number +" "+ operator + " "+ second_number + " = ";
  document.getElementById('answer_box').value = ""


}