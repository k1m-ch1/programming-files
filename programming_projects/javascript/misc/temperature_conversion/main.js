const FARENHEIT_TO_CELCIUS = true;
const CELCIUS_TO_FARENHEIT = false;
let mode = FARENHEIT_TO_CELCIUS;
document.getElementById("temperatureFarenheit").onclick = function(){
  document.getElementById("titleProgram").innerHTML = "Celcius to Farenheit converter";
  mode = CELCIUS_TO_FARENHEIT;
}

document.getElementById("temperatureCelcius").onclick = function(){
  document.getElementById("titleProgram").innerHTML = "Farenheit to Celcius converter";
  mode = FARENHEIT_TO_CELCIUS;
}

document.getElementById("submitButton").onclick = function(){
  let result = 0;
  let inputted = document.getElementById("inputTemperature").value;
  if(inputted == ""){
    inputted = 0;
  }else{
    inputted = Number(inputted);
  }
  mode? result = ((inputted - 32)*5)/9: result = (inputted * 9)/5 + 32;
  mode? window.alert(inputted + " farenheit is equals to " + Math.round(result*100)/100 + " celcius"): window.alert(inputted + " celcius is equals to " + Math.round(result*100)/100 + " farenheit");
}