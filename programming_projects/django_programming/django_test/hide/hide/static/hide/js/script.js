
let fromIndex = 1;
const margin = 10;

function requestContent(fromIndex, margin){
  fetch(`/request-content/?from=${fromIndex}&to=${fromIndex+margin}`)
  .then(response => response.json())
  .then(data => {
    data.post.forEach(function(post){
      let newDiv = document.createElement('div');
      newDiv.innerHTML = post+"<button id=\"hide\">Hide</button>";
      newDiv.style.display = "flex";
      newDiv.style.justifyContent = "space-between";
      newDiv.style.backgroundColor = "green";
      newDiv.style.fontSize = "64";
      newDiv.style.color = "white";
      newDiv.style.marginTop = "10";
      newDiv.style.marginBottom = "10";
      newDiv.style.padding = "10";
      newDiv.id = "post"
      document.querySelector('#content').append(newDiv);
    })
  })
}

document.addEventListener('DOMContentLoaded', function(){
  requestContent(fromIndex, margin);
  fromIndex = fromIndex +  margin;

  window.onscroll = function(){
    if (window.innerHeight + window.scrollY >= document.body.offsetHeight){
      requestContent(fromIndex, margin);
      fromIndex = fromIndex + margin;
    }
  }

  document.addEventListener('click', event => {
    target = event.target;
    if (target.id === "hide"){
      target.parentElement.style.animationPlayState = "running";
      target.parentElement.addEventListener('animationend', () => {
        target.parentElement.remove();
      })
      target.parentElement.style.animationPlayState = "running";

    }
  })

})