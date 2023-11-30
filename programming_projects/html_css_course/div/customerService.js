let yes = false;
let no = false;

let satisfied = "You are satisfied with our service!";
let unsatisfied = "You are not satisfied with our service! :(";

function changeYes(){
  yes? yes = false: yes = true;
  console.log("Yes function says: ");
  yes? console.log(satisfied): console.log(unsatisfied);
}

function changeNo(){
  console.log("No function says: ");
  no? no = false: yes = true;
  no? console.log(unsatisfied): console.log(satisfied);
}

document.getElementById("yesButton").onclick = changeYes;
document.getElementById("noButton").onclick = changeNo;