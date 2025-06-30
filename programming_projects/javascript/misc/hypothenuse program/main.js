document.getElementById("submitButton").onclick = function(){
  let height = document.getElementById("height").value;
  let base = document.getElementById("base").value;
  if(height == "" || base == ""){
    window.alert("Missing arguments, please try again.");
  }
  else{
    let resultVar = Math.sqrt(Math.pow(Number(height), 2) + Math.pow(Number(base), 2));
    window.alert(`The hypothenuse of a right triangle of Height ${height} and of Base ${base} is ${(Math.round(resultVar*100))/100}`);

  }
  // window.alert(`Your the hypothenuse of this right triangle is ${resultVar}`)
} 