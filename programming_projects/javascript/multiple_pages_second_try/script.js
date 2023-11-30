function showPage(page){
  document.querySelectorAll('h1').forEach(function(h1Element){
    h1Element.style.display = 'none';
  })
    document.querySelector(`#${page}`).style.display = 'block';
}

document.addEventListener('DOMContentLoaded', function () {
  document.querySelectorAll('button').forEach(function(button){
    button.onclick = function(){
      showPage(this.dataset.page)
    }
  })
})