document.addEventListener('DOMContentLoaded', function(){
  document.querySelector('#submit').disabled = true;
  document.querySelector('#tasks').onkeyup = function(){
    const new_task = document.querySelector('#tasks');
    document.querySelector('#submit').disabled = (new_task.value.length == 0);
  }

  document.querySelector('form').onsubmit = function(){
    const new_task = document.querySelector('#tasks');
    const new_li = document.createElement('li');
    new_li.innerHTML = new_task.value;
    document.querySelector('ul').append(new_li);
    new_task.value = "";
    return false;
  }
})